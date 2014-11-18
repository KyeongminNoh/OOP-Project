#include "Building.h"

class LaborBuilding : public Building{
public:
	LaborBuilding(ManageGame *mg);
	virtual void Upgrade(ManageGame *mg);
	virtual void Upgrade2(ManageGame *mg);
private:
};