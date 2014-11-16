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
		void Mancome();
		void Girlcome();
		void Dayclicked();
		void Nightclicked();

private:
	GameWindow* window;
	QWidget* Page;
	QLabel* Title;
	QLabel* Person;
	QLabel* Night;
};
