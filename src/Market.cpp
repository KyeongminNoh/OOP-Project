#include "Market.h"
#include "ManageGame.h"

Market::Market(ManageGame *mg){
	constructed = true;
	level = 1;
	enabled_atNight = true;
	name = "통나무집";
	UpgradeCost = 100;
	mg->change_InclineLonely(0.07);
};

void Market::Upgrade(ManageGame *mg){
	level++;
	UpgradeCost += 100;
	mg->change_InclineLonely(0.07);
};

void Market::Upgrade2(ManageGame *mg){
	level++;
	UpgradeCost += 100;
	mg->change_InclineLonely(0.1);
};