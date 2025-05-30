// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Mover.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UMover : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMover();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetShouldMove(bool isable);
	
private:
	UPROPERTY(EditAnywhere)
	FVector OriginLocation; // 초기 위치

	UPROPERTY(EditAnywhere)
	FVector MoveOffset; // 얼마나 움직일지 

	UPROPERTY(EditAnywhere)
	float MoveTime = 4.f; // 동작하는 시간

	UPROPERTY(EditAnywhere)
	bool ShouldMove = false; // 움직일지 여부 
};
