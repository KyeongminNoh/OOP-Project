#pragma once
#include "GameWindow.h"
#include "FieldScene.h"
#include "qwidget.h"
#include "Building.h"
#include "AskAlert.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

class InGym : public QWidget
{
	Q_OBJECT

public:
	InGym() {}
	InGym(GameWindow* win, ManageGame* preGame, FieldScene* preScene);
	~InGym(){}

public slots:

private:
	GameWindow* window;
	QWidget* Page;
	QLabel* Title;
	QLabel* buildname;
	QLabel* exerEff;
	Map* maP;
	FieldScene* preScene;
	BuildWhat *MenuBar;
//	ManageGame *onGoingGame;
};