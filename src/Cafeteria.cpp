#include "Cafeteria.h"
#include "ManageGame.h"

Cafeteria::Cafeteria(ManageGame *mg){
	constructed = true;
	level = 1;
	enabled_atNight = true;
	name = "ü����";
	UpgradeCost = 50;
};


void Cafeteria::Upgrade(ManageGame *mg){
	level++;
	UpgradeCost += 50;
};

void Cafeteria::Upgrade2(ManageGame *mg){
	level++;
};