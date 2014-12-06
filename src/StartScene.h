#pragma once
#include "GameWindow.h"
#include "qwidget.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>


enum MouseFunction { MOUSE_MOVE, MOUSE_CLICK, MOUSE_DOWN, MOUSE_DRAG, MOUSE_UP };
enum { CLICK_MOUSE_MOVE_RANGE = 6 };

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

protected:


private:

	QLabel *Head;
	
	QLabel *alertButton1;
	GameWindow* window;
	QWidget* Page;
	QLabel* Title;
};