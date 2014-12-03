#include "InMarket.h"
#include "Map.h"
#include "ManageGame.h"
#include "Building.h"
#include "AskAlert.h"
#include "NormalAlert.h"

InMarket::InMarket(ManageGame *Game, QWidget *parent) : QWidget(parent){

	onGoingGame = Game;
	resize(660, 450);
	QPixmap Image;
	
	askalert = NULL;
	normalalert = NULL;
	
		if(onGoingGame->getBuilding(8)->get_level()==1)
		{
			Image.load(QString::fromUtf8("Resources/Market1.png")); // 체력회복량까지
		}
		else if(onGoingGame->getBuilding(8)->get_level()==2)
		{
			Image.load(QString::fromUtf8("Resources/Market2.png"));
		}
		else if(onGoingGame->getBuilding(8)->get_level()==3)
		{
			Image.load(QString::fromUtf8("Resources/Market3.png"));
		}
		Screen = new QLabel(this);
		Screen->setScaledContents(true);
		Screen->resize(660, 450);
		Screen->setGeometry(QRect(0, 0, 660, 450));
		Screen->setPixmap(Image);
		
		
		

		QIcon BcornerImage;
		BcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/Drink1_activated.png")), QIcon::Normal, QIcon::Off);
		QIcon CcornerImage;
		CcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/Drink2.png")), QIcon::Normal, QIcon::Off);
		QIcon DcornerImage;
		DcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/Drink3.png")), QIcon::Normal, QIcon::Off);

		Drink1_Button = new QPushButton(Screen);
		Drink1_Button->setGeometry(QRect(100, 187, 112, 45));
		Drink1_Button->setIcon(BcornerImage);
		Drink1_Button->setIconSize(QSize(100, 40));
		Drink1_Button->setFlat(true);

		Drink2_Button = new QPushButton(Screen);
		Drink2_Button->setGeometry(QRect(106, 237, 100, 40));
		Drink2_Button->setIcon(CcornerImage);
		Drink2_Button->setIconSize(QSize(100, 40));
		Drink2_Button->setFlat(true);

		Drink3_Button = new QPushButton(Screen);
		Drink3_Button->setGeometry(QRect(106, 285, 100, 40));
		Drink3_Button->setIcon(DcornerImage);
		Drink3_Button->setIconSize(QSize(100, 40));
		Drink3_Button->setFlat(true);

		if(onGoingGame->getBuilding(8)->get_level() >= 2){
			
			CcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/Drink2_activated.png")), QIcon::Normal, QIcon::Off);
			Drink2_Button->setGeometry(QRect(100, 235, 112, 45));
			Drink2_Button->setIcon(CcornerImage);
			QObject::connect(Drink2_Button, SIGNAL(clicked()), this, SLOT(setDrink2Alert()));
		}
		if(onGoingGame->getBuilding(8)->get_level() == 3){
			DcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/Drink3_activated.png")), QIcon::Normal, QIcon::Off);
			Drink3_Button->setGeometry(QRect(100, 284, 112, 45));
			Drink3_Button->setIcon(DcornerImage);
			QObject::connect(Drink3_Button, SIGNAL(clicked()), this, SLOT(setDrink3Alert()));
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

		QObject::connect(Drink1_Button, SIGNAL(clicked()), this, SLOT(setDrink1Alert()));

			
		QObject::connect(UpgradeButton, SIGNAL(clicked()), this, SLOT(setMar_Upgrade_Alert()));
		QObject::connect(BackButton,SIGNAL(clicked()), onGoingGame, SLOT(BACKalert()));

	
}


void InMarket::setMar_Upgrade_Alert(){
	if(askalert !=NULL)
		return;
	else{
		if(onGoingGame->getBuilding(8)->get_level() == 1){
			askalert = new AskAlert(onGoingGame, "MarUpgrade1",Screen);
			askalert->setGeometry(QRect(110, 100, 300, 225));
			askalert->show();
		}
		else if(onGoingGame->getBuilding(8)->get_level() == 2){
			askalert = new AskAlert(onGoingGame, "MarUpgrade2",Screen);
			askalert->setGeometry(QRect(110, 100, 300, 225));
			askalert->show();
		}
	}
}

void InMarket::setNormalAlert(QString name){
	if(normalalert != NULL)
		return;
	else{
		normalalert = new NormalAlert(onGoingGame, name, "Mar" ,Screen);
		normalalert->setGeometry(QRect(110, 150, 300, 150));
		normalalert->show();
	}
}

void InMarket::DeleteNormalAlert(){
	if(normalalert != NULL)
		delete normalalert;

	normalalert = NULL;
}

void InMarket::DeleteAskAlert(){
	if(askalert != NULL)
		delete askalert;

	askalert = NULL;
}

void InMarket::ReDraw(){
		QPixmap Image;
		if(onGoingGame->getBuilding(8)->get_level()==1)
		{
			Image.load(QString::fromUtf8("Resources/Market1.png")); // 체력회복량까지
		}
		else if(onGoingGame->getBuilding(8)->get_level()==2)
		{
			Image.load(QString::fromUtf8("Resources/Market2.png"));
		}
		else if(onGoingGame->getBuilding(8)->get_level()==3)
		{
			Image.load(QString::fromUtf8("Resources/Market3.png"));
		}
		Screen->setPixmap(Image);

		if(onGoingGame->getBuilding(8)->get_level() >= 2){
			QIcon CcornerImage;
			CcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/Drink2_activated.png")), QIcon::Normal, QIcon::Off);
			Drink2_Button->setGeometry(QRect(100, 235, 112, 45));
			Drink2_Button->setIcon(CcornerImage);
			QObject::connect(Drink2_Button, SIGNAL(clicked()), this, SLOT(setDrink2Alert()));
		}
		if(onGoingGame->getBuilding(8)->get_level() == 3){
			QIcon DcornerImage;
			DcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/Drink3_activated.png")), QIcon::Normal, QIcon::Off);
			Drink3_Button->setGeometry(QRect(100, 284, 112, 45));
			Drink3_Button->setIcon(DcornerImage);
			QObject::connect(Drink3_Button, SIGNAL(clicked()), this, SLOT(setDrink3Alert()));
		}

		repaint();
}

void InMarket::setDrink1Alert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Drink1" ,Screen);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void InMarket::setDrink2Alert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Drink2" ,Screen);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void InMarket::setDrink3Alert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Drink3" ,Screen);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}