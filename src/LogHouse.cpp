#include "LogHouse.h"
#include "ManageGame.h"

LogHouse::LogHouse(ManageGame *mg){
	constructed = true;
	level = 1;
	enabled_atNight = true;
	name = "�볪����";
	UpgradeCost = 100;
	mg->change_InclineLonely(0.05);
};

void LogHouse::Upgrade(ManageGame *mg){
	level++;
	UpgradeCost += 100;
	mg->change_InclineLonely(0.05);
};

void LogHouse::Upgrade2(ManageGame *mg){
	level++;
	UpgradeCost += 100;
	mg->change_InclineLonely(0.1);
};