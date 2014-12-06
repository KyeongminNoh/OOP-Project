#pragma once
#include "GameWindow.h"
#include "StartScene.h"
#include "qwidget.h"
#include "BuildWhat.h"
#include "ManageGame.h"
#include "Map.h"
#include "Semester.h"
#include "LoadScene.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>



class FieldScene : public QWidget
{
	Q_OBJECT

public:
	FieldScene() {}
	FieldScene(GameWindow* win, int isMan, int isDayPerson, struct data S);
	~FieldScene(){}

public slots:
		

private:
	GameWindow* window;
	QWidget* Page;
	QLabel* Title;
	QLabel* SideBar;
	QLabel* Footer;
	Map* maP;
	BuildWhat *MenuBar;
	ManageGame *onGoingGame;
};