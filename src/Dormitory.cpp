#include "Dormitory.h"
#include "ManageGame.h"
#include "Player.h"

Dormitory::Dormitory(ManageGame *mg){
	constructed = true;
	level = 0;
	enabled_atNight = true;
	name = "Ã¼À°°ü";


};

void Dormitory::Upgrade(ManageGame *mg){
	level++;
	mg->get_onPlayer()->set_Health(20);
};

void Dormitory::Upgrade2(ManageGame *mg){
	level++;
};