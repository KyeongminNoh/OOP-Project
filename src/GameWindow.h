#pragma once
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

class GameWindow : public QMainWindow
{
	Q_OBJECT

public:
	GameWindow();
	~GameWindow(){}

	public slots:

private:
	int w;
	int h;
};