#include <string>

class Building
{
public:
	void upgrade(); // level++, upgrade_cost ����

private:
	int level;
	int upgrade_cost;
	bool constructed;
	bool enable_night;
	string name;
//	int position;
}