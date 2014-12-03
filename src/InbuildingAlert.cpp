#include "InbuildingAlert.h"
#include "ManageGame.h"
#include "Map.h"
#include "Building.h"

InbuildingAlert::InbuildingAlert(ManageGame *Game, QString Name, QWidget *parent) : QWidget(parent){

	alertType = Name;
	onGoingGame = Game;
	resize(660, 450);

	QPixmap Image;
	
	if(alertType == "Gym")
	{
		Image.load(QString::fromUtf8("Resources/InGym.jpg"));
		Inbuildingalert = new QLabel(this);
		Inbuildingalert->resize(660, 450);
		Inbuildingalert->setGeometry(QRect(0, 0, 660, 450));
		Inbuildingalert->setPixmap(Image);
		QLabel* buildname;
		buildname = new QLabel(Inbuildingalert);
		buildname->setScaledContents(true);
		buildname->setGeometry(QRect(0,0,300,140));
		QPixmap buildnameImage;
		if(onGoingGame->getBuilding(3)->get_level()==1)
		{
			buildnameImage.load(QString::fromUtf8("Resources/Gym_Title_level1.png")); // 체력회복량까지
		}
		else if(onGoingGame->getBuilding(3)->get_level()==2)
		{
			buildnameImage.load(QString::fromUtf8("Resources/Gym_Title_level2.png"));
		}
		else if(onGoingGame->getBuilding(3)->get_level()==3)
		{
			buildnameImage.load(QString::fromUtf8("Resources/Gym_Title_level3.png"));
		}
		buildname->setPixmap(buildnameImage);

//		buildname->show();

		QIcon ExerImage;
		ExerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/ExerciseButton.png")), QIcon::Normal, QIcon::Off);

		QPushButton *ExerButton;
		ExerButton = new QPushButton(Inbuildingalert);
		ExerButton->setGeometry(QRect(120, 200, 120, 60));
		ExerButton->setIcon(ExerImage);
		ExerButton->setIconSize(QSize(120, 60));

		QLabel* exerEff;
		exerEff = new QLabel(Inbuildingalert);
		exerEff->setScaledContents(true);
		exerEff->setGeometry(QRect(200,200,200,60));
		QPixmap exerEffImage;
		if(onGoingGame->getBuilding(3)->get_level()==1)
		{
			exerEffImage.load(QString::fromUtf8("Resources/exerEff_level1.png")); // 운동효과
		}
		else if(onGoingGame->getBuilding(3)->get_level()==2)
		{
			exerEffImage.load(QString::fromUtf8("Resources/exerEff_level2.png"));
		}
		else if(onGoingGame->getBuilding(3)->get_level()==3)
		{
			exerEffImage.load(QString::fromUtf8("Resources/exerEff_level3.png"));
		}
		exerEff->setPixmap(exerEffImage);

		QIcon UpgradeImage;
		UpgradeImage.addPixmap(QPixmap(QString::fromUtf8("Resources/UpgradeButton.png")), QIcon::Normal, QIcon::Off);

		QPushButton *UpgradeButton;
		UpgradeButton = new QPushButton(Inbuildingalert);
		UpgradeButton->setGeometry(QRect(300, 340, 120, 60));
		UpgradeButton->setIcon(UpgradeImage);
		UpgradeButton->setIconSize(QSize(120, 60));

		QIcon BackImage;
		BackImage.addPixmap(QPixmap(QString::fromUtf8("Resources/BackButton.png")), QIcon::Normal, QIcon::Off);

		QPushButton *BackButton;
		BackButton = new QPushButton(Inbuildingalert);
		BackButton->setGeometry(QRect(450, 340, 120, 60));
		BackButton->setIcon(BackImage);
		BackButton->setIconSize(QSize(120, 60));

		Inbuildingalert->show();

		QObject::connect(ExerButton, SIGNAL(clicked()), this, SLOT(setExerAlert()));
		QObject::connect(UpgradeButton, SIGNAL(clicked()), this, SLOT(setGym_Upgrade_Alert()));
		QObject::connect(BackButton,SIGNAL(clicked()), onGoingGame, SLOT(Inbuildingalert()));

	}
	else if(alertType == "Mar")
		Image.load(QString::fromUtf8("Resources/InMarket.png"));
	else if(alertType == "Lib")
		Image.load(QString::fromUtf8("Resources/InLibrary.png"));
	else if(alertType == "Stu")
		Image.load(QString::fromUtf8("Resources/InStudentHall.png"));


/*
	font = new QFont( "Resources/NanumBarunGothic.ttp");
	font->setKerning( true );
	font->setBold( true );
	font->setPixelSize( 20 );

	
	OK = new QPushButton(Inbuildingalert);
	OK->setText("OK");
	OK->resize(100, 50);
	OK->setGeometry(QRect(100, 125, 100, 50));

	Inbuildingalert->show();


	QObject::connect(OK, SIGNAL(clicked()), onGoingGame, SLOT(OKalert()));*/
}

void InbuildingAlert::InGym(ManageGame *Game)
{

}
