// Wliered did a thing


#include "WarriorHeroLinkedAnimLayer.h"

#include "WarriorHeroAnimInstance.h"

UWarriorHeroAnimInstance* UWarriorHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UWarriorHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
