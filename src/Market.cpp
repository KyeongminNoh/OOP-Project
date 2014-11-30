#include "Market.h"
#include "ManageGame.h"

Market::Market(ManageGame *mg){
	constructed = true;
	level = 1;
	enabled_atNight = true;
	name = "통나무집";
	UpgradeCost = 60;
	mg->change_InclineLonely(0.05);
};

void Market::Upgrade(ManageGame *mg){
	level++;
	UpgradeCost += 60;
	mg->change_InclineLonely(0.04);
};

void Market::Upgrade2(ManageGame *mg){
	level++;
	mg->change_InclineLonely(0.06);
};