// Wliered did a thing


#include "EnemyUIComponent.h"

#include "Warrior/Widgets/WarriorWidgeBase.h"


void UEnemyUIComponent::RegisterEnemyDrawnWidget(UWarriorWidgeBase* InWidgetToRegister)
{
	EnemyDrawnWidgets.Add(InWidgetToRegister);
}

void UEnemyUIComponent::RemoveEnemyDrawnWidgetsIfAny()
{
	if (EnemyDrawnWidgets.IsEmpty())
	{
		return;
	}

	for (UWarriorWidgeBase* DrawnWidget : EnemyDrawnWidgets)
	{
		if (DrawnWidget)
		{
			DrawnWidget->RemoveFromParent();
		}
	}
	EnemyDrawnWidgets.Empty();
}
