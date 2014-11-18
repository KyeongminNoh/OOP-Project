#include "Map.h"

Map::Map(QWidget *parent) : QWidget(parent){

	nowEnvironment = new QLabel(this);
	nowEnvironment->resize(640, 450);


	nowEnvironment->show();

	DormitoryImage = new QLabel(nowEnvironment);
	DormitoryImage->setScaledContents(true);
	DormitoryImage->setGeometry(QRect(250,40,110,110));
	QPixmap IDormitory;
    IDormitory.load(QString::fromUtf8("Resources/Dormitory.png"));
    DormitoryImage->setPixmap(IDormitory);
	DormitoryImage->show();

	EngineeringImage = new QLabel(nowEnvironment);
	EngineeringImage->setScaledContents(true);
	EngineeringImage->setGeometry(QRect(40,40,110,110));
	QPixmap IEngineering;
    IEngineering.load(QString::fromUtf8("Resources/Engineering.png"));
    EngineeringImage->setPixmap(IEngineering);
	EngineeringImage->show();

	CafeteriaImage = new QLabel(nowEnvironment);
	CafeteriaImage->setScaledContents(true);
	CafeteriaImage->setGeometry(QRect(460,280,110,110));
	QPixmap ICafeteria;
    ICafeteria.load(QString::fromUtf8("Resources/Cafeteria.png"));
    CafeteriaImage->setPixmap(ICafeteria);
	CafeteriaImage->show();

}


void Map::createGymImage(int level){
	GymImage = new QLabel(nowEnvironment);
	GymImage->setScaledContents(true);
	GymImage->setGeometry(QRect(500,150,100,100));
	QPixmap IGym;
    IGym.load(QString::fromUtf8("Resources/Gym.png"));
    GymImage->setPixmap(IGym);
	GymImage->show();
}

void Map::createLaborBuilding(int level){
	LaborBuildingImage = new QLabel(nowEnvironment);
	LaborBuildingImage->setScaledContents(true);
	LaborBuildingImage->setGeometry(QRect(40,300,100,100));
	QPixmap ILaborBuilding;
    ILaborBuilding.load(QString::fromUtf8("Resources/LaborBuilding.png"));
    LaborBuildingImage->setPixmap(ILaborBuilding);
	LaborBuildingImage->show();
}

void Map::createStudentHall(int level){
	StudentHallImage = new QLabel(nowEnvironment);
	StudentHallImage->setScaledContents(true);
	StudentHallImage->setGeometry(QRect(60,160,100,100));
	QPixmap IStudentHall;
    IStudentHall.load(QString::fromUtf8("Resources/StudentHall.png"));
    StudentHallImage->setPixmap(IStudentHall);
	StudentHallImage->show();
}


void Map::createLogHouseImage(int level){
	LogHouseImage = new QLabel(nowEnvironment);
	LogHouseImage->setScaledContents(true);
	LogHouseImage->setGeometry(QRect(240,360,100,100));
	QPixmap ILogHouse;
    ILogHouse.load(QString::fromUtf8("Resources/LogHouse.png"));
    LogHouseImage->setPixmap(ILogHouse);
	LogHouseImage->show();
}

void Map::createLibraryImage(int level){
	LibraryImage = new QLabel(nowEnvironment);
	LibraryImage->setScaledContents(true);
	LibraryImage->setGeometry(QRect(500,150,100,100));
	QPixmap ILibrary;
    ILibrary.load(QString::fromUtf8("Resources/Library.png"));
    LibraryImage->setPixmap(ILibrary);
	LibraryImage->show();
}

void Map::createMarketImage(int level){
	MarketImage = new QLabel(nowEnvironment);
	MarketImage->setScaledContents(true);
	MarketImage->setGeometry(QRect(500,150,100,100));
	QPixmap IMarket;
    IMarket.load(QString::fromUtf8("Resources/Market.png"));
    MarketImage->setPixmap(IMarket);
	MarketImage->show();
}