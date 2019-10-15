// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryItemFactory.h"

FInventoryItem InventoryItemFactory::ConvertToStruct(AItemActor* actor)
{
	FInventoryItem item;

	// Assign AItemActor values to FInventoryItem struct
	item.ClassType = actor->GetClass();
	item.DisplayName = actor->DisplayName;
	item.IsUseable = actor->IsUseable;
	item.ItemType = actor->ItemType;
	item.Quantity = actor->Quantity;

	return item;
}

AItemActor* InventoryItemFactory::ConvertToActor(UObject* worldContextObject, FInventoryItem item, FTransform transform)
{
	// Get current world
	UWorld* currentWorld = worldContextObject->GetWorld();

	// Spawn actor into the world
	AItemActor* actor = currentWorld->SpawnActor<AItemActor>(item.ClassType, transform);

	// Assign values from FInventoryItem struct to AItemActor object
	actor->Quantity = item.Quantity;
	actor->ItemType = item.ItemType;
	actor->IsUseable = item.IsUseable;

	// Return spawned actor
	return actor;
}
