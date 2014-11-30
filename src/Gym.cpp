#include "Gym.h"
#include "ManageGame.h"

Gym::Gym(ManageGame *mg){
	constructed = true;
	level = 1;
	enabled_atNight = true;
	name = "Ã¼À°°ü";
	UpgradeCost = 50;

	mg->change_DeclineHealth(0.05);
};

void Gym::Upgrade(ManageGame *mg){
	level++;
	UpgradeCost += 50;
	mg->change_DeclineHealth(0.05);
};

void Gym::Upgrade2(ManageGame *mg){
	level++;
	mg->change_DeclineHealth(0.15);
};