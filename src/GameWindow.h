#pragma once
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class StartScene;
class FieldScene;
class LoadScene;
class CreateScene;

class GameWindow : public QMainWindow
{
	Q_OBJECT

public:
	GameWindow();
	~GameWindow(){}
	StartScene *Startscene;
	FieldScene *Fieldscene;
	LoadScene *Loadscene;
	CreateScene *Createscene;
	public slots:

private:
	
	int w;
	int h;
};