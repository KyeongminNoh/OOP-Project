#include "InCafeteria.h"
#include "Map.h"
#include "ManageGame.h"
#include "Building.h"
#include "AskAlert.h"
#include "NormalAlert.h"

InCafeteria::InCafeteria(ManageGame *Game, QWidget *parent) : QWidget(parent){

	onGoingGame = Game;
	resize(660, 450);
	QPixmap Image;
	
	askalert = NULL;
	normalalert = NULL;
	
		if(onGoingGame->getBuilding(1)->get_level()==1)
		{
			Image.load(QString::fromUtf8("Resources/Dining1.png")); // 체력회복량까지
		}
		else if(onGoingGame->getBuilding(1)->get_level()==2)
		{
			Image.load(QString::fromUtf8("Resources/Dining2.png"));
		}
		else if(onGoingGame->getBuilding(1)->get_level()==3)
		{
			Image.load(QString::fromUtf8("Resources/Dining3.png"));
		}
		Screen = new QLabel(this);
		Screen->setScaledContents(true);
		Screen->resize(660, 450);
		Screen->setGeometry(QRect(0, 0, 660, 450));
		Screen->setPixmap(Image);
		
		
		

		QIcon BcornerImage;
		BcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/B_activated.png")), QIcon::Normal, QIcon::Off);
		QIcon CcornerImage;
		CcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/C.png")), QIcon::Normal, QIcon::Off);
		QIcon DcornerImage;
		DcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/D.png")), QIcon::Normal, QIcon::Off);

		EatB_Button = new QPushButton(Screen);
		EatB_Button->setGeometry(QRect(135, 197, 112, 45));
		EatB_Button->setIcon(BcornerImage);
		EatB_Button->setIconSize(QSize(100, 40));
		EatB_Button->setFlat(true);

		EatC_Button = new QPushButton(Screen);
		EatC_Button->setGeometry(QRect(141, 247, 100, 40));
		EatC_Button->setIcon(CcornerImage);
		EatC_Button->setIconSize(QSize(100, 40));
		EatC_Button->setFlat(true);

		EatD_Button = new QPushButton(Screen);
		EatD_Button->setGeometry(QRect(141, 295, 100, 40));
		EatD_Button->setIcon(DcornerImage);
		EatD_Button->setIconSize(QSize(100, 40));
		EatD_Button->setFlat(true);

		if(onGoingGame->getBuilding(1)->get_level() >= 2){
			
			CcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/C_activated.png")), QIcon::Normal, QIcon::Off);
			EatC_Button->setGeometry(QRect(135, 245, 112, 45));
			EatC_Button->setIcon(CcornerImage);
			QObject::connect(EatC_Button, SIGNAL(clicked()), this, SLOT(setEatCAlert()));
		}
		if(onGoingGame->getBuilding(1)->get_level() == 3){
			DcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/D_activated.png")), QIcon::Normal, QIcon::Off);
			EatD_Button->setGeometry(QRect(135, 294, 112, 45));
			EatD_Button->setIcon(DcornerImage);
			QObject::connect(EatD_Button, SIGNAL(clicked()), this, SLOT(setEatDAlert()));
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

		QObject::connect(EatB_Button, SIGNAL(clicked()), this, SLOT(setEatBAlert()));

			
		QObject::connect(UpgradeButton, SIGNAL(clicked()), this, SLOT(setCaf_Upgrade_Alert()));
		QObject::connect(BackButton,SIGNAL(clicked()), onGoingGame, SLOT(BACKalert()));

	
}


void InCafeteria::setCaf_Upgrade_Alert(){
	if(askalert !=NULL)
		return;
	else{
		if(onGoingGame->getBuilding(1)->get_level() == 1){
			askalert = new AskAlert(onGoingGame, "CafUpgrade1",Screen);
			askalert->setGeometry(QRect(110, 100, 300, 225));
			askalert->show();
		}
		else if(onGoingGame->getBuilding(1)->get_level() == 2){
			askalert = new AskAlert(onGoingGame, "CafUpgrade2",Screen);
			askalert->setGeometry(QRect(110, 100, 300, 225));
			askalert->show();
		}
	}
}

void InCafeteria::setNormalAlert(QString name){
	if(normalalert != NULL)
		return;
	else{
		normalalert = new NormalAlert(onGoingGame, name, "Caf" ,Screen);
		normalalert->setGeometry(QRect(110, 150, 300, 150));
		normalalert->show();
	}
}

void InCafeteria::DeleteNormalAlert(){
	if(normalalert != NULL)
		delete normalalert;

	normalalert = NULL;
}

void InCafeteria::DeleteAskAlert(){
	if(askalert != NULL)
		delete askalert;

	askalert = NULL;
}

void InCafeteria::ReDraw(){
		QPixmap Image;
		if(onGoingGame->getBuilding(1)->get_level()==1)
		{
			Image.load(QString::fromUtf8("Resources/Dining1.png")); // 체력회복량까지
		}
		else if(onGoingGame->getBuilding(1)->get_level()==2)
		{
			Image.load(QString::fromUtf8("Resources/Dining2.png"));
		}
		else if(onGoingGame->getBuilding(1)->get_level()==3)
		{
			Image.load(QString::fromUtf8("Resources/Dining3.png"));
		}
		Screen->setPixmap(Image);

		if(onGoingGame->getBuilding(1)->get_level() >= 2){
			QIcon CcornerImage;
			CcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/C_activated.png")), QIcon::Normal, QIcon::Off);
			EatC_Button->setGeometry(QRect(135, 245, 112, 45));
			EatC_Button->setIcon(CcornerImage);
			QObject::connect(EatC_Button, SIGNAL(clicked()), this, SLOT(setEatCAlert()));
		}
		if(onGoingGame->getBuilding(1)->get_level() == 3){
			QIcon DcornerImage;
			DcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/D_activated.png")), QIcon::Normal, QIcon::Off);
			EatD_Button->setGeometry(QRect(135, 294, 112, 45));
			EatD_Button->setIcon(DcornerImage);
			QObject::connect(EatD_Button, SIGNAL(clicked()), this, SLOT(setEatDAlert()));
		}

		repaint();
}

void InCafeteria::setEatBAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "B" ,Screen);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void InCafeteria::setEatCAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "C" ,Screen);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void InCafeteria::setEatDAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "D" ,Screen);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}