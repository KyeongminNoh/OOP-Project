#include "Map.h"
#include "ManageGame.h"
#include "AskAlert.h"
#include "NormalAlert.h"

Map::Map(QWidget *parent) : QWidget(parent){

	askalert = NULL;
	normalalert = NULL;

	nowEnvironment = new QLabel(this);
	nowEnvironment->resize(660, 450);


	nowEnvironment->show();

	Session1 = new QLabel(nowEnvironment);
	Session1->setScaledContents(true);
	Session1->setGeometry(QRect(550, 10, 100, 45));
	QPixmap SImage;
	SImage.load(QString::fromUtf8("Resources/Session1.png"));
	Session1->setPixmap(SImage);
	Session1->show();

	DormitoryImage = new QLabel(nowEnvironment);
	DormitoryImage->setScaledContents(true);
	DormitoryImage->setGeometry(QRect(250,0,110,110));
	QPixmap IDormitory;
    IDormitory.load(QString::fromUtf8("Resources/Dormitory.png"));
    DormitoryImage->setPixmap(IDormitory);
	DormitoryImage->show();

	EngineeringImage = new QLabel(nowEnvironment);
	EngineeringImage->setScaledContents(true);
	EngineeringImage->setGeometry(QRect(10,80,110,110));
	QPixmap IEngineering;
    IEngineering.load(QString::fromUtf8("Resources/Engineering.png"));
    EngineeringImage->setPixmap(IEngineering);
	EngineeringImage->show();

	CafeteriaImage = new QLabel(nowEnvironment);
	CafeteriaImage->setScaledContents(true);
	CafeteriaImage->setGeometry(QRect(500,290,110,110));
	QPixmap ICafeteria;
    ICafeteria.load(QString::fromUtf8("Resources/Cafeteria.png"));
    CafeteriaImage->setPixmap(ICafeteria);
	CafeteriaImage->show();

}


void Map::createGymImage(int level){
	GymImage = new QLabel(nowEnvironment);
	GymImage->setScaledContents(true);
	GymImage->setGeometry(QRect(400,30,100,100));
	QPixmap IGym;
    IGym.load(QString::fromUtf8("Resources/Gym.png"));
    GymImage->setPixmap(IGym);
	GymImage->show();
}

void Map::createLaborBuilding(int level){
	LaborBuildingImage = new QLabel(nowEnvironment);
	LaborBuildingImage->setScaledContents(true);
	LaborBuildingImage->setGeometry(QRect(530,180,100,100));
	QPixmap ILaborBuilding;
    ILaborBuilding.load(QString::fromUtf8("Resources/LaborBuilding.png"));
    LaborBuildingImage->setPixmap(ILaborBuilding);
	LaborBuildingImage->show();
}

void Map::createStudentHall(int level){
	StudentHallImage = new QLabel(nowEnvironment);
	StudentHallImage->setScaledContents(true);
	StudentHallImage->setGeometry(QRect(130,20,100,100));
	QPixmap IStudentHall;
    IStudentHall.load(QString::fromUtf8("Resources/StudentHall.png"));
    StudentHallImage->setPixmap(IStudentHall);
	StudentHallImage->show();
}


void Map::createLogHouseImage(int level){
	LogHouseImage = new QLabel(nowEnvironment);
	LogHouseImage->setScaledContents(true);
	LogHouseImage->setGeometry(QRect(520,70,100,100));
	QPixmap ILogHouse;
    ILogHouse.load(QString::fromUtf8("Resources/LogHouse.png"));
    LogHouseImage->setPixmap(ILogHouse);
	LogHouseImage->show();
}

void Map::createLibraryImage(int level){
	LibraryImage = new QLabel(nowEnvironment);
	LibraryImage->setScaledContents(true);
	LibraryImage->setGeometry(QRect(10,190,100,100));
	QPixmap ILibrary;
    ILibrary.load(QString::fromUtf8("Resources/Library.png"));
    LibraryImage->setPixmap(ILibrary);
	LibraryImage->show();
}

void Map::createMarketImage(int level){
	MarketImage = new QLabel(nowEnvironment);
	MarketImage->setScaledContents(true);
	MarketImage->setGeometry(QRect(30,440,100,100));
	QPixmap IMarket;
    IMarket.load(QString::fromUtf8("Resources/Market.png"));
    MarketImage->setPixmap(IMarket);
	MarketImage->show();
}

void Map::setGymAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Gym",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 300));
		askalert->show();
	}

}

void Map::setLibAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Lib",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 300));
		askalert->show();
	}
}

void Map::setLabAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Lab",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 300));
		askalert->show();
	}
}

void Map::setLogAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Log",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 300));
		askalert->show();
	}
}

void Map::setStuAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Stu",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 300));
		askalert->show();
	}
}

void Map::setMarAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Mar",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 300));
		askalert->show();
	}
}

void Map::setNormalAlert(QString name){
	if(normalalert != NULL)
		return;
	else{
		normalalert = new NormalAlert(onGoingGame, name ,nowEnvironment);
		normalalert->setGeometry(QRect(110, 150, 300, 200));
		normalalert->show();
	}
}

void Map::DeleteAskAlert(){
	delete askalert;
	askalert = NULL;
}

void Map::DeleteNormalAlert(){
	delete normalalert;
	normalalert = NULL;
}

void Map::setManageGame(ManageGame *Game){
	onGoingGame = Game;
}