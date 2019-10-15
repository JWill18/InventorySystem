// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InventoryItemFactory.h"
#include "InventoryItem.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Inventory.generated.h"

/**
 * Holds InventoryItems and allows for spawning of items into the game world
 */
UCLASS(EditInlineNew, Blueprintable)
class INVENTORYSYSTEM_API UInventory : public UObject
{
	GENERATED_BODY()
	
public:

	// Array of items
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory Manager")
	TArray<FInventoryItem> Items;

	// Default constructor
	UInventory();

	// Adds AItemActor to array
	UFUNCTION(BlueprintCallable, Category = "Inventory Manager")
	FInventoryItem AddItem(AItemActor* actor);

	// Spawn items array for specified class. Removes the number of items spawned from array.
	UFUNCTION(BlueprintCallable, Category = "Inventory Manager", meta = (WorldContext = "worldContextObject"))
	AItemActor* SpawnItemByClass(UObject* worldContextObject, UClass* itemType, FTransform transform, int amountToSpawn = 1);

	// Spawn items array for specified index in the array. Removes the number of items spawned from array.
	UFUNCTION(BlueprintCallable, Category = "Inventory Manager", meta = (WorldContext = "WorldContextObject"))
	AItemActor* SpawnItemByIndex(UObject* worldContextObject, int index, FTransform transform, int amountToSpawn = 1);

	// Returns a sub set of items from the array based on item types
	UFUNCTION(BlueprintCallable, Category = "Inventory Manager")
	TArray<FInventoryItem> FilterByItemType(EItemTypes type);

private:

	// Spawn items from array. Removes the number of items spawned from array.
	AItemActor* SpawnItem(UObject* worldContextObject, FInventoryItem item, FTransform transform, int amountToSpawn);

	// Looks for item in array. Returns -1 if item is not found
	int IndexOfItem(FInventoryItem item);
};
