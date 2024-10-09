// Wliered did a thing


#include "GEExecCalc_DamageTaken.h"

#include "Warrior/WarriorDebugHelper.h"
#include "Warrior/WarriorGameplaytags.h"
#include "Warrior/GAS/AttributeSets/WarriorAttributeSet.h"

struct FWarriorDamageCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageTaken)

	FWarriorDamageCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UWarriorAttributeSet, AttackPower, Source, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UWarriorAttributeSet, DefensePower, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UWarriorAttributeSet, DamageTaken, Target, false);
	}
};
static const FWarriorDamageCapture& GetWarriorDamageCapture()
{
	static FWarriorDamageCapture WarriorDamageCapture;
	return WarriorDamageCapture;
}
UGEExecCalc_DamageTaken::UGEExecCalc_DamageTaken()
{
	// SLOW METHOD
	//FProperty* AttackPowerProperty = FindFieldChecked<FProperty>(UWarriorAttributeSet::StaticClass(),GET_MEMBER_NAME_CHECKED(UWarriorAttributeSet, AttackPower));

	//FGameplayEffectAttributeCaptureDefinition AttackPowerCaptureDefinition(AttackPowerProperty, EGameplayEffectAttributeCaptureSource::Source, false);

	//RelevantAttributesToCapture.Add(AttackPowerCaptureDefinition);

	RelevantAttributesToCapture.Add(GetWarriorDamageCapture().AttackPowerDef);
	RelevantAttributesToCapture.Add(GetWarriorDamageCapture().DefensePowerDef);
	RelevantAttributesToCapture.Add(GetWarriorDamageCapture().DamageTakenDef);
}

void UGEExecCalc_DamageTaken::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, // we have to override the Execute_Implementation instead of the Execute function, because it is a BP native function
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	// Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

	const FGameplayEffectSpec& EffectSpec = ExecutionParams.GetOwningSpec();
	//EffectSpec.GetContext().GetSourceObject();
	//EffectSpec.GetContext().GetAbility();
	//EffectSpec.GetContext().GetInstigator();
	//EffectSpec.GetContext().GetEffectCauser();
	//These are all elements that are included when we create the SpecHandle to pass into the GE
	
	FAggregatorEvaluateParameters EvaluateParameters; // this is required for the below functions, AttemptCalculateCapturedAttributeMagnitude because it holds information about the Source and TargetAttributes that may affect each other
	EvaluateParameters.SourceTags = EffectSpec.CapturedSourceTags.GetAggregatedTags(); // we need to se the tags into the created variable above for both the Source and the Target
	EvaluateParameters.TargetTags = EffectSpec.CapturedTargetTags.GetAggregatedTags();

	float SourceAttackPower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetWarriorDamageCapture().AttackPowerDef, EvaluateParameters, SourceAttackPower); //SourceAttackPower now contains the actual value of the actor's attribute, since it is an OutParam
	//Debug::Print(TEXT("SourceAttackPower"), SourceAttackPower);
	
	float BaseDamage = 0.f;
	int32 UsedLightAttackComboCount = 0;
	int32 UsedHeavyAttackComboCount = 0;

	// I'm not entirely sure where this TMap is coming from, but I think we set it in BP? does this have to do with the curve tables we set up? the GameplayEffect class has it as a variable
	for (const TPair<FGameplayTag, float>& TagMagnitude : EffectSpec.SetByCallerTagMagnitudes)
	{
		if (TagMagnitude.Key.MatchesTagExact(WarriorGameplayTags::Shared_SetbyCaller_BaseDamage))
		{
			BaseDamage = TagMagnitude.Value;
			//Debug::Print(TEXT("BaseDamage"), BaseDamage);
		}
		if (TagMagnitude.Key.MatchesTagExact(WarriorGameplayTags::Player_SetByCaller_AttackType_Light))
		{
			UsedLightAttackComboCount = TagMagnitude.Value;
			//Debug::Print(TEXT("UsedLightAttackComboCount"), UsedLightAttackComboCount);
		}
		if (TagMagnitude.Key.MatchesTagExact(WarriorGameplayTags::Player_SetByCaller_AttackType_Heavy))
		{
			UsedHeavyAttackComboCount = TagMagnitude.Value;
			//Debug::Print(TEXT("UsedHeavyAttackComboCount"), UsedHeavyAttackComboCount);

		}
	}
	
	float TargetDefensePower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetWarriorDamageCapture().DefensePowerDef, EvaluateParameters, TargetDefensePower);
	//Debug::Print(TEXT("TargetDefensePower"), TargetDefensePower);


	// once we have a hold of all the variables we will be using in our damage calculations, we can begin creating the formula to actually calculate damage
	// go through each variable and determine how it affects the BaseDamage
	if (UsedLightAttackComboCount != 0)
	{
		// each combo hit adds an extra 5% damage
		const float DamageIncreasedPercentLight = (UsedLightAttackComboCount-1) * 0.05f + 1.f;
		//Debug::Print(TEXT("DamageIncreasedPercentLight"), DamageIncreasedPercentLight);

		BaseDamage *= DamageIncreasedPercentLight;
		//Debug::Print(TEXT("ScaledBaseDamageLight"), BaseDamage);

	}
	if (UsedHeavyAttackComboCount != 0)
	{
		// each combo hit adds an extra 5% damage
		const float DamageIncreasedPercentHeavy = (UsedHeavyAttackComboCount) * 0.15f + 1.f;
		//Debug::Print(TEXT("DamageIncreasedPercentHeavy"), DamageIncreasedPercentHeavy);

		BaseDamage *= DamageIncreasedPercentHeavy;
		//Debug::Print(TEXT("ScaledBaseDamageHeavy"), BaseDamage);

	}

	// final damage calculation
	const float FinalDamageDealt = BaseDamage * SourceAttackPower / TargetDefensePower;
	//Debug::Print(TEXT("FinalDamageDealt"), FinalDamageDealt);


	// check to ensure the final damage done is greater than zero before changing the health value in Target's Attribute Set
	if (FinalDamageDealt > 0.f)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(GetWarriorDamageCapture().DamageTakenProperty, EGameplayModOp::Override, FinalDamageDealt));
	}
}
