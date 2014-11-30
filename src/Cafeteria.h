#include "Building.h"

class Cafeteria : public Building{
public:
	Cafeteria(ManageGame *mg);
	virtual void Upgrade(ManageGame *mg);
	virtual void Upgrade2(ManageGame *mg);
private:
};