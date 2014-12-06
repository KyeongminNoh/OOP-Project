#include "LoadScene.h"
#include "FieldScene.h"
#include <QMouseEvent>
#include <QTimer>
#include "SelectScene.h"
#include "StartScene.h"

SelectScene::SelectScene(GameWindow* win, int isMan, int isDayPerson)
{
	window = win;
	setMouseTracking(true);

	Page = new QWidget(window);
	Page->resize(800,600);

	Man = isMan;
	DayPerson = isDayPerson;
	Title = new QLabel();
	Title->setScaledContents(true);
	Title->setGeometry(QRect(0,0,800,600));
    QPixmap image;
    image.load(QString::fromUtf8("Resources/White.png"));
    Title->setPixmap(image);

	window->setCentralWidget(Title);



	QIcon Menu1;
	Menu1.addPixmap(QPixmap(QString::fromUtf8("Resources/Semester1.png")), QIcon::Normal, QIcon::Off);
	QIcon Menu2;
	Menu2.addPixmap(QPixmap(QString::fromUtf8("Resources/Semester2.png")), QIcon::Normal, QIcon::Off);
	QIcon Menu3;
	Menu3.addPixmap(QPixmap(QString::fromUtf8("Resources/Semester3.png")), QIcon::Normal, QIcon::Off);
	QIcon Menu4;
	Menu4.addPixmap(QPixmap(QString::fromUtf8("Resources/Semester4.png")), QIcon::Normal, QIcon::Off);
	QIcon Menu5;
	Menu5.addPixmap(QPixmap(QString::fromUtf8("Resources/Semester5.png")), QIcon::Normal, QIcon::Off);
	QIcon Menu6;
	Menu6.addPixmap(QPixmap(QString::fromUtf8("Resources/Semester6.png")), QIcon::Normal, QIcon::Off);
	QIcon Menu7;
	Menu7.addPixmap(QPixmap(QString::fromUtf8("Resources/Semester7.png")), QIcon::Normal, QIcon::Off);
	QIcon Menu8;
	Menu8.addPixmap(QPixmap(QString::fromUtf8("Resources/Semester8.png")), QIcon::Normal, QIcon::Off);
	QIcon NextIcon;
	NextIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/GoStart.png")), QIcon::Normal, QIcon::Off);

	Head = new QLabel(Title);
	Head->setScaledContents(true);
	Head->setGeometry(QRect(270,45,250,80));
    QPixmap Himage;
    Himage.load(QString::fromUtf8("Resources/SemesterSelect.png"));
    Head->setPixmap(Himage);
	Head->show();


	
	Semester1Button = new QPushButton(Title);
    Semester1Button->setGeometry(QRect(125, 150, 100, 100));
	Semester1Button->setIcon(Menu1);
	Semester1Button->setIconSize(QSize(90, 90));
	Semester1Button->setFlat(true);
	Semester1Button->show();

	
	Semester2Button = new QPushButton(Title);
    Semester2Button->setGeometry(QRect(275, 150, 100, 100));
	Semester2Button->setIcon(Menu2);
	Semester2Button->setIconSize(QSize(90, 90));
	Semester2Button->setFlat(true);
	Semester2Button->show();

	
	Semester3Button = new QPushButton(Title);
    Semester3Button->setGeometry(QRect(425, 150, 100, 100));
	Semester3Button->setIcon(Menu3);
	Semester3Button->setIconSize(QSize(90, 90));
	Semester3Button->setFlat(true);
	Semester3Button->show();

	
	Semester4Button = new QPushButton(Title);
    Semester4Button->setGeometry(QRect(575, 150, 100, 100));
	Semester4Button->setIcon(Menu4);
	Semester4Button->setIconSize(QSize(90, 90));
	Semester4Button->setFlat(true);
	Semester4Button->show();

	
	Semester5Button = new QPushButton(Title);
    Semester5Button->setGeometry(QRect(125, 300, 100, 100));
	Semester5Button->setIcon(Menu5);
	Semester5Button->setIconSize(QSize(90, 90));
	Semester5Button->setFlat(true);
	Semester5Button->show();

	
	Semester6Button = new QPushButton(Title);
    Semester6Button->setGeometry(QRect(275, 300, 100, 100));
	Semester6Button->setIcon(Menu6);
	Semester6Button->setIconSize(QSize(90, 90));
	Semester6Button->setFlat(true);
	Semester6Button->show();

	
	Semester7Button = new QPushButton(Title);
    Semester7Button->setGeometry(QRect(425, 300, 100, 100));
	Semester7Button->setIcon(Menu7);
	Semester7Button->setIconSize(QSize(90, 90));
	Semester7Button->setFlat(true);
	Semester7Button->show();

	
	Semester8Button = new QPushButton(Title);
    Semester8Button->setGeometry(QRect(575, 300, 100, 100));
	Semester8Button->setIcon(Menu8);
	Semester8Button->setIconSize(QSize(90, 90));
	Semester8Button->setFlat(true);
	Semester8Button->show();

	
/*	QPushButton *nextButton;
	nextButton = new QPushButton(Title);
	nextButton->setGeometry(QRect(295, 515, 210, 70));
	nextButton->setIcon(NextIcon);
	nextButton->setIconSize(QSize(200, 64));
	nextButton->setFlat(true);
	nextButton->show();*/


	QObject::connect(Semester1Button,SIGNAL(clicked()),this,SLOT(Start1()));
	QObject::connect(Semester2Button,SIGNAL(clicked()),this,SLOT(Start2()));
	QObject::connect(Semester3Button,SIGNAL(clicked()),this,SLOT(Start3()));
	QObject::connect(Semester4Button,SIGNAL(clicked()),this,SLOT(Start4()));
	QObject::connect(Semester5Button,SIGNAL(clicked()),this,SLOT(Start5()));
	QObject::connect(Semester6Button,SIGNAL(clicked()),this,SLOT(Start6()));
	QObject::connect(Semester7Button,SIGNAL(clicked()),this,SLOT(Start7()));
	QObject::connect(Semester8Button,SIGNAL(clicked()),this,SLOT(Start8()));

//	QObject::connect(nextButton, SIGNAL(clicked()),this,SLOT(NextClicked()));

	Title->show();
}
void SelectScene::Start1()
{
	struct data s;
	s.isSemester=1;
	FieldScene* fieldscene = new FieldScene(window, Man, DayPerson, s);
}
void SelectScene::Start2()
{
	struct data s;
	s.isSemester=2;
	FieldScene* fieldscene = new FieldScene(window, Man, DayPerson, s);
}
void SelectScene::Start3()
{
	struct data s;
	s.isSemester=3;
	FieldScene* fieldscene = new FieldScene(window, Man, DayPerson, s);
}
void SelectScene::Start4()
{
	struct data s;
	s.isSemester=4;
	FieldScene* fieldscene = new FieldScene(window, Man, DayPerson, s);
}
void SelectScene::Start5()
{
	struct data s;
	s.isSemester=5;
	FieldScene* fieldscene = new FieldScene(window, Man, DayPerson, s);
}
void SelectScene::Start6()
{
	struct data s;
	s.isSemester=6;
	FieldScene* fieldscene = new FieldScene(window, Man, DayPerson, s);
}
void SelectScene::Start7()
{
	struct data s;
	s.isSemester=7;
	FieldScene* fieldscene = new FieldScene(window, Man, DayPerson, s);
}
void SelectScene::Start8()
{
	struct data s;
	s.isSemester=8;
	FieldScene* fieldscene = new FieldScene(window, Man, DayPerson, s);
}
/*void LoadScene::MousePressEvent(QMouseEvent *event){
	Cursor = event->pos();
}*/
