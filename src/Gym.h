#include "Building.h"

class Gym : public Building{
public:
	virtual void Upgrade(ManageGame *mg);
	virtual void Upgrade2(ManageGame *mg);
	Gym(ManageGame *mg);
private:

};