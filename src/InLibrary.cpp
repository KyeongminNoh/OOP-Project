#include "InLibrary.h"
#include "Map.h"
#include "ManageGame.h"
#include "Building.h"
#include "AskAlert.h"
#include "NormalAlert.h"

InLibrary::InLibrary(ManageGame *Game, QWidget *parent) : QWidget(parent){

	onGoingGame = Game;
	resize(660, 450);
	QPixmap Image;
	
	askalert = NULL;
	normalalert = NULL;
	
		if(onGoingGame->getBuilding(6)->get_level()==1)
		{
			Image.load(QString::fromUtf8("Resources/Library1.png")); // 체력회복량까지
		}
		else if(onGoingGame->getBuilding(6)->get_level()==2)
		{
			Image.load(QString::fromUtf8("Resources/Library2.png"));
		}
		else if(onGoingGame->getBuilding(6)->get_level()==3)
		{
			Image.load(QString::fromUtf8("Resources/Library3.png"));
		}
		Screen = new QLabel(this);
		Screen->setScaledContents(true);
		Screen->resize(660, 450);
		Screen->setGeometry(QRect(0, 0, 660, 450));
		Screen->setPixmap(Image);
		
		

		QIcon StudyImage;
		StudyImage.addPixmap(QPixmap(QString::fromUtf8("Resources/Study.png")), QIcon::Normal, QIcon::Off);

		QPushButton *StudyButton;
		StudyButton = new QPushButton(Screen);
		StudyButton->setGeometry(QRect(100, 210, 120, 60));
		StudyButton->setIcon(StudyImage);
		StudyButton->setIconSize(QSize(120, 60));
		StudyButton->setFlat(true);

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

		QObject::connect(StudyButton, SIGNAL(clicked()), this, SLOT(setStudyAlert()));
		QObject::connect(UpgradeButton, SIGNAL(clicked()), this, SLOT(setLibrary_Upgrade_Alert()));
		QObject::connect(BackButton,SIGNAL(clicked()), onGoingGame, SLOT(BACKalert()));

	
}

void InLibrary::setStudyAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Study",Screen);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void InLibrary::setLibrary_Upgrade_Alert(){
	if(askalert !=NULL)
		return;
	else{
		if(onGoingGame->getBuilding(6)->get_level() == 1){
			askalert = new AskAlert(onGoingGame, "LibUpgrade1",Screen);
			askalert->setGeometry(QRect(110, 100, 300, 225));
			askalert->show();
		}

		else if(onGoingGame->getBuilding(6)->get_level() == 2){
			askalert = new AskAlert(onGoingGame, "LibUpgrade2",Screen);
			askalert->setGeometry(QRect(110, 100, 300, 225));
			askalert->show();
		}
	}
}

void InLibrary::setNormalAlert(QString name){
	if(normalalert != NULL)
		return;
	else{
		normalalert = new NormalAlert(onGoingGame, name, "Lib" ,Screen);
		normalalert->setGeometry(QRect(110, 150, 300, 150));
		normalalert->show();
	}
}

void InLibrary::DeleteNormalAlert(){
	if(normalalert != NULL)
		delete normalalert;

	normalalert = NULL;
}

void InLibrary::DeleteAskAlert(){
	if(askalert != NULL)
		delete askalert;
	askalert = NULL;
}

void InLibrary::ReDraw(){
		QPixmap Image;
		if(onGoingGame->getBuilding(6)->get_level()==1)
		{
			Image.load(QString::fromUtf8("Resources/Library1.png")); // 체력회복량까지
		}
		else if(onGoingGame->getBuilding(6)->get_level()==2)
		{
			Image.load(QString::fromUtf8("Resources/Library2.png"));
		}
		else if(onGoingGame->getBuilding(6)->get_level()==3)
		{
			Image.load(QString::fromUtf8("Resources/Library3.png"));
		}
		Screen->setPixmap(Image);
		repaint();
}