#include "Building.h"

class Library : public Building{
public:
	Library(ManageGame *mg);
	virtual void Upgrade(ManageGame *mg);
	virtual void Upgrade2(ManageGame *mg);
private:
};