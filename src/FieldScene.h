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
#include <QMediaPlayer>
#include <QMediaPlaylist>



class FieldScene : public QWidget
{
	Q_OBJECT

public:
	FieldScene() {}
	FieldScene(GameWindow* win, int isMan, int isDayPerson, struct data S);
	~FieldScene(){}

	void ReturnStart();
	void ExitGame();
public slots:
		

private:
	QMediaPlayer* _bgm;
	QMediaPlaylist* Playlist;
	GameWindow* window;
	QWidget* Page;
	QLabel* Title;
	QLabel* SideBar;
	QLabel* Footer;
	Map* maP;
	BuildWhat *MenuBar;
	ManageGame *onGoingGame;
};