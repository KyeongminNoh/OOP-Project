#include "GameWindow.h"
#include "StartScene.h"

GameWindow::GameWindow()
{
	w=800;
	h=600;

	resize(w,h);
	setMinimumSize(w,h);
	setMaximumSize(w,h);

	StartScene* startscene = new StartScene(this);

	this->show();
}