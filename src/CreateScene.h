#pragma once
#include "GameWindow.h"
#include "StartScene.h"
#include "qwidget.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

class CreateScene : public QWidget
{
	Q_OBJECT

public:
	CreateScene() {}
	CreateScene(GameWindow* win);
	~CreateScene(){}

	public slots:
		void resetButton();
		void Mancome();
		void Girlcome();
		void Dayclicked();
		void Nightclicked();
		void NextClicked();

private:
	void MousePressEvent(QMouseEvent *event);
	QPoint Cursor;
	GameWindow* window;
	QWidget* Page;
	QLabel* Head;
	QLabel* Title;
	QLabel* Person;
	QLabel* Night;
	QPushButton *manButton;
	QPushButton *girlButton;
	QPushButton *dayButton;
	QPushButton *nightButton;
	int isMan;
	int isDayPerson;
};
