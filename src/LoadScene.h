#pragma once
#include "GameWindow.h"
#include "StartScene.h"
#include "qwidget.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

class LoadScene : public QWidget
{
	Q_OBJECT

public:
	LoadScene() {}
	LoadScene(GameWindow* win);
	~LoadScene(){}

	public slots:
		void NextClicked();
		void DataView1();
		void DataView2();
		void DataView3();
		void DataView4();
private:
	GameWindow* window;
	QWidget* Page;
	QLabel* Head;
	QLabel* Title;
	QLabel *Person;
	QLabel* Night;
	QLabel* Session1;
	int FileCheck;
	int isDayPerson[5],isMan[5],isSemester[5];
	int BuildingLevel[5][9];
	int Friend_num[5][6];
	int Max_Heal[5],Knowl[5];
	int grade[5][9];
};
