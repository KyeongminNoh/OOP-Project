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

class GradeTable;

struct data{
	int isDayPerson,isMan,isSemester;
//		int BuildingLevel[9];
	int Friend_num[6];
	int Max_Heal;
	int grade[9];
	int File;
};
class LoadScene : public QWidget
{
	Q_OBJECT

public:
	LoadScene() {}
	LoadScene(GameWindow* win);
	~LoadScene(){}

	public slots:
		void showClicked();
		void BackClicked2();
		void NextClicked();
		void BackClicked();
		void DataView1();
		void DataView2();
		void DataView3();
		void DataView4();
private:
	void paintEvent(QPaintEvent*);
	GameWindow* window;
	QWidget* Page;
	QLabel* Head;
	QLabel* Title;
	QLabel *Person;
	QLabel* Night;
	QLabel* Session1;
	QLabel *grade;
	QPushButton *backButton2;
	QFont* font;

	GradeTable *gradetable;
	struct data s[5];
	int FileCheck;
};
