// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Enemy_FindRandomLocation.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

UBTTask_Enemy_FindRandomLocation::UBTTask_Enemy_FindRandomLocation()
{
	NodeName = TEXT("Find Random Location");

	// accept only vectors
	BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(
		UBTTask_Enemy_FindRandomLocation, BlackboardKey));
}

EBTNodeResult::Type UBTTask_Enemy_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	FNavLocation Location{};

	//get AI pawn
	AAIController* AIController{ OwnerComp.GetAIOwner()};
	const APawn* AIPawn{ AIController->GetPawn() };

	//get pawn origin
	const FVector Origin{ AIPawn->GetActorLocation() };

	// navigation system, find random location
	const UNavigationSystemV1* NavSys{ UNavigationSystemV1::GetCurrent(GetWorld()) };
	if (IsValid(NavSys) && NavSys->GetRandomPointInNavigableRadius(Origin, SearchRange, Location))
	{
		AIController->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName, Location.Location);
	}

	// Tell the behavior tree that the task finished with success
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}

FString UBTTask_Enemy_FindRandomLocation::GetStaticDescription() const
{
	return FString::Printf(TEXT("Vector: %s"), *BlackboardKey.SelectedKeyName.ToString());
}
