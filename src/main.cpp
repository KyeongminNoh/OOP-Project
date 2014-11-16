#include "start.h"
#include "GameWindow.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	GameWindow window;
	

	return a.exec();
}
void start::newstart()
{
/*	QMainWindow *window = new QMainWindow();
	window->resize(1024,768);
	window->show();

	QLabel *label = new QLabel(window);
	label->setScaledContents(true);
	label->setGeometry(QRect(0,0,window->width(),window->height()));
    QPixmap image;
    image.load(QString::fromUtf8("Resources/hehe.jpg"));
    label->setPixmap(image);
    label->show();
	*/
}