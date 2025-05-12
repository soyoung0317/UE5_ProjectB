// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Mover.h"
#include "KeyTrigger.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UKeyTrigger : public UBoxComponent
{
	GENERATED_BODY()
	
public:	
	UKeyTrigger();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetMover(UMover* NewMover);

private:
	UPROPERTY(EditAnywhere)
	FName AcceptableActorTag = "UnlockKey";

	UMover* Mover;
	AActor* GetAcceptableActor() const;
};
