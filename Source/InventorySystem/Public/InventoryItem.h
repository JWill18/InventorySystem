// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ItemActor.h"
#include "CoreMinimal.h"
#include "InventoryItem.generated.h"

/**
 * A struct to store ItemActor information into the Inventory
 */
USTRUCT(BlueprintType)
struct FInventoryItem
{
	GENERATED_BODY()

public:
	// Store ItemActor Properties
	UPROPERTY(BlueprintReadOnly, Category = "Inventory Item")
	TSubclassOf<AItemActor> ClassType;

	// Display Name of the ItemActor
	UPROPERTY(BlueprintReadOnly, Category = "Inventory Item")
	FString DisplayName;

	// Item Type of the ItemActor
	UPROPERTY(BlueprintReadOnly, Category="Inventory Item")
	EItemTypes ItemType;

	// Quantity of the ItemActor
	UPROPERTY(BlueprintReadWrite, Category="Inventory Item")
	int Quantity = -1;

	// Useability of the ItemActor
	UPROPERTY(BlueprintReadOnly, Category = "Inventory Item")
	bool IsUseable;
};
