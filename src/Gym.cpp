#include "Gym.h"
#include "ManageGame.h"

Gym::Gym(ManageGame *mg){
	constructed = true;
	level = 1;
	enabled_atNight = true;
	name = "Ã¼À°°ü";
	UpgradeCost = 100;

	mg->change_DeclineHealth(0.1);
};

void Gym::Upgrade(ManageGame *mg){
	level++;
	UpgradeCost += 100;
	mg->change_DeclineHealth(0.2);
};

void Gym::Upgrade2(ManageGame *mg){
	level++;
	UpgradeCost += 100;
	mg->change_DeclineHealth(0.2);
};