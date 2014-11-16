#pragma once
#include "GameWindow.h"
#include "qwidget.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

class StartScene : public QWidget
{
	Q_OBJECT

public:
	StartScene() {}
	StartScene(GameWindow* win);
	~StartScene(){}

	public slots:
		void RunNewGame();
		void RunContinue();
		void RunExit();

private:
	GameWindow* window;
	QWidget* Page;
	QLabel* Title;
};