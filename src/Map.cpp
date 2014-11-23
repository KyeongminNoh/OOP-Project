#include "Map.h"
#include "ManageGame.h"
#include "AskAlert.h"
#include "NormalAlert.h"
#include <QMouseEvent>
#include <QTimer>

Map::Map(QWidget *parent) : QWidget(parent){
	x =320;
	y =350;
	
	px = 1;
	py = 1;


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

	nowPlayer = new QLabel(nowEnvironment);
	nowPlayer->setScaledContents(true);
	nowPlayer->setGeometry(QRect(320, 350, 40, 80));
	QPixmap PlayerImage;
	PlayerImage.load(QString::fromUtf8("Resources/Player.png"));
	nowPlayer->setPixmap(PlayerImage);
	nowPlayer->show();



	DormitoryImage = new QPushButton(nowEnvironment);
	//DormitoryImage->setScaledContents(true);
	DormitoryImage->setGeometry(QRect(250,0,110,110));
	QIcon IDormitory;
    IDormitory.addPixmap(QPixmap(QString::fromUtf8("Resources/Dormitory.png")), QIcon::Normal, QIcon::Off);
    DormitoryImage->setIcon(IDormitory);
	DormitoryImage->setIconSize(QSize(110, 110));
	DormitoryImage->setFlat(true);
	DormitoryImage->show();

	EngineeringImage = new QPushButton(nowEnvironment);
	//EngineeringImage->setScaledContents(true);
	EngineeringImage->setGeometry(QRect(10,80,110,110));
	QIcon IEngineering;
    IEngineering.addPixmap(QPixmap(QString::fromUtf8("Resources/Engineering.png")), QIcon::Normal, QIcon::Off);
    EngineeringImage->setIcon(IEngineering);
	EngineeringImage->setIconSize(QSize(110, 110));
	EngineeringImage->setFlat(true);
	EngineeringImage->show();

	CafeteriaImage = new QPushButton(nowEnvironment);
	//CafeteriaImage->setScaledContents(true);
	CafeteriaImage->setGeometry(QRect(500,290,110,110));
	QIcon ICafeteria;
    ICafeteria.addPixmap(QPixmap(QString::fromUtf8("Resources/Cafeteria.png")), QIcon::Normal, QIcon::Off);
    CafeteriaImage->setIcon(ICafeteria);
	CafeteriaImage->setIconSize(QSize(110, 110));
	CafeteriaImage->setFlat(true);
	CafeteriaImage->show();

	QObject::connect(EngineeringImage, SIGNAL(clicked()), SLOT(MoveToEngineering()));
	QObject::connect(CafeteriaImage, SIGNAL(clicked()), SLOT(MoveToCafeteria()));
	

}


void Map::createGymImage(int level){
	GymImage = new QPushButton(nowEnvironment);
	//GymImage->setScaledContents(true);
	GymImage->setGeometry(QRect(400,30,100,100));
	QIcon IGym;
    IGym.addPixmap(QPixmap(QString::fromUtf8("Resources/Gym.png")), QIcon::Normal, QIcon::Off);
    GymImage->setIcon(IGym);
	GymImage->setIconSize(QSize(100, 100));
	GymImage->setFlat(true);
	GymImage->show();

	QObject::connect(GymImage, SIGNAL(clicked()), SLOT(MoveToGym()));
}

void Map::createLaborBuilding(int level){
	LaborBuildingImage = new QPushButton(nowEnvironment);
	//LaborBuildingImage->setScaledContents(true);
	LaborBuildingImage->setGeometry(QRect(530,180,100,100));
	QIcon ILaborBuilding;
    ILaborBuilding.addPixmap(QPixmap(QString::fromUtf8("Resources/LaborBuilding.png")), QIcon::Normal, QIcon::Off);
    LaborBuildingImage->setIcon(ILaborBuilding);
	LaborBuildingImage->setIconSize(QSize(100, 100));
	LaborBuildingImage->setFlat(true);
	LaborBuildingImage->show();
}

void Map::createStudentHall(int level){
	StudentHallImage = new QPushButton(nowEnvironment);
	//StudentHallImage->setScaledContents(true);
	StudentHallImage->setGeometry(QRect(130,20,100,100));
	QIcon IStudentHall;
    IStudentHall.addPixmap(QPixmap(QString::fromUtf8("Resources/StudentHall.png")), QIcon::Normal, QIcon::Off);
    StudentHallImage->setIcon(IStudentHall);
	StudentHallImage->setIconSize(QSize(100, 100));
	StudentHallImage->setFlat(true);
	StudentHallImage->show();
}


void Map::createLogHouseImage(int level){
	LogHouseImage = new QPushButton(nowEnvironment);
	//LogHouseImage->setScaledContents(true);
	LogHouseImage->setGeometry(QRect(520,70,100,100));
	QIcon ILogHouse;
    ILogHouse.addPixmap(QPixmap(QString::fromUtf8("Resources/LogHouse.png")), QIcon::Normal, QIcon::Off);
    LogHouseImage->setIcon(ILogHouse);
	LogHouseImage->setIconSize(QSize(100, 100));
	LogHouseImage->setFlat(true);
	LogHouseImage->show();
}

void Map::createLibraryImage(int level){
	LibraryImage = new QPushButton(nowEnvironment);
	//LibraryImage->setScaledContents(true);
	LibraryImage->setGeometry(QRect(10,190,100,100));
	QIcon ILibrary;
    ILibrary.addPixmap(QPixmap(QString::fromUtf8("Resources/Library.png")), QIcon::Normal, QIcon::Off);
    LibraryImage->setIcon(ILibrary);
	LibraryImage->setIconSize(QSize(100, 100));
	LibraryImage->setFlat(true);
	LibraryImage->show();
}

void Map::createMarketImage(int level){
	MarketImage = new QPushButton(nowEnvironment);
	//MarketImage->setScaledContents(true);
	MarketImage->setGeometry(QRect(30,440,100,100));
	QIcon IMarket;
    IMarket.addPixmap(QPixmap(QString::fromUtf8("Resources/Market.png")), QIcon::Normal, QIcon::Off);
    MarketImage->setIcon(IMarket);
	MarketImage->setIconSize(QSize(100, 100));
	MarketImage->setFlat(true);
	MarketImage->show();
}

void Map::setGym_Upgrade_Alert()
{
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "GymUpgrade",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 300));
		askalert->show();
	}
}
void Map::setExerAlert()
{
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Exer",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 300));
		askalert->show();
	}
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

void Map::MovePlayer(){
	x -= px;
	y -= py;

	nowPlayer->setGeometry(QRect(x, y, 40, 80));
	repaint();
}

void Map::MoveToEngineering(){
	px = 1.2;
	py = 1;


	QTimer *Timer;
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(2000, Timer, SLOT(stop()));
	Timer->start(10);
}


void Map::MoveToCafeteria(){
	px = -1;
	py = 0.3;
	
	QTimer *Timer;
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(1000, Timer, SLOT(stop()));
	Timer->start(5);
}

void Map::MoveToGym(){
	px = -0.8;
	py = 1.7;
	
	QTimer *Timer;
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(1000, Timer, SLOT(stop()));
	Timer->start(5);
}
