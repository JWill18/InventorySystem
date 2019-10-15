# InventorySystem
An inventory system created in C++ and implemented through Blueprints in UE4 4.22

# Setup
To be able to open the project and run it, please install version 4.22 from the Epic Game Launcher.
Also download the following:
[Windows 10 sdk](https://go.microsoft.com/fwlink/p/?)
[Windows 8.1 sdk](https://go.microsoft.com/fwlink/p/?LinkId=323507)
[Visual Studio 2019](https://visualstudio.microsoft.com/vs/)

## Visual Studio Setup
For Visual Studio, install the following features
Desktop development with C++
Game Development C++

## Compiling Project
Once everything is installed, right click on the InventorySystem.uproject file and 'Generate Visual Studio project files' to create the .sln file
Opening the .sln or .uproject file will allow you to compile

# Source Files
All of the inventory system is setup in the C++ directory of '/Source/InventorySystem/'

Files:
Inventory.h
Inventory.cpp
InventoryItem.h
InventoryItem.cpp
InventoryFactory.h
InventoryFactory.cpp
ItemActor.h
ItemActor.cpp

# Example
Open the InventoryExample level and click play in the UE4 Editor.
Walk up to one of the objects on the table and press 'E' when you get close to one to put it in your inventory.
Once an item is in your inventory, press 'Tab' to open your inventory.
From here you can click items and choose to use or drop the items.