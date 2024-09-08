#pragma once

UENUM()
enum class EWarriorConfirmType : uint8
{
	Yes,
	No
};

UENUM()
enum class EWarriorValidType : uint8
{
	Valid,
	Invalid
};

UENUM(BlueprintType)
enum class EToggleDamageType : uint8
{
	CurrentEquippedWeapon,
	LeftHand,
	RightHand
};

UENUM()
enum class EWarriorSuccessType : uint8
{
	Successful,
	Failed
};
