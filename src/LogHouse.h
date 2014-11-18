#include "Building.h"

class LogHouse : public Building{
public:
	LogHouse(ManageGame *mg);
	virtual void Upgrade(ManageGame *mg);
	virtual void Upgrade2(ManageGame *mg);

private:

};