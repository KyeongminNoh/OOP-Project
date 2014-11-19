#include "AskAlert.h"
#include "ManageGame.h"
#include "Map.h"

AskAlert::AskAlert(ManageGame *Game, QString Name, QWidget *parent) : QWidget(parent){


	onGoingGame = Game;
	BuildingName = Name;
	resize(300, 300);

	QPixmap Image;
	
	if(BuildingName == "Gym")
		Image.load(QString::fromUtf8("Resources/AskGym.png"));
	else if(BuildingName == "Lib")
		Image.load(QString::fromUtf8("Resources/AskLibrary.png"));
	else if(BuildingName == "Lab")
		Image.load(QString::fromUtf8("Resources/AskLabor.png"));
	else if(BuildingName == "Log")
		Image.load(QString::fromUtf8("Resources/AskLogHouse.png"));
	else if(BuildingName == "Stu")
		Image.load(QString::fromUtf8("Resources/AskStuHall.png"));
	else if(BuildingName == "Mar")
		Image.load(QString::fromUtf8("Resources/AskMarket.png"));

	askalert = new QLabel(this);
	askalert->resize(300, 300);
	askalert->setGeometry(QRect(0, 0, 300, 300));
	askalert->setPixmap(Image);

	font = new QFont( "Resources/NanumBarunGothic.ttp");
	font->setKerning( true );
	font->setBold( true );
	font->setPixelSize( 20 );

	
	Yes = new QPushButton(askalert);
	Yes->setText("Yes");
	Yes->resize(100, 50);
	Yes->setGeometry(QRect(30, 225, 100, 50));
	No = new QPushButton(askalert);
	No->setText("No");
	No->resize(100, 50);
	No->setGeometry(QRect(170, 225, 100, 50));

	askalert->show();
	if(BuildingName == "Gym")
		QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(BuildGym()));
	else if(BuildingName == "Lib")
		QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(BuildLibrary()));
	else if(BuildingName == "Lab")
		QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(BuildLaborBuilding()));
	else if(BuildingName == "Log")
		QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(BuildLogHouse()));
	else if(BuildingName == "Stu")
		QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(BuildStudentHall()));
	else if(BuildingName == "Mar")
		QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(BuildMarket()));


	QObject::connect(No, SIGNAL(clicked()), onGoingGame, SLOT(NoBuild()));
}


void AskAlert::paintEvent(QPaintEvent *event){
	ask = new QPainter(this);

	QString question, B;
	question.append("Do you want Build");
	
}
