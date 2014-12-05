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
private:
	GameWindow* window;
	QWidget* Page;
	QLabel* Head;
	QLabel* Title;
};
