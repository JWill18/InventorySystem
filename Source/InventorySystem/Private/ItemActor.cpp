// Fill out your copyright notice in the Description page of Project Settings.


#include "..\Public\ItemActor.h"

// Sets default values
AItemActor::AItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
	ItemMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void AItemActor::HighlightItem(bool highlight)
{
	// Set the post process setting that will add a highlight around the object
	ItemMesh->SetRenderCustomDepth(highlight);
}

void AItemActor::Use()
{
	// Check to make sure to not use an unusable item or if the item is no more.
	if (!IsUseable || Quantity <= 0)
		return;

	// Reduce item quantity
	Quantity--;

	// Use custom logic for item
	CustomInventoryUse();
}

// Called when the game starts or when spawned
void AItemActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItemActor::CustomInventoryUse_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("The ExecuteUse must be overriden to allow for custom implementation"));
}

// Called every frame
void AItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

