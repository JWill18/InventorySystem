// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InventoryItem.h"
#include "Engine/World.h"
#include "CoreMinimal.h"

/**
 * A static factory that is used to convert between AItemActor and FInventoryItem
 */
static class INVENTORYSYSTEM_API InventoryItemFactory
{
public:
	// Convert AItemActor to FInventoryItem
	static FInventoryItem ConvertToStruct(AItemActor* actor);

	// Convert FInventoryItem to AItemActor
	static AItemActor* ConvertToActor(UObject* worldContextObject, FInventoryItem item, FTransform transform);
};
