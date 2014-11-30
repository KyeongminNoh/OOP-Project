#include "LogHouse.h"
#include "ManageGame.h"

LogHouse::LogHouse(ManageGame *mg){
	constructed = true;
	level = 1;
	enabled_atNight = true;
	name = "통나무집";
	UpgradeCost = 50;
	mg->change_InclineLonely(0.03);
};

void LogHouse::Upgrade(ManageGame *mg){
	level++;
	UpgradeCost += 50;
	mg->change_InclineLonely(0.02);
};

void LogHouse::Upgrade2(ManageGame *mg){
	level++;
	mg->change_InclineLonely(0.05);
};