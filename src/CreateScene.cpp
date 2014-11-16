#include "CreateScene.h"
#include "StartScene.h"


CreateScene::CreateScene(GameWindow* win)
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

	QIcon ManMenu;
	ManMenu.addPixmap(QPixmap(QString::fromUtf8("Resources/ManMenu.png")), QIcon::Normal, QIcon::Off);
	QIcon GirlMenu;
	GirlMenu.addPixmap(QPixmap(QString::fromUtf8("Resources/GirlMenu.png")), QIcon::Normal, QIcon::Off);
	QIcon DayMenu;
	DayMenu.addPixmap(QPixmap(QString::fromUtf8("Resources/DayMenu.png")), QIcon::Normal, QIcon::Off);
	QIcon NightMenu;
	NightMenu.addPixmap(QPixmap(QString::fromUtf8("Resources/NightMenu.png")), QIcon::Normal, QIcon::Off);

	QPushButton *manButton;
	manButton = new QPushButton(Title);
    manButton->setGeometry(QRect(125, 250, 100, 100));
	manButton->setIcon(ManMenu);
	manButton->setIconSize(QSize(100, 100));
	manButton->show();

	QPushButton *girlButton;
	girlButton = new QPushButton(Title);
    girlButton->setGeometry(QRect(275, 250, 100, 100));
	girlButton->setIcon(GirlMenu);
	girlButton->setIconSize(QSize(100, 100));
	girlButton->show();

	QPushButton *dayButton;
	dayButton = new QPushButton(Title);
    dayButton->setGeometry(QRect(125, 400, 100, 100));
	dayButton->setIcon(DayMenu);
	dayButton->setIconSize(QSize(100, 100));
	dayButton->show();

	QPushButton *nightButton;
	nightButton = new QPushButton(Title);
    nightButton->setGeometry(QRect(275, 400, 100, 100));
	nightButton->setIcon(NightMenu);
	nightButton->setIconSize(QSize(100, 100));
	nightButton->show();

	QObject::connect(manButton,SIGNAL(clicked()),this,SLOT(Mancome()));
	QObject::connect(girlButton,SIGNAL(clicked()),this,SLOT(Girlcome()));

	QObject::connect(dayButton,SIGNAL(clicked()),this,SLOT(Dayclicked()));
	QObject::connect(nightButton,SIGNAL(clicked()),this,SLOT(Nightclicked()));

	Title->show();
}
void CreateScene::Mancome()
{

	Person = new QLabel(Title);
	Person->setScaledContents(true);
	Person->setGeometry(QRect(425,250,250,250));
	QPixmap Iperson;
    Iperson.load(QString::fromUtf8("Resources/Man.jpg"));
    Person->setPixmap(Iperson);

	Person->show();

}
void CreateScene::Girlcome()
{

	Person = new QLabel(Title);
	Person->setScaledContents(true);
	Person->setGeometry(QRect(425,250,250,250));
	QPixmap Iperson;
    Iperson.load(QString::fromUtf8("Resources/Girl.jpg"));
    Person->setPixmap(Iperson);

	Person->show();
}
void CreateScene::Dayclicked()
{

	Night = new QLabel(Title);
	Night->setScaledContents(true);
	Night->setGeometry(QRect(425,200,50,50));
	QPixmap weather;
    weather.load(QString::fromUtf8("Resources/Day.jpg"));
    Night->setPixmap(weather);

	Night->show();
}
void CreateScene::Nightclicked()
{

	Night = new QLabel(Title);
	Night->setScaledContents(true);
	Night->setGeometry(QRect(425,200,50,50));
	QPixmap weather;
    weather.load(QString::fromUtf8("Resources/Night.jpg"));
    Night->setPixmap(weather);

	Night->show();
}

