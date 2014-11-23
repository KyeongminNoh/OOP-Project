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
    image.load(QString::fromUtf8("Resources/backscreen.jpg"));
    Title->setPixmap(image);

	window->setCentralWidget(Title);

	setMouseTracking(true);

	QIcon NewGame;
	NewGame.addPixmap(QPixmap(QString::fromUtf8("Resources/NewGame.png")), QIcon::Normal, QIcon::Off);
	QIcon Continue;
	Continue.addPixmap(QPixmap(QString::fromUtf8("Resources/Continue.png")), QIcon::Normal, QIcon::Off);
	QIcon Exit;
	Exit.addPixmap(QPixmap(QString::fromUtf8("Resources/Exit.png")), QIcon::Normal, QIcon::Off);

	alertButton1 = new QLabel(Title);
	alertButton1->setGeometry(QRect( 0, 0, 200, 200 ));
	alertButton1->setText("Go");
	alertButton1->show();

	QPushButton *pushButton;
	pushButton = new QPushButton(Title);
    pushButton->setGeometry(QRect(125, 350, 75, 25));
	pushButton->setIcon(NewGame);
	pushButton->setIconSize(QSize(100, 50));
	pushButton->show();

	QObject::connect(pushButton,SIGNAL(clicked()),this,SLOT(RunNewGame()));
	
	QPushButton *pushButton2;
	pushButton2 = new QPushButton(Title);
    pushButton2->setGeometry(QRect(125, 400, 75, 25));
	pushButton2->setIcon(Continue);
	pushButton2->setIconSize(QSize(100, 50));
	pushButton2->show();
	
	QObject::connect(pushButton2,SIGNAL(clicked()),this,SLOT(RunContinue()));
	
	QPushButton *pushButton3;
	pushButton3 = new QPushButton(Title);
    pushButton3->setGeometry(QRect(125, 450, 75, 25));
	pushButton3->setIcon(Exit);
	pushButton3->setIconSize(QSize(100, 50));
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
