#include "CreateScene.h"
#include "StartScene.h"
#include "FieldScene.h"
#include <QMouseEvent>
#include <QTimer>


CreateScene::CreateScene(GameWindow* win)
{
	window = win;
	setMouseTracking(true);

	Page = new QWidget(window);
	Page->resize(800,600);

	Title = new QLabel();
	Title->setScaledContents(true);
	Title->setGeometry(QRect(0,0,800,600));
    QPixmap image;
    image.load(QString::fromUtf8("Resources/White.png"));
    Title->setPixmap(image);

	

	window->setCentralWidget(Title);

	isMan = 0;
	isDayPerson = 0;

	QIcon ManMenu;
	ManMenu.addPixmap(QPixmap(QString::fromUtf8("Resources/ManMenu.png")), QIcon::Normal, QIcon::Off);
	QIcon GirlMenu;
	GirlMenu.addPixmap(QPixmap(QString::fromUtf8("Resources/GirlMenu.png")), QIcon::Normal, QIcon::Off);
	QIcon DayMenu;
	DayMenu.addPixmap(QPixmap(QString::fromUtf8("Resources/DayMenu.png")), QIcon::Normal, QIcon::Off);
	QIcon NightMenu;
	NightMenu.addPixmap(QPixmap(QString::fromUtf8("Resources/NightMenu.png")), QIcon::Normal, QIcon::Off);

	Head = new QLabel(Title);
	Head->setScaledContents(true);
	Head->setGeometry(QRect(270,45,250,80));
    QPixmap Himage;
    Himage.load(QString::fromUtf8("Resources/CreateCharacter.png"));
    Head->setPixmap(Himage);
	Head->show();


	
	manButton = new QPushButton(Title);
    manButton->setGeometry(QRect(125, 250, 100, 100));
	manButton->setIcon(ManMenu);
	manButton->setIconSize(QSize(100, 100));
	manButton->show();

	
	girlButton = new QPushButton(Title);
    girlButton->setGeometry(QRect(275, 250, 100, 100));
	girlButton->setIcon(GirlMenu);
	girlButton->setIconSize(QSize(100, 100));
	girlButton->show();

	
	dayButton = new QPushButton(Title);
    dayButton->setGeometry(QRect(125, 400, 100, 100));
	dayButton->setIcon(DayMenu);
	dayButton->setIconSize(QSize(100, 100));
	dayButton->show();

	
	nightButton = new QPushButton(Title);
    nightButton->setGeometry(QRect(275, 400, 100, 100));
	nightButton->setIcon(NightMenu);
	nightButton->setIconSize(QSize(100, 100));
	nightButton->show();

	QPushButton *nextButton;
	nextButton = new QPushButton(Title);
	nextButton->setText("Start!!");
	nextButton->resize(80,50);
	nextButton->setGeometry(QRect(650, 520, 80, 40));
	nextButton->show();


	QObject::connect(manButton,SIGNAL(clicked()),this,SLOT(Mancome()));
	QObject::connect(girlButton,SIGNAL(clicked()),this,SLOT(Girlcome()));

	QObject::connect(dayButton,SIGNAL(clicked()),this,SLOT(Dayclicked()));
	QObject::connect(nightButton,SIGNAL(clicked()),this,SLOT(Nightclicked()));

	QObject::connect(nextButton, SIGNAL(clicked()),this,SLOT(NextClicked()));

	Title->show();
}

void CreateScene::MousePressEvent(QMouseEvent *event){
	Cursor = event->pos();
}

void CreateScene::resetButton(){
	manButton->setGeometry(QRect(125, 250, 100, 100));
	girlButton->setGeometry(QRect(275, 250, 100, 100));
	dayButton->setGeometry(QRect(125, 400, 100, 100));
	nightButton->setGeometry(QRect(275, 400, 100, 100));
}

void CreateScene::Mancome()
{
	isMan = 2;
	manButton->setGeometry(QRect(128, 253, 100, 100));
	Person = new QLabel(Title);
	Person->setScaledContents(true);
	Person->setGeometry(QRect(425,250,250,250));
	QPixmap Iperson;
    Iperson.load(QString::fromUtf8("Resources/Man.png"));
    Person->setPixmap(Iperson);

	Person->show();

	QTimer::singleShot(150, this, SLOT(resetButton()));

}
void CreateScene::Girlcome()
{
	isMan = 1;
	girlButton->setGeometry(QRect(278, 253, 100, 100));
	Person = new QLabel(Title);
	Person->setScaledContents(true);
	Person->setGeometry(QRect(425,250,250,250));
	QPixmap Iperson;
    Iperson.load(QString::fromUtf8("Resources/Girl.png"));
    Person->setPixmap(Iperson);

	Person->show();

	QTimer::singleShot(150, this, SLOT(resetButton()));
}
void CreateScene::Dayclicked()
{
	isDayPerson = 2;
	dayButton->setGeometry(QRect(128, 403, 100, 100));

	Night = new QLabel(Title);
	Night->setScaledContents(true);
	Night->setGeometry(QRect(425,200,50,50));
	QPixmap weather;
    weather.load(QString::fromUtf8("Resources/Day.png"));
    Night->setPixmap(weather);

	Night->show();
	QTimer::singleShot(150, this, SLOT(resetButton()));
}
void CreateScene::Nightclicked()
{
	isDayPerson = 1;
	nightButton->setGeometry(QRect(278, 403, 100, 100));
	Night = new QLabel(Title);
	Night->setScaledContents(true);
	Night->setGeometry(QRect(425,200,50,50));
	QPixmap weather;
    weather.load(QString::fromUtf8("Resources/Night.png"));
    Night->setPixmap(weather);

	Night->show();

	QTimer::singleShot(150, this, SLOT(resetButton()));
}

void CreateScene::NextClicked()
{
	if(isMan == 0 || isDayPerson == 0){
	}
	else{
		FieldScene* fieldscene = new FieldScene(window, isMan, isDayPerson);
	}
}

