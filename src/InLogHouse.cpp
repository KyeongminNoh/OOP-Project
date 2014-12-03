#include "InLogHouse.h"
#include "Map.h"
#include "ManageGame.h"
#include "Building.h"
#include "AskAlert.h"
#include "NormalAlert.h"

InLogHouse::InLogHouse(ManageGame *Game, QWidget *parent) : QWidget(parent){

	onGoingGame = Game;
	resize(660, 450);
	QPixmap Image;
	
	askalert = NULL;
	normalalert = NULL;
	
		if(onGoingGame->getBuilding(7)->get_level()==1)
		{
			Image.load(QString::fromUtf8("Resources/LogHouse1.png")); // 체력회복량까지
		}
		else if(onGoingGame->getBuilding(7)->get_level()==2)
		{
			Image.load(QString::fromUtf8("Resources/LogHouse2.png"));
		}
		else if(onGoingGame->getBuilding(7)->get_level()==3)
		{
			Image.load(QString::fromUtf8("Resources/LogHouse3.png"));
		}
		Screen = new QLabel(this);
		Screen->setScaledContents(true);
		Screen->resize(660, 450);
		Screen->setGeometry(QRect(0, 0, 660, 450));
		Screen->setPixmap(Image);
		
		
		

		QIcon BcornerImage;
		BcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/LogA_activated.png")), QIcon::Normal, QIcon::Off);
		QIcon CcornerImage;
		CcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/LogB.png")), QIcon::Normal, QIcon::Off);
		QIcon DcornerImage;
		DcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/LogC.png")), QIcon::Normal, QIcon::Off);

		LogA_Button = new QPushButton(Screen);
		LogA_Button->setGeometry(QRect(100, 187, 112, 45));
		LogA_Button->setIcon(BcornerImage);
		LogA_Button->setIconSize(QSize(100, 40));
		LogA_Button->setFlat(true);

		LogB_Button = new QPushButton(Screen);
		LogB_Button->setGeometry(QRect(106, 237, 100, 40));
		LogB_Button->setIcon(CcornerImage);
		LogB_Button->setIconSize(QSize(100, 40));
		LogB_Button->setFlat(true);

		LogC_Button = new QPushButton(Screen);
		LogC_Button->setGeometry(QRect(106, 285, 100, 40));
		LogC_Button->setIcon(DcornerImage);
		LogC_Button->setIconSize(QSize(100, 40));
		LogC_Button->setFlat(true);

		if(onGoingGame->getBuilding(7)->get_level() >= 2){
			
			CcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/LogB_activated.png")), QIcon::Normal, QIcon::Off);
			LogB_Button->setGeometry(QRect(100, 235, 112, 45));
			LogB_Button->setIcon(CcornerImage);
			QObject::connect(LogB_Button, SIGNAL(clicked()), this, SLOT(setLogBAlert()));
		}
		if(onGoingGame->getBuilding(7)->get_level() == 3){
			DcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/LogC_activated.png")), QIcon::Normal, QIcon::Off);
			LogC_Button->setGeometry(QRect(100, 284, 112, 45));
			LogC_Button->setIcon(DcornerImage);
			QObject::connect(LogC_Button, SIGNAL(clicked()), this, SLOT(setLogCAlert()));
		}



		QIcon UpgradeImage;
		UpgradeImage.addPixmap(QPixmap(QString::fromUtf8("Resources/Upgrade.png")), QIcon::Normal, QIcon::Off);

		
		UpgradeButton = new QPushButton(Screen);
		UpgradeButton->setGeometry(QRect(300, 340, 130, 60));
		UpgradeButton->setIcon(UpgradeImage);
		UpgradeButton->setIconSize(QSize(120, 60));
		UpgradeButton->setFlat(true);

		QIcon BackImage;
		BackImage.addPixmap(QPixmap(QString::fromUtf8("Resources/GoBack_InGame.png")), QIcon::Normal, QIcon::Off);

		
		BackButton = new QPushButton(Screen);
		BackButton->setGeometry(QRect(450, 340, 130, 60));
		BackButton->setIcon(BackImage);
		BackButton->setIconSize(QSize(120, 60));
		BackButton->setFlat(true);
		Screen->show();

		QObject::connect(LogA_Button, SIGNAL(clicked()), this, SLOT(setLogAAlert()));

			
		QObject::connect(UpgradeButton, SIGNAL(clicked()), this, SLOT(setMar_Upgrade_Alert()));
		QObject::connect(BackButton,SIGNAL(clicked()), onGoingGame, SLOT(BACKalert()));

	
}


void InLogHouse::setMar_Upgrade_Alert(){
	if(askalert !=NULL)
		return;
	else{
		if(onGoingGame->getBuilding(7)->get_level() == 1){
			askalert = new AskAlert(onGoingGame, "LogUpgrade1",Screen);
			askalert->setGeometry(QRect(110, 100, 300, 225));
			askalert->show();
		}
		else if(onGoingGame->getBuilding(7)->get_level() == 2){
			askalert = new AskAlert(onGoingGame, "LogUpgrade2",Screen);
			askalert->setGeometry(QRect(110, 100, 300, 225));
			askalert->show();
		}
	}
}

void InLogHouse::setNormalAlert(QString name){
	if(normalalert != NULL)
		return;
	else{
		normalalert = new NormalAlert(onGoingGame, name, "Log" ,Screen);
		normalalert->setGeometry(QRect(110, 150, 300, 150));
		normalalert->show();
	}
}

void InLogHouse::DeleteNormalAlert(){
	if(normalalert != NULL)
		delete normalalert;

	normalalert = NULL;
}

void InLogHouse::DeleteAskAlert(){
	if(askalert != NULL)
		delete askalert;

	askalert = NULL;
}

void InLogHouse::ReDraw(){
		QPixmap Image;
		if(onGoingGame->getBuilding(7)->get_level()==1)
		{
			Image.load(QString::fromUtf8("Resources/LogHouse1.png")); // 체력회복량까지
		}
		else if(onGoingGame->getBuilding(7)->get_level()==2)
		{
			Image.load(QString::fromUtf8("Resources/LogHouse2.png"));
		}
		else if(onGoingGame->getBuilding(7)->get_level()==3)
		{
			Image.load(QString::fromUtf8("Resources/LogHouse3.png"));
		}
		Screen->setPixmap(Image);

		if(onGoingGame->getBuilding(7)->get_level() >= 2){
			QIcon CcornerImage;
			CcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/LogB_activated.png")), QIcon::Normal, QIcon::Off);
			LogB_Button->setGeometry(QRect(100, 235, 112, 45));
			LogB_Button->setIcon(CcornerImage);
			QObject::connect(LogB_Button, SIGNAL(clicked()), this, SLOT(setLogBAlert()));
		}
		if(onGoingGame->getBuilding(7)->get_level() == 3){
			QIcon DcornerImage;
			DcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/LogC_activated.png")), QIcon::Normal, QIcon::Off);
			LogC_Button->setGeometry(QRect(100, 284, 112, 45));
			LogC_Button->setIcon(DcornerImage);
			QObject::connect(LogC_Button, SIGNAL(clicked()), this, SLOT(setLogCAlert()));
		}

		repaint();
}

void InLogHouse::setLogAAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "LogA" ,Screen);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void InLogHouse::setLogBAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "LogB" ,Screen);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void InLogHouse::setLogCAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "LogC" ,Screen);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}