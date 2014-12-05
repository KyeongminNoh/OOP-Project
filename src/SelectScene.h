#pragma once
#include "GameWindow.h"
#include "StartScene.h"
#include "LoadScene.h"
#include "qwidget.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

class SelectScene : public QWidget
{
	Q_OBJECT

public:
	SelectScene() {}
	SelectScene(GameWindow* win, int isMan, int isDayPerson);
	~SelectScene(){}

	public slots:
		void Start1();
		void Start2();
		void Start3();
		void Start4();
		void Start5();
		void Start6();
		void Start7();
		void Start8();

private:
	GameWindow* window;
	QWidget* Page;
	QLabel* Head;
	QLabel* Title;
	int Man;
	int DayPerson;
	QPushButton *Semester1Button;
	QPushButton *Semester2Button;
	QPushButton *Semester3Button;
	QPushButton *Semester4Button;
	QPushButton *Semester5Button;
	QPushButton *Semester6Button;
	QPushButton *Semester7Button;
	QPushButton *Semester8Button;
};
