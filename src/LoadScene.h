#pragma once
#include "GameWindow.h"
#include "StartScene.h"
#include "qwidget.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QLabel>
struct data{
	int isDayPerson,isMan,isSemester;
//		int BuildingLevel[9];
	int Friend_num[6];
	int Max_Heal;
	int grade[9];
};
class LoadScene : public QWidget
{
	Q_OBJECT

public:
	LoadScene() {}
	LoadScene(GameWindow* win);
	~LoadScene(){}

	public slots:
		void NextClicked();
		void BackClicked();
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
	struct data s[5];
	int FileCheck;
};
