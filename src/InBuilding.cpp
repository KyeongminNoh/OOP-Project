#include "InBuillding.h"
#include "ManageGame.h"
#include "Map.h"


InBuilding::InBuilding(ManageGame *Game, QWidget *parent) : QWidget(parent){

	onGoingGame = Game;
	resize(660, 450);

}