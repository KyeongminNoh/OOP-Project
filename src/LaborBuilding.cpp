#include "LaborBuilding.h"
#include "ManageGame.h"

LaborBuilding::LaborBuilding(ManageGame *mg){
	ConstructCost = 500;
	constructed = true;
	level = 1;
	enabled_atNight = true;
	name = "Ã¼À°°ü";
	UpgradeCost = 100;

	mg->change_DeclineHealth(-0.15);
};

void LaborBuilding::Upgrade(ManageGame *mg){
	level++;
	UpgradeCost += 100;
	mg->change_DeclineHealth(0.05);
};

void LaborBuilding::Upgrade2(ManageGame *mg){
	level++;
	UpgradeCost += 100;
	mg->change_DeclineHealth(0.05);
};