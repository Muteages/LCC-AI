// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"

#include "EnemyController.generated.h"

/**
 * 
 */
UCLASS()
class LIVECREATORAI_API AEnemyController : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyController();


protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
		TObjectPtr<UBehaviorTree> EnemyBehaviorTree;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
		TObjectPtr<UBehaviorTreeComponent> EnemyBehaviorTreeComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
		TObjectPtr<UBlackboardComponent> EnemyBlackboard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		TObjectPtr<UAIPerceptionComponent> EnemyPerceptionComponent;


};
