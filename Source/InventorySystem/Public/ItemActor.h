// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemActor.generated.h"

/**
 * An enum to represent the type of item an AItemActor is
 */
UENUM(BlueprintType)
enum class EItemTypes : uint8 {
	WEAPON,
	ARMOR,
	CONSUMABLE
};

/**
 * An object that can be stored into the Inventory
 */
UCLASS()
class INVENTORYSYSTEM_API AItemActor : public AActor
{
	GENERATED_BODY()
	
public:	

	// Display Name for Item
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item")
	FString DisplayName;

	// Bundles similar items to prevent duplication
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	int Quantity = 1;

	// Determine what type of item this is
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item")
	EItemTypes ItemType;

	// Determines if the ExecuteUse function can be called
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item")
	bool IsUseable;

	// Adds a static mesh for highlighting the object
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ItemMesh;

	// Sets default values for this actor's properties
	AItemActor();

	// Used to highlight mesh
	UFUNCTION(BlueprintCallable, Category="Item")
	void HighlightItem(bool highlight);

	// Base call for using the item. Handles logic such as decreasing quantity and executing additional logic
	UFUNCTION(BlueprintCallable, Category="Item")
	void Use();

	// Should be overridden by derived classes if marked as useable to allow for custom implementation per class
	UFUNCTION(BlueprintNativeEvent)
	void CustomInventoryUse();

	// Allows for CustomInventoryUse to be overwritten in child blueprint classes
	virtual void CustomInventoryUse_Implementation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
