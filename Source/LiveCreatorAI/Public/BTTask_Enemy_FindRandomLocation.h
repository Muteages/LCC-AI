// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_Enemy_FindRandomLocation.generated.h"

/**
 * 
 */
UCLASS()
class LIVECREATORAI_API UBTTask_Enemy_FindRandomLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_Enemy_FindRandomLocation();


public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual FString GetStaticDescription() const override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Search")
	float SearchRange {500.f};
};
