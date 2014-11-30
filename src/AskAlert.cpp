#include "AskAlert.h"
#include "ManageGame.h"
#include "Map.h"

AskAlert::AskAlert(ManageGame *Game, QString Name, QWidget *parent) : QWidget(parent){


	onGoingGame = Game;
	BuildingName = Name;
	resize(300, 225);

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

	/* Gym 내부 */
	else if(BuildingName == "Exer") // 운동하는 것, building은 아님
		Image.load(QString::fromUtf8("Resources/AskExercise.png"));
	else if(BuildingName == "GymUpgrade1")
		Image.load(QString::fromUtf8("Resources/AskUpgrade1.png"));
	else if(BuildingName == "GymUpgrade2")
		Image.load(QString::fromUtf8("Resources/AskUpgrade2.png"));

	/* Cafeteria 내부 */
	else if(BuildingName == "Eat") // 운동하는 것, building은 아님
		Image.load(QString::fromUtf8("Resources/AskEat.png"));
	else if(BuildingName == "CafUpgrade1")
		Image.load(QString::fromUtf8("Resources/AskUpgrade1.png"));
	else if(BuildingName == "CafUpgrade2")
		Image.load(QString::fromUtf8("Resources/AskUpgrade2.png"));

	askalert = new QLabel(this);
	askalert->setScaledContents(true);
	askalert->setGeometry(QRect(0, 0, 300, 225));
	askalert->setPixmap(Image);

	font = new QFont( "Resources/NanumBarunGothic.ttp");
	font->setKerning( true );
	font->setBold( true );
	font->setPixelSize( 20 );

	
	Yes = new QPushButton(askalert);
	Yes->setGeometry(QRect(30, 170, 100, 45));
	QIcon YesIcon;
    YesIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/Yes.png")), QIcon::Normal, QIcon::Off);
	Yes->setIcon(YesIcon);
	Yes->setIconSize(QSize(90, 36));
	Yes->setFlat(true);
	Yes->show();
	No = new QPushButton(askalert);
	No->setGeometry(QRect(170, 170, 100, 45));
	QIcon NoIcon;
    NoIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/No.png")), QIcon::Normal, QIcon::Off);
	No->setIcon(NoIcon);
	No->setIconSize(QSize(90, 36));
	No->setFlat(true);
	No->show();

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
	else if(BuildingName == "Exer")
		QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(DoExer()));
	else if(BuildingName == "GymUpgrade1" || BuildingName == "GymUpgrade2")
		QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(BuildGym()));
	else if(BuildingName == "B" )
		QObject::connect(Yes, SIGNAL(clicked()), this ,SLOT(EatB()));
	else if(BuildingName == "C" )
		QObject::connect(Yes, SIGNAL(clicked()), this ,SLOT(EatC()));
	else if(BuildingName == "D" )
		QObject::connect(Yes, SIGNAL(clicked()), this ,SLOT(EatD()));
	else if(BuildingName == "CafUpgrade1" || BuildingName == "CafUpgrade2")
		QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(BuildCafeteria()));



	if(BuildingName == "GymUpgrade1" || BuildingName == "GymUpgrade2" || BuildingName == "Exer")
		QObject::connect(No, SIGNAL(clicked()), onGoingGame, SLOT(NothingInGym()));
	else if(BuildingName == "CafUpgrade1" || BuildingName == "CafUpgrade2" || BuildingName == "B" || BuildingName == "C" || BuildingName == "D"){
		QObject::connect(No, SIGNAL(clicked()), onGoingGame, SLOT(NothingInCaf()));
	}
	else{
		QObject::connect(No, SIGNAL(clicked()), onGoingGame, SLOT(NoBuild()));
	}
}


void AskAlert::paintEvent(QPaintEvent *event){
	ask = new QPainter(this);

	QString question, B;
	question.append("Do you want Build");
	
}

void AskAlert::EatB(){
	onGoingGame->EatinCaf(1);
}

void AskAlert::EatC(){
	onGoingGame->EatinCaf(2);
}

void AskAlert::EatD(){
	onGoingGame->EatinCaf(3);
}
