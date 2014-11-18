#include "Building.h"

class StudentHall : public Building{
public:
	StudentHall(ManageGame *mg);
	virtual void Upgrade(ManageGame *mg);
	virtual void Upgrade2(ManageGame *mg);
private:
};