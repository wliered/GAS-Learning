// Wliered did a thing

#pragma once

#include "CoreMinimal.h"
#include "WarriorEnumTypes.h"

class FWarriorCountdownAction : public FPendingLatentAction
{
public:
	FWarriorCountdownAction(float InTotalCountdownTime, float InUpdateInterval, float& InOutRemainingTime, EWarriorCountDownActionOutput& InCountdownOutput, const FLatentActionInfo& LatentActionInfo)
		: bNeedToCancel(false),
		TotalCountdownTime(InTotalCountdownTime),
		UpdateInterval(InUpdateInterval),
		OutRemainingTime(InOutRemainingTime),
		CountdownOutput(InCountdownOutput),
		ExecutionFunction(LatentActionInfo.ExecutionFunction),
		OutputLink(LatentActionInfo.Linkage),
		CallbackTarget(LatentActionInfo.CallbackTarget),
		ElapsedInterval(0.f),
		ElapsedTimeSinceStart(0.f)
	{
		
	}

	void CancelAction();
private:
	bool bNeedToCancel;
	float TotalCountdownTime;
	float UpdateInterval;
	float& OutRemainingTime;
	EWarriorCountDownActionOutput& CountdownOutput;
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	float ElapsedInterval;
	float ElapsedTimeSinceStart;
	
};
