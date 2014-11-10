#include <string>

class Building
{
public:
	void Upgrade(); // level++, upgrade_cost º¯°æ

private:
	int level;
	int UpgradeCost;
	bool constructed;
	bool enabled_atNight;
	string name;
//	int position;
}
