#include "StartScene.h"
#include "GameWindow.h"
#include "CreateScene.h"
#include "LoadScene.h"
#include <QMouseEvent>

StartScene::StartScene(GameWindow* win)
{
	window = win;


	Page = new QWidget(window);
	Page->resize(800,600);

	Title = new QLabel();
	Title->setScaledContents(true);
	Title->setGeometry(QRect(0,0,800,600));
    QPixmap image;
    image.load(QString::fromUtf8("Resources/backscreen.png"));
    Title->setPixmap(image);

	window->setCentralWidget(Title);

	setMouseTracking(true);

	Head = new QLabel(Title);
	Head->setScaledContents(true);
	Head->setGeometry(QRect(175,25,450,220));
    QPixmap Himage;
    Himage.load(QString::fromUtf8("Resources/Title.png"));
    Head->setPixmap(Himage);
	Head->show();

	QIcon NewGame;
	NewGame.addPixmap(QPixmap(QString::fromUtf8("Resources/NewGame.png")), QIcon::Normal, QIcon::Off);
	QIcon Continue;
	Continue.addPixmap(QPixmap(QString::fromUtf8("Resources/Continue.png")), QIcon::Normal, QIcon::Off);
	QIcon Exit;
	Exit.addPixmap(QPixmap(QString::fromUtf8("Resources/Exit.png")), QIcon::Normal, QIcon::Off);


	QPushButton *pushButton;
	pushButton = new QPushButton(Title);
    pushButton->setGeometry(QRect(300, 360, 200, 60));
	pushButton->setIcon(NewGame);
	pushButton->setIconSize(QSize(200, 60));
	pushButton->setFlat(true);
	pushButton->show();

	QObject::connect(pushButton,SIGNAL(clicked()),this,SLOT(RunNewGame()));
	
	QPushButton *pushButton2;
	pushButton2 = new QPushButton(Title);
    pushButton2->setGeometry(QRect(300, 440, 200, 60));
	pushButton2->setIcon(Continue);
	pushButton2->setIconSize(QSize(200, 60));
	pushButton2->setFlat(true);
	pushButton2->show();
	
	QObject::connect(pushButton2,SIGNAL(clicked()),this,SLOT(RunContinue()));
	
	QPushButton *pushButton3;
	pushButton3 = new QPushButton(Title);
    pushButton3->setGeometry(QRect(300, 520, 200, 60));
	pushButton3->setIcon(Exit);
	pushButton3->setIconSize(QSize(200, 60));
	pushButton3->setFlat(true);
	pushButton3->show();

	QObject::connect(pushButton3,SIGNAL(clicked()),this,SLOT(RunExit()));

	Title->show();
}
void StartScene::RunNewGame()
{
	CreateScene* createscene = new CreateScene(window);
	delete Title;
	delete Page;
	delete this;
}
void StartScene::RunContinue()
{
	LoadScene* loadscene = new LoadScene(window);
	delete Title;
	delete Page;
	delete this;
}
void StartScene::RunExit()
{
	window->close();
}
