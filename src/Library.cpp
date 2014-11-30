#include "Library.h"
#include "ManageGame.h"
#include "Player.h"


Library::Library(ManageGame *mg){
	constructed = true;
	level = 1;
	enabled_atNight = true;
	name = "µµ¼­°ü";
	UpgradeCost = 50;

	mg->get_onPlayer()->set_Knowledge(5);

};

void Library::Upgrade(ManageGame *mg){
	level++;
	UpgradeCost += 50;
	mg->get_onPlayer()->set_Knowledge(10);
};

void Library::Upgrade2(ManageGame *mg){
	level++;
	mg->get_onPlayer()->set_Knowledge(15);
};

