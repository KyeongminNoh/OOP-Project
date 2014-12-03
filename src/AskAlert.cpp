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

	/* Gym ���� */
	else if(BuildingName == "Exer") // ��ϴ� ��, building�� �ƴ�
		Image.load(QString::fromUtf8("Resources/AskExercise.png"));
	else if(BuildingName == "GymUpgrade1")
		Image.load(QString::fromUtf8("Resources/AskUpgrade1.png"));
	else if(BuildingName == "GymUpgrade2")
		Image.load(QString::fromUtf8("Resources/AskUpgrade2.png"));

	/* Cafeteria ���� */
	else if(BuildingName == "B" || BuildingName == "C" || BuildingName == "D") // ��ϴ� ��, building�� �ƴ�
		Image.load(QString::fromUtf8("Resources/AskEat.png"));
	else if(BuildingName == "CafUpgrade1")
		Image.load(QString::fromUtf8("Resources/AskUpgrade1.png"));
	else if(BuildingName == "CafUpgrade2")
		Image.load(QString::fromUtf8("Resources/AskUpgrade2.png"));

	/* Market ���� */
	else if(BuildingName == "Drink1" || BuildingName == "Drink2" || BuildingName == "Drink3") // ��ϴ� ��, building�� �ƴ�
		Image.load(QString::fromUtf8("Resources/AskDrink.png"));
	else if(BuildingName == "MarUpgrade1")
		Image.load(QString::fromUtf8("Resources/AskUpgrade1_Market.png"));
	else if(BuildingName == "MarUpgrade2")
		Image.load(QString::fromUtf8("Resources/AskUpgrade2_Market.png"));

	/* LogHouse ���� */
	else if(BuildingName == "LogA" || BuildingName == "LogB" || BuildingName == "LogC") // ��ϴ� ��, building�� �ƴ�
		Image.load(QString::fromUtf8("Resources/AskLog.png"));
	else if(BuildingName == "LogUpgrade1")
		Image.load(QString::fromUtf8("Resources/AskUpgrade1.png"));
	else if(BuildingName == "LogUpgrade2")
		Image.load(QString::fromUtf8("Resources/AskUpgrade2.png"));

		/* StudentHall ���� */
	else if(BuildingName == "clubA" || BuildingName == "clubB" || BuildingName == "clubC") // ��ϴ� ��, building�� �ƴ�
		Image.load(QString::fromUtf8("Resources/AskClub.png"));
	else if(BuildingName == "StuUpgrade1")
		Image.load(QString::fromUtf8("Resources/AskUpgrade1_StuHall.png"));
	else if(BuildingName == "StuUpgrade2")
		Image.load(QString::fromUtf8("Resources/AskUpgrade2_StuHall.png"));

	// Library ����

	else if(BuildingName == "Study") 
		Image.load(QString::fromUtf8("Resources/AskStudy.png"));
	else if(BuildingName == "LibUpgrade1")
		Image.load(QString::fromUtf8("Resources/AskUpgrade1.png"));
	else if(BuildingName == "LibUpgrade2")
		Image.load(QString::fromUtf8("Resources/AskUpgrade2.png"));

	// Labor ����

	else if(BuildingName == "Work") 
		Image.load(QString::fromUtf8("Resources/AskWork.png"));
	else if(BuildingName == "LabUpgrade1")
		Image.load(QString::fromUtf8("Resources/AskUpgrade1.png"));
	else if(BuildingName == "LabUpgrade2")
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


	else if(BuildingName == "Exer") // Gym
		QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(DoExer()));
	else if(BuildingName == "GymUpgrade1" || BuildingName == "GymUpgrade2")
		QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(BuildGym()));


	else if(BuildingName == "B" ) // Cafeteria
		QObject::connect(Yes, SIGNAL(clicked()), this ,SLOT(EatB()));
	else if(BuildingName == "C" )
		QObject::connect(Yes, SIGNAL(clicked()), this ,SLOT(EatC()));
	else if(BuildingName == "D" )
		QObject::connect(Yes, SIGNAL(clicked()), this ,SLOT(EatD()));
	else if(BuildingName == "CafUpgrade1" || BuildingName == "CafUpgrade2")
		QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(BuildCafeteria()));


	else if(BuildingName == "Drink1" )
		QObject::connect(Yes, SIGNAL(clicked()), this ,SLOT(Drink1()));
	else if(BuildingName == "Drink2" )
		QObject::connect(Yes, SIGNAL(clicked()), this ,SLOT(Drink2()));
	else if(BuildingName == "Drink3" )
		QObject::connect(Yes, SIGNAL(clicked()), this ,SLOT(Drink3()));
	else if(BuildingName == "MarUpgrade1" || BuildingName == "MarUpgrade2")
		QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(BuildMarket()));

	else if(BuildingName == "LogA" )
		QObject::connect(Yes, SIGNAL(clicked()), this ,SLOT(LogA()));
	else if(BuildingName == "LogB" )
		QObject::connect(Yes, SIGNAL(clicked()), this ,SLOT(LogB()));
	else if(BuildingName == "LogC" )
		QObject::connect(Yes, SIGNAL(clicked()), this ,SLOT(LogC()));
	else if(BuildingName == "LogUpgrade1" || BuildingName == "LogUpgrade2")
		QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(BuildLogHouse()));

	else if(BuildingName == "clubA" )
		QObject::connect(Yes, SIGNAL(clicked()), this ,SLOT(ClubA()));
	else if(BuildingName == "clubB" )
		QObject::connect(Yes, SIGNAL(clicked()), this ,SLOT(ClubB()));
	else if(BuildingName == "clubC" )
		QObject::connect(Yes, SIGNAL(clicked()), this ,SLOT(ClubC()));
	else if(BuildingName == "StuUpgrade1" || BuildingName == "StuUpgrade2")
		QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(BuildStudentHall()));

	else if(BuildingName == "Study") // Library
		QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(DoStudy()));
	else if(BuildingName == "LibUpgrade1" || BuildingName == "LibUpgrade2")
		QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(BuildLibrary()));

	else if(BuildingName == "Work") // Labor
		QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(DoWork()));
	else if(BuildingName == "LabUpgrade1" || BuildingName == "LabUpgrade2")
		QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(BuildLaborBuilding()));

	if(BuildingName == "GymUpgrade1" || BuildingName == "GymUpgrade2" || BuildingName == "Exer")
		QObject::connect(No, SIGNAL(clicked()), onGoingGame, SLOT(NothingInGym()));
	else if(BuildingName == "LibUpgrade1" || BuildingName == "LibUpgrade2" || BuildingName == "Study")
		QObject::connect(No, SIGNAL(clicked()), onGoingGame, SLOT(NothingInLib()));
	else if(BuildingName == "LabUpgrade1" || BuildingName == "LabUpgrade2" || BuildingName == "Work")
		QObject::connect(No, SIGNAL(clicked()), onGoingGame, SLOT(NothingInLab()));
	else if(BuildingName == "CafUpgrade1" || BuildingName == "CafUpgrade2" || BuildingName == "B" || BuildingName == "C" || BuildingName == "D"){
		QObject::connect(No, SIGNAL(clicked()), onGoingGame, SLOT(NothingInCaf()));
	}
	else if(BuildingName == "MarUpgrade1" || BuildingName == "MarUpgrade2" || BuildingName == "Drink1" || BuildingName == "Drink2" || BuildingName == "Drink3"){
		QObject::connect(No, SIGNAL(clicked()), onGoingGame, SLOT(NothingInMar()));
	}
	else if(BuildingName == "LogUpgrade1" || BuildingName == "LogUpgrade2" || BuildingName == "LogA" || BuildingName == "LogB" || BuildingName == "LogC"){
		QObject::connect(No, SIGNAL(clicked()), onGoingGame, SLOT(NothingInMar()));
	}
	else if(BuildingName == "StuUpgrade1" || BuildingName == "StuUpgrade2" || BuildingName == "clubA" || BuildingName == "clubB" || BuildingName == "clubC"){
		QObject::connect(No, SIGNAL(clicked()), onGoingGame, SLOT(NothingInStu()));
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

void AskAlert::Drink1(){
	onGoingGame->DrinkinMarket(1);
};

void AskAlert::Drink2(){
	onGoingGame->DrinkinMarket(2);
};

void AskAlert::Drink3(){
	onGoingGame->DrinkinMarket(3);
};

void AskAlert::LogA(){
	onGoingGame->EatinLogHouse(1);
}

void AskAlert::LogB(){
	onGoingGame->EatinLogHouse(2);
}

void AskAlert::LogC(){
	onGoingGame->EatinLogHouse(3);
}

void AskAlert::ClubA(){
	onGoingGame->ClubActivity(1);
}

void AskAlert::ClubB(){
	onGoingGame->ClubActivity(2);
}

void AskAlert::ClubC(){
	onGoingGame->ClubActivity(3);
}