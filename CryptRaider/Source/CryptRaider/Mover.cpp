// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// 컴포넌트 소유주 가져오기
	AActor* Owner = GetOwner();
	FString Name = Owner->GetName();
	FString CurrentLocation = (Owner->GetActorLocation()).ToCompactString();

	UE_LOG(LogTemp, Display, TEXT("Owner Address : %s"), *(Name));
	UE_LOG(LogTemp, Display, TEXT("Owner Location : %s"), *(CurrentLocation));
}

