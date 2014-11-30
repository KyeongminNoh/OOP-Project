#include <QString>

class ManageGame;

#ifndef BUILDING_H
#define BUILDING_H
class Building
{
public:
	Building(){};
	Building(ManageGame *mg);

	int get_UpgradeCost(){return UpgradeCost;}
	int get_level(){ return level;}
	virtual void Upgrade(ManageGame *mg) = 0; // level++, upgrade_cost º¯°æ
	virtual void Upgrade2(ManageGame *mg) = 0;



protected:
	int level;
	int ConstructCost;
	int UpgradeCost;
	bool constructed;
	bool enabled_atNight;
	QString name;
//	int position;
};

#endif
