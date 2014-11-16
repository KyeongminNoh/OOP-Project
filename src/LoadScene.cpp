#include "LoadScene.h"
#include "StartScene.h"

LoadScene::LoadScene(GameWindow* win)
{
	window = win;

	Page = new QWidget(window);
	Page->resize(800,600);

	Title = new QLabel();
	Title->setScaledContents(true);
	Title->setGeometry(QRect(0,0,800,600));
    QPixmap image;
    image.load(QString::fromUtf8("Resources/test.jpg"));
    Title->setPixmap(image);

	window->setCentralWidget(Title);

	Title->show();
}