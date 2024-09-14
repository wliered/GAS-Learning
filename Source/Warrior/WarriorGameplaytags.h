﻿#pragma once


#include "NativeGameplayTags.h"

namespace WarriorGameplayTags
{
	/** Input Tags **/
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequipAxe);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LightAttack_Axe);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_HeavyAttack_Axe);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Roll);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_SwitchTarget);
	
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_MustBeHeld);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_MustBeHeld_Block);
	
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Toggleable);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Toggleable_TargetLock);
	/** Input Tags **/

	/** Player Tags **/
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);
	
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip_Axe);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_HitPause);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_SuccessfulBlock);
	/** Player Tags **/

	/** Player Ability Tags **/
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Axe);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Unequip_Axe);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Light_Axe);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Heavy_Axe);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_HitPause);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Roll);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Block);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_TargetLock);
	/** Ability Tags **/

	/** Player Status Tags **/
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_JumpToFinisher);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_Rolling);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_Blocking);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_TargetLock);
	
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_SetByCaller_AttackType_Light);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_SetByCaller_AttackType_Heavy);
	/** Player Status Tags **/

	/** Enemy Tags **/
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Weapon);
	
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Ability_Melee);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Ability_Ranged);

	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Status_Strafing);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Status_UnderAttack);
	/** Enemy Tags **/

	/** Shared Tags **/
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Event_MeleeHit);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Event_HitReact);

	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_SetbyCaller_BaseDamage);
	
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Ability_HitReact);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Ability_Death);
	
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_Dead);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_HitReact_Front);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_HitReact_Left);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_HitReact_Right);
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Status_HitReact_Back);

	/** Shared Tags **/




}

