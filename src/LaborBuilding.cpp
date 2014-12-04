#include "LaborBuilding.h"
#include "ManageGame.h"

LaborBuilding::LaborBuilding(ManageGame *mg){
	ConstructCost = 500;
	constructed = true;
	level = 1;
	enabled_atNight = true;
	name = "Ã¼À°°ü";
	UpgradeCost = 50;

	mg->change_InclineFinance(0.05);
};

void LaborBuilding::Upgrade(ManageGame *mg){
	level++;
	UpgradeCost += 50;
	mg->change_InclineFinance(0.05);
};

void LaborBuilding::Upgrade2(ManageGame *mg){
	level++;
	mg->change_InclineFinance(0.1);
};