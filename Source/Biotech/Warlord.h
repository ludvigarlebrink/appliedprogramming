// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Warlord.generated.h"

class AWarrior;
class AWarriorAttachment;
class UCapsuleComponent;
class USceneComponent;

UCLASS()
class BIOTECH_API AWarlord : public ACharacter
{
	GENERATED_BODY()

public:

	AWarlord();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	AWarriorAttachment* JoinArmy(AWarrior* Warrior);

protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ExpandArmy();

	UFUNCTION(BlueprintCallable)
	void UpdateArmyAttachments();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Army")
	int32 ArmyHalfWidth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Army")
	int32 ArmyHeight;

protected:

	UPROPERTY(BlueprintReadWrite)
	TArray<AWarrior*> Army;

	UPROPERTY(BlueprintReadWrite)
	TArray<AWarriorAttachment*> ArmyAttachments;
};
