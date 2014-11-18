#include "Building.h"

class Market : public Building{
public:
	Market(ManageGame *mg);
	virtual void Upgrade(ManageGame *mg);
	virtual void Upgrade2(ManageGame *mg);

private:

};