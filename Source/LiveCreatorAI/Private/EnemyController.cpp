// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"


AEnemyController::AEnemyController()
{
	EnemyBehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Tree Component"));
	EnemyBlackboard = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard Component"));

	EnemyPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AI Perception Component"));

}

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(EnemyBehaviorTree.Get()))
	{
		RunBehaviorTree(EnemyBehaviorTree.Get());
		EnemyBehaviorTreeComponent->StartTree(*EnemyBehaviorTree.Get());

	}
}

void AEnemyController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (IsValid(EnemyBlackboard.Get()) && IsValid(EnemyBehaviorTree.Get()))
	{
		EnemyBlackboard->InitializeBlackboard((*EnemyBehaviorTree.Get()->BlackboardAsset.Get()));
	}
}
