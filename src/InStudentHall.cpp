#include "InStudentHall.h"
#include "Map.h"
#include "ManageGame.h"
#include "Building.h"
#include "AskAlert.h"
#include "NormalAlert.h"

InStudentHall::InStudentHall(ManageGame *Game, QWidget *parent) : QWidget(parent){

	onGoingGame = Game;
	resize(660, 450);
	QPixmap Image;
	
	askalert = NULL;
	normalalert = NULL;
	
		if(onGoingGame->getBuilding(5)->get_level()==1)
		{
			Image.load(QString::fromUtf8("Resources/StuHall1.png")); // 체력회복량까지
		}
		else if(onGoingGame->getBuilding(5)->get_level()==2)
		{
			Image.load(QString::fromUtf8("Resources/StuHall2.png"));
		}
		else if(onGoingGame->getBuilding(5)->get_level()==3)
		{
			Image.load(QString::fromUtf8("Resources/StuHall3.png"));
		}
		Screen = new QLabel(this);
		Screen->setScaledContents(true);
		Screen->resize(660, 450);
		Screen->setGeometry(QRect(0, 0, 660, 450));
		Screen->setPixmap(Image);
		
		
		

		QIcon BcornerImage;
		BcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/clubA_activated.png")), QIcon::Normal, QIcon::Off);
		QIcon CcornerImage;
		CcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/clubB.png")), QIcon::Normal, QIcon::Off);
		QIcon DcornerImage;
		DcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/clubC.png")), QIcon::Normal, QIcon::Off);

		clubA_Button = new QPushButton(Screen);
		clubA_Button->setGeometry(QRect(100, 185, 112, 45));
		clubA_Button->setIcon(BcornerImage);
		clubA_Button->setIconSize(QSize(100, 40));
		clubA_Button->setFlat(true);

		clubB_Button = new QPushButton(Screen);
		clubB_Button->setGeometry(QRect(106, 235, 100, 40));
		clubB_Button->setIcon(CcornerImage);
		clubB_Button->setIconSize(QSize(100, 40));
		clubB_Button->setFlat(true);

		clubC_Button = new QPushButton(Screen);
		clubC_Button->setGeometry(QRect(106, 285, 100, 40));
		clubC_Button->setIcon(DcornerImage);
		clubC_Button->setIconSize(QSize(100, 40));
		clubC_Button->setFlat(true);

		if(onGoingGame->getBuilding(5)->get_level() >= 2){
			
			CcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/clubB_activated.png")), QIcon::Normal, QIcon::Off);
			clubB_Button->setGeometry(QRect(100, 235, 112, 45));
			clubB_Button->setIcon(CcornerImage);
			QObject::connect(clubB_Button, SIGNAL(clicked()), this, SLOT(setclubBAlert()));
		}
		if(onGoingGame->getBuilding(5)->get_level() == 3){
			DcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/clubC_activated.png")), QIcon::Normal, QIcon::Off);
			clubC_Button->setGeometry(QRect(100, 284, 112, 45));
			clubC_Button->setIcon(DcornerImage);
			QObject::connect(clubC_Button, SIGNAL(clicked()), this, SLOT(setclubCAlert()));
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

		QObject::connect(clubA_Button, SIGNAL(clicked()), this, SLOT(setclubAAlert()));

			
		QObject::connect(UpgradeButton, SIGNAL(clicked()), this, SLOT(setMar_Upgrade_Alert()));
		QObject::connect(BackButton,SIGNAL(clicked()), onGoingGame, SLOT(BACKalert()));

	
}


void InStudentHall::setMar_Upgrade_Alert(){
	if(askalert !=NULL)
		return;
	else{
		if(onGoingGame->getBuilding(5)->get_level() == 1){
			askalert = new AskAlert(onGoingGame, "StuUpgrade1",Screen);
			askalert->setGeometry(QRect(110, 100, 300, 225));
			askalert->show();
		}
		else if(onGoingGame->getBuilding(5)->get_level() == 2){
			askalert = new AskAlert(onGoingGame, "StuUpgrade2",Screen);
			askalert->setGeometry(QRect(110, 100, 300, 225));
			askalert->show();
		}
	}
}

void InStudentHall::setNormalAlert(QString name){
	if(normalalert != NULL)
		return;
	else{
		normalalert = new NormalAlert(onGoingGame, name, "Stu" ,Screen);
		normalalert->setGeometry(QRect(110, 150, 300, 150));
		normalalert->show();
	}
}

void InStudentHall::DeleteNormalAlert(){
	if(normalalert != NULL)
		delete normalalert;

	normalalert = NULL;
}

void InStudentHall::DeleteAskAlert(){
	if(askalert != NULL)
		delete askalert;

	askalert = NULL;
}

void InStudentHall::ReDraw(){
		QPixmap Image;
		if(onGoingGame->getBuilding(5)->get_level()==1)
		{
			Image.load(QString::fromUtf8("Resources/StutHall1.png")); // 체력회복량까지
		}
		else if(onGoingGame->getBuilding(5)->get_level()==2)
		{
			Image.load(QString::fromUtf8("Resources/StuHall2.png"));
		}
		else if(onGoingGame->getBuilding(5)->get_level()==3)
		{
			Image.load(QString::fromUtf8("Resources/StuHall3.png"));
		}
		Screen->setPixmap(Image);

		if(onGoingGame->getBuilding(5)->get_level() >= 2){
			QIcon CcornerImage;
			CcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/clubB_activated.png")), QIcon::Normal, QIcon::Off);
			clubB_Button->setGeometry(QRect(100, 235, 112, 45));
			clubB_Button->setIcon(CcornerImage);
			QObject::connect(clubB_Button, SIGNAL(clicked()), this, SLOT(setclubBAlert()));
		}
		if(onGoingGame->getBuilding(5)->get_level() == 3){
			QIcon DcornerImage;
			DcornerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/clubC_activated.png")), QIcon::Normal, QIcon::Off);
			clubC_Button->setGeometry(QRect(100, 284, 112, 45));
			clubC_Button->setIcon(DcornerImage);
			QObject::connect(clubC_Button, SIGNAL(clicked()), this, SLOT(setclubCAlert()));
		}

		repaint();
}

void InStudentHall::setclubAAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "clubA" ,Screen);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void InStudentHall::setclubBAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "clubB" ,Screen);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void InStudentHall::setclubCAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "clubC" ,Screen);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}