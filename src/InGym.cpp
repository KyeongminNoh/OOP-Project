#include "InGym.h"
#include "Map.h"
#include "ManageGame.h"
#include "Building.h"
#include "AskAlert.h"
#include "NormalAlert.h"

InGym::InGym(ManageGame *Game, QWidget *parent) : QWidget(parent){

	onGoingGame = Game;
	resize(660, 450);
	QPixmap Image;
	
	askalert = NULL;
	normalalert = NULL;
	
		if(onGoingGame->getBuilding(3)->get_level()==1)
		{
			Image.load(QString::fromUtf8("Resources/Gym1.png")); // 체력회복량까지
		}
		else if(onGoingGame->getBuilding(3)->get_level()==2)
		{
			Image.load(QString::fromUtf8("Resources/Gym2.png"));
		}
		else if(onGoingGame->getBuilding(3)->get_level()==3)
		{
			Image.load(QString::fromUtf8("Resources/Gym3.png"));
		}
		Screen = new QLabel(this);
		Screen->setScaledContents(true);
		Screen->resize(660, 450);
		Screen->setGeometry(QRect(0, 0, 660, 450));
		Screen->setPixmap(Image);
		
		
		

		QIcon ExerImage;
		ExerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/Exercise.png")), QIcon::Normal, QIcon::Off);

		QPushButton *ExerButton;
		ExerButton = new QPushButton(Screen);
		ExerButton->setGeometry(QRect(100, 210, 120, 60));
		ExerButton->setIcon(ExerImage);
		ExerButton->setIconSize(QSize(120, 60));
		ExerButton->setFlat(true);

		/*
		QLabel* exerEff;
		exerEff = new QLabel(Screen);
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
		*/


		QIcon UpgradeImage;
		UpgradeImage.addPixmap(QPixmap(QString::fromUtf8("Resources/Upgrade.png")), QIcon::Normal, QIcon::Off);

		QPushButton *UpgradeButton;
		UpgradeButton = new QPushButton(Screen);
		UpgradeButton->setGeometry(QRect(300, 340, 130, 60));
		UpgradeButton->setIcon(UpgradeImage);
		UpgradeButton->setIconSize(QSize(120, 60));
		UpgradeButton->setFlat(true);

		QIcon BackImage;
		BackImage.addPixmap(QPixmap(QString::fromUtf8("Resources/GoBack_InGame.png")), QIcon::Normal, QIcon::Off);

		QPushButton *BackButton;
		BackButton = new QPushButton(Screen);
		BackButton->setGeometry(QRect(450, 340, 130, 60));
		BackButton->setIcon(BackImage);
		BackButton->setIconSize(QSize(120, 60));
		BackButton->setFlat(true);
		Screen->show();

		QObject::connect(ExerButton, SIGNAL(clicked()), this, SLOT(setExerAlert()));
		QObject::connect(UpgradeButton, SIGNAL(clicked()), this, SLOT(setGym_Upgrade_Alert()));
		QObject::connect(BackButton,SIGNAL(clicked()), onGoingGame, SLOT(BACKalert()));

	
}

void InGym::setExerAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Exer",Screen);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void InGym::setGym_Upgrade_Alert(){
	if(askalert !=NULL)
		return;
	else{
		if(onGoingGame->getBuilding(3)->get_level() == 1){
			askalert = new AskAlert(onGoingGame, "GymUpgrade1",Screen);
			askalert->setGeometry(QRect(110, 100, 300, 225));
			askalert->show();
		}
		else if(onGoingGame->getBuilding(3)->get_level() == 2){
			askalert = new AskAlert(onGoingGame, "GymUpgrade2",Screen);
			askalert->setGeometry(QRect(110, 100, 300, 225));
			askalert->show();
		}
	}
}

void InGym::setNormalAlert(QString name){
	if(normalalert != NULL)
		return;
	else{
		normalalert = new NormalAlert(onGoingGame, name, "Gym" ,Screen);
		normalalert->setGeometry(QRect(110, 150, 300, 150));
		normalalert->show();
	}
}

void InGym::DeleteNormalAlert(){
	if(normalalert != NULL)
		delete normalalert;

	normalalert = NULL;
}

void InGym::DeleteAskAlert(){
	if(askalert != NULL)
		delete askalert;
	askalert = NULL;
}

void InGym::ReDraw(){
		QPixmap Image;
		if(onGoingGame->getBuilding(3)->get_level()==1)
		{
			Image.load(QString::fromUtf8("Resources/Gym1.png")); // 체력회복량까지
		}
		else if(onGoingGame->getBuilding(3)->get_level()==2)
		{
			Image.load(QString::fromUtf8("Resources/Gym2.png"));
		}
		else if(onGoingGame->getBuilding(3)->get_level()==3)
		{
			Image.load(QString::fromUtf8("Resources/Gym3.png"));
		}
		Screen->setPixmap(Image);
		repaint();
}