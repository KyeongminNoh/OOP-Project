#include "InLabor.h"
#include "Map.h"
#include "ManageGame.h"
#include "Building.h"
#include "AskAlert.h"
#include "NormalAlert.h"

InLabor::InLabor(ManageGame *Game, QWidget *parent) : QWidget(parent){

	onGoingGame = Game;
	resize(660, 450);
	QPixmap Image;
	
	askalert = NULL;
	normalalert = NULL;
	
		if(onGoingGame->getBuilding(4)->get_level()==1)
		{
			Image.load(QString::fromUtf8("Resources/Labor1.png")); // 체력회복량까지
		}
		else if(onGoingGame->getBuilding(4)->get_level()==2)
		{
			Image.load(QString::fromUtf8("Resources/Labor2.png"));
		}
		else if(onGoingGame->getBuilding(4)->get_level()==3)
		{
			Image.load(QString::fromUtf8("Resources/Labor3.png"));
		}
		Screen = new QLabel(this);
		Screen->setScaledContents(true);
		Screen->resize(660, 450);
		Screen->setGeometry(QRect(0, 0, 660, 450));
		Screen->setPixmap(Image);
		
		

		QIcon WorkImage;
		WorkImage.addPixmap(QPixmap(QString::fromUtf8("Resources/Work.png")), QIcon::Normal, QIcon::Off);

		QPushButton *WorkButton;
		WorkButton = new QPushButton(Screen);
		WorkButton->setGeometry(QRect(100, 210, 120, 60));
		WorkButton->setIcon(WorkImage);
		WorkButton->setIconSize(QSize(120, 60));
		WorkButton->setFlat(true);

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

		QObject::connect(WorkButton, SIGNAL(clicked()), this, SLOT(setWorkAlert()));
		QObject::connect(UpgradeButton, SIGNAL(clicked()), this, SLOT(setLabor_Upgrade_Alert()));
		QObject::connect(BackButton,SIGNAL(clicked()), onGoingGame, SLOT(BACKalert()));

	
}

void InLabor::setWorkAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Work",Screen);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void InLabor::setLabor_Upgrade_Alert(){
	if(askalert !=NULL)
		return;
	else{
		if(onGoingGame->getBuilding(4)->get_level() == 1){
			askalert = new AskAlert(onGoingGame, "LabUpgrade1",Screen);
			askalert->setGeometry(QRect(110, 100, 300, 225));
			askalert->show();
		}

		else if(onGoingGame->getBuilding(4)->get_level() == 2){
			askalert = new AskAlert(onGoingGame, "LabUpgrade2",Screen);
			askalert->setGeometry(QRect(110, 100, 300, 225));
			askalert->show();
		}
	}
}

void InLabor::setNormalAlert(QString name){
	if(normalalert != NULL)
		return;
	else{
		normalalert = new NormalAlert(onGoingGame, name, "Lab" ,Screen);
		normalalert->setGeometry(QRect(110, 150, 300, 150));
		normalalert->show();
	}
}

void InLabor::DeleteNormalAlert(){
	if(normalalert != NULL)
		delete normalalert;

	normalalert = NULL;
}

void InLabor::DeleteAskAlert(){
	if(askalert != NULL)
		delete askalert;
	askalert = NULL;
}

void InLabor::ReDraw(){
		QPixmap Image;
		if(onGoingGame->getBuilding(4)->get_level()==1)
		{
			Image.load(QString::fromUtf8("Resources/Labor1.png")); // 체력회복량까지
		}
		else if(onGoingGame->getBuilding(4)->get_level()==2)
		{
			Image.load(QString::fromUtf8("Resources/Labor2.png"));
		}
		else if(onGoingGame->getBuilding(4)->get_level()==3)
		{
			Image.load(QString::fromUtf8("Resources/Labor3.png"));
		}
		Screen->setPixmap(Image);
		repaint();
}