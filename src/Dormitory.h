#include "Building.h"

class Dormitory : public Building{
public:
	virtual void Upgrade(ManageGame *mg);
	virtual void Upgrade2(ManageGame *mg);
	Dormitory(ManageGame *mg);
private:

};