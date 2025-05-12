// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyTrigger.h"

UKeyTrigger::UKeyTrigger()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UKeyTrigger::BeginPlay()
{
	Super::BeginPlay();
    
    GetOwner()->FindComponentByClass<UBoxComponent>()->SetGenerateOverlapEvents(true);
}

void UKeyTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (Mover == nullptr)
        return;

    // AcceptableActorTag와 같은 오브젝트
    AActor* Actor = GetAcceptableActor();
    if (Actor != nullptr)
    {
        // 루트컴포넌트를 통해 물리 시뮬 비활성 + 다른 컴포넌트에 부착하여 이동하도록함
        UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
        if(Component != nullptr)
            Component->SetSimulatePhysics(false);
        
        Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
        Mover->SetShouldMove(true);
    }
    else
    {
        Mover->SetShouldMove(false);
    }

}

AActor* UKeyTrigger::GetAcceptableActor() const
{
    TArray<AActor*> Actors;
    GetOwner()->FindComponentByClass<UBoxComponent>()->GetOverlappingActors(Actors); // 현재 overlap된 모든 액터 배열에 반환
    UE_LOG(LogTemp, Warning, TEXT("Overlapping %d actor(s)."), Actors.Num());
    for (AActor* Actor : Actors)
    {
        UE_LOG(LogTemp, Display, TEXT("name : %s"), *Actor->GetName());

        if (Actor->ActorHasTag(AcceptableActorTag))
        {
            return Actor;
        }
    }

    return nullptr;
}

void UKeyTrigger::SetMover(UMover* NewMover)
{
    Mover = NewMover;
}