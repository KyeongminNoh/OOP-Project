
#include "ManageGame.h"
#include "GameWindow.h"
#include <QtWidgets/QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextCodec>
#include "BuildWhat.h"

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);

	GameWindow window; // Scene코딩용 메인
	


	return a.exec(); // 공통
}