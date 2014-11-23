#include "StudentHall.h"
#include "ManageGame.h"

StudentHall::StudentHall(ManageGame *mg){
	ConstructCost = 500;
	constructed = true;
	level = 1;
	enabled_atNight = true;
	name = "통나무집";
	UpgradeCost = 100;
	mg->change_InclineLonely(0.05);
};

void StudentHall::Upgrade(ManageGame *mg){
	level++;
	UpgradeCost += 100;
	mg->change_InclineLonely(0.05);
};

void StudentHall::Upgrade2(ManageGame *mg){
	level++;
	UpgradeCost += 100;
	mg->change_InclineLonely(0.1);
};