// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"

UInventory::UInventory()
{
	Items = TArray<FInventoryItem>();
}

FInventoryItem UInventory::AddItem(AItemActor* actor)
{
	FInventoryItem item = InventoryItemFactory::ConvertToStruct(actor);
	
	int index = IndexOfItem(item);

	// The item does not exist in the array
	if (index == -1)
	{
		index = Items.Add(item);
	}
	else
	{
		// Grab existing item from array
		FInventoryItem itemInInventory = Items[index];

		// Increase quantity amount of item
		itemInInventory.Quantity += item.Quantity;

		// Update item in array
		Items[index] = itemInInventory;
	}

	// Return new/updated item
	return Items[index];
}

AItemActor* UInventory::SpawnItemByClass(UObject* worldContextObject, UClass* itemType, FTransform transform, int amountToSpawn)
{
	FInventoryItem item;
	AItemActor* actor = nullptr;

	// For item in inventory that matches the class
	for (FInventoryItem invItem : Items)
	{
		if (invItem.ClassType == itemType)
		{
			item = invItem;
			continue;
		}
	}

	// Check to see that item has been found
	if (item.Quantity != -1)
	{
		// Spawn actor into world
		actor = SpawnItem(worldContextObject, item, transform, amountToSpawn);
	}

	// Return actor
	return actor;
}

AItemActor* UInventory::SpawnItemByIndex(UObject* worldContextObject, int index, FTransform transform, int amountToSpawn)
{
	AItemActor* actor = nullptr;

	// Check to see if item exists in array
	if (Items.IsValidIndex(index))
	{
		FInventoryItem item = Items[index];

		// Spawn actor into the world
		actor = SpawnItem(worldContextObject, item, transform, amountToSpawn);
	}
	
	// Return actor
	return actor;
}

TArray<FInventoryItem> UInventory::FilterByItemType(EItemTypes type)
{
	// Create array to hold filtered items
	TArray<FInventoryItem> filterItems = TArray<FInventoryItem>();

	// Search Inventory for items with same Item Type
	for (FInventoryItem item : Items)
	{
		if (item.ItemType == type)
			filterItems.Add(item);
	}

	// Return filtered list
	return filterItems;
}

AItemActor* UInventory::SpawnItem(UObject* worldContextObject, FInventoryItem item, FTransform transform, int amountToSpawn)
{
	AItemActor* actor = nullptr;

	// Index of item in inventory
	int index = IndexOfItem(item);

	// Verify that the item exists in the inventory
	if (index != -1)
	{
		// Convert FInventoryItem to AItemActor with factory
		actor = InventoryItemFactory::ConvertToActor(worldContextObject, item, transform);

		// Handle item's Quantity value in inventory based on how many of that object were taken out.
		if (amountToSpawn > item.Quantity)
		{
			actor->Quantity = item.Quantity;
			Items.RemoveAt(index);
		}
		else
		{
			// Decrease quantity
			actor->Quantity = amountToSpawn;
			item.Quantity -= amountToSpawn;

			// If Quantity is 0 then remove item, else update array
			if (item.Quantity <= 0)
			{
				Items.RemoveAt(index);
			}
			else
			{
				Items[index] = item;
			}
		}
	}
	// Return actor
	return actor;
}

int UInventory::IndexOfItem(FInventoryItem item)
{
	int index = -1;
	FInventoryItem invItem;

	// Loop through Items and look for item matching Display Name and Class Type
	for (int i = 0; i < Items.Num(); i++)
	{
		invItem = Items[i];

		if (invItem.ClassType == item.ClassType && invItem.DisplayName == item.DisplayName)
		{
			// Set index on found item
			index = i;
			continue;
		}
	}

	// Return index of item in Inventory
	return index;
}
