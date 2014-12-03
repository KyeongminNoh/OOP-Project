#include "Map.h"
#include "ManageGame.h"
#include "AskAlert.h"
#include "NormalAlert.h"
#include "InGym.h"
#include "InDormitory.h"
#include "InCafeteria.h"
#include "InMarket.h"
#include "InLogHouse.h"
#include "InStudentHall.h"
#include "InEngineering.h"
#include "Player.h"
#include "Semester.h"
#include "TestAssn.h"
#include <QMouseEvent>
#include <QTimer>

Map::Map(bool Man, QWidget *parent) : QWidget(parent){
	x =320;
	y =350;
	
	px = 1;
	py = 1;
	nowActing = false;
	nowSemester = new Semester();

	incafeteria = NULL;
	Inbuildingalert = NULL;
	inmarket = NULL;
	inloghouse = NULL;
	instudenthall = NULL;


	askalert = NULL;
	normalalert = NULL;

	nowEnvironment = new QLabel(this);
	nowEnvironment->resize(660, 450);


	nowEnvironment->show();

	QString SN;
	SN.setNum(nowSemester->get_CurrentSemester());
	QByteArray Session;
	Session.append("Resources/Session");
	Session.append(SN);
	Session.append(".png");

	Session1 = new QLabel(nowEnvironment);
	Session1->setScaledContents(true);
	Session1->setGeometry(QRect(550, 10, 100, 45));
	QPixmap SImage;
	SImage.load(QString::fromUtf8(Session));
	Session1->setPixmap(SImage);
	Session1->show();

	nowPlayer = new QLabel(nowEnvironment);
	nowPlayer->setScaledContents(true);
	nowPlayer->setGeometry(QRect(320, 350, 40, 80));
	QPixmap PlayerImage;
	if(Man == true)
		PlayerImage.load(QString::fromUtf8("Resources/Player.png"));
	else
		PlayerImage.load(QString::fromUtf8("Resources/Woman.png"));
	nowPlayer->setPixmap(PlayerImage);
	nowPlayer->show();

	
	QPushButton *Reset;
	Reset = new QPushButton(nowEnvironment);
	Reset->setText("Reset!");
	Reset->setGeometry(QRect(0, 0, 40, 30));
	Reset->show();


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
	QObject::connect(DormitoryImage, SIGNAL(clicked()), SLOT(MoveToDormitory()));
	QObject::connect(Reset, SIGNAL(clicked()), SLOT(ResetPlayer()));

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

	QObject::connect(LaborBuildingImage, SIGNAL(clicked()), SLOT(MoveToLaborBuilding()));
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
	QObject::connect(StudentHallImage, SIGNAL(clicked()), SLOT(MoveToStudentHall()));
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
	QObject::connect(LogHouseImage, SIGNAL(clicked()), SLOT(MoveToLogHouse()));
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
	QObject::connect(LibraryImage, SIGNAL(clicked()), SLOT(MoveToLibrary()));
}

void Map::createMarketImage(int level){
	MarketImage = new QPushButton(nowEnvironment);
	//MarketImage->setScaledContents(true);
	MarketImage->setGeometry(QRect(30,340,100,100));
	QIcon IMarket;
    IMarket.addPixmap(QPixmap(QString::fromUtf8("Resources/Market.png")), QIcon::Normal, QIcon::Off);
    MarketImage->setIcon(IMarket);
	MarketImage->setIconSize(QSize(100, 100));
	MarketImage->setFlat(true);
	MarketImage->show();
	QObject::connect(MarketImage, SIGNAL(clicked()), SLOT(MoveToMarket()));
}

void Map::setGym_Upgrade_Alert()
{
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "GymUpgrade",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}
void Map::setExerAlert()
{
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Exer",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void Map::setGymAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Gym",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}

}

void Map::setLibAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Lib",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void Map::setLabAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Lab",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void Map::setLogAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Log",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void Map::setStuAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Stu",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void Map::setMarAlert(){
	if(askalert != NULL)
		return;
	else{
		askalert = new AskAlert(onGoingGame, "Mar",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void Map::setNormalAlert(QString name){
	if(normalalert != NULL)
		return;
	else{
		normalalert = new NormalAlert(onGoingGame, name, "map", nowEnvironment);
		normalalert->setGeometry(QRect(110, 150, 300, 150));
		if(name == "Sleep" || name == "CTSleep"){
			normalalert->setGeometry(QRect(0, 0, 660, 450));
		}
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

void Map::DeleteInBldg()
{
	delete Inbuildingalert;
	Inbuildingalert = NULL;
	delete incafeteria;
	incafeteria = NULL;
	delete inmarket;
	inmarket = NULL;
	delete inloghouse;
	inloghouse  = NULL;
	delete instudenthall;
	instudenthall = NULL;
	ResetPlayer();
}

void Map::DeleteInDormitory()
{
	delete indormitory;
	indormitory = NULL;
	ResetPlayer();
}

void Map::DeleteInEngineering()
{
	delete inengineering;
	inengineering = NULL;
	ResetPlayer();
}

void Map::DeleteTA(){
	
	delete TA;
	TA = NULL;

	delete Screen;
	Screen = NULL;

	nowActing = false;
};

void Map::setManageGame(ManageGame *Game){
	onGoingGame = Game;
}

void Map::ResetPlayer(){
	x =320;
	y =350;

	nowPlayer->setGeometry(QRect(x, y, 40, 80));
	repaint();
}

void Map::MovePlayer(){
	x -= px;
	y -= py;

	nowPlayer->setGeometry(QRect(x, y, 40, 80));
	repaint();
}

void Map::MoveToEngineering(){
	px = 5.77;
	py = 5.77;

	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(1300, this, SLOT(DeleteTimer()));
	QTimer::singleShot(1350, this, SLOT(setInEngineering()));
	Timer->start(20);
}

void Map::MoveToCafeteria(){
	px = -6.4;
	py = 2;
	
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(800, this, SLOT(DeleteTimer()));
	QTimer::singleShot(850, this, SLOT(setInCafeteria()));
	Timer->start(20);
}

void Map::MoveToGym(){

	px = -3.5;
	py = 7.5;
	
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));


	QTimer::singleShot(1000, this, SLOT(DeleteTimer()));
	QTimer::singleShot(1050, this, SLOT(setInGym()));
	Timer->start(30);
}

void Map::MoveToLaborBuilding(){
	px = -5.5;
	py = 5.05;
	
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(1000, this, SLOT(DeleteTimer()));
	
	Timer->start(30);
}

void Map::DeleteTimer(){
	delete Timer;
	px = 0;
	py = 0;
}

void Map::MoveToDormitory(){
	px = 0.9;
	py = 7;
	
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(1200, this, SLOT(DeleteTimer()));
	QTimer::singleShot(1250, this, SLOT(setInDormitory()));
	Timer->start(30);
}

void Map::MoveToStudentHall(){
	px = 3;
	py = 6.5;
	
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(1200, this, SLOT(DeleteTimer()));
		QTimer::singleShot(1250, this, SLOT(setInStudentHall()));
	Timer->start(30);
}

void Map::MoveToLogHouse(){
	px = -5.5;
	py = 7.3;
	
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
//	if(Inbuildingalert != NULL)
//		return;
//	else{

//	}
	QTimer::singleShot(1000, this, SLOT(DeleteTimer()));
	QTimer::singleShot(1050, this, SLOT(setInLogHouse()));
	Timer->start(30);
}

void Map::MoveToLibrary(){
	px = 7;
	py = 4.7;
	
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(1000, this, SLOT(DeleteTimer()));
	Timer->start(30);
}

void Map::MoveToMarket(){

	px = 6;
	py = -0.5;
	
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));


	QTimer::singleShot(1000, this, SLOT(DeleteTimer()));
	QTimer::singleShot(1050, this, SLOT(setInMarket()));
	Timer->start(30);
}


void Map::setInGym(){
	Inbuildingalert = new InGym(onGoingGame, nowEnvironment);
	Inbuildingalert->setGeometry(QRect(0, 0, 660, 450));
	Inbuildingalert->show();

}

InGym* Map::getInGym(){
	return Inbuildingalert;
}

InCafeteria* Map::getInCafeteria(){
	return incafeteria;
}

InMarket* Map::getInMarket(){
	return inmarket;
}

InLogHouse* Map::getInLogHouse(){
	return inloghouse;
}

InStudentHall* Map::getInStudentHall(){
	return instudenthall;
}

void Map::setInDormitory(){
	indormitory = new InDormitory(onGoingGame, nowEnvironment);
	indormitory->setGeometry(QRect(0, 0, 660, 450));
	indormitory->show();

}

void Map::setInEngineering(){
	inengineering = new InEngineering(onGoingGame, nowEnvironment);
	inengineering->setGeometry(QRect(0, 0, 660, 450));
	inengineering->show();
}

void Map::setInCafeteria(){
	incafeteria = new InCafeteria(onGoingGame, nowEnvironment);
	incafeteria->setGeometry(QRect(0,0,660, 450));
	incafeteria->show();
}

void Map::setInMarket(){
	inmarket = new InMarket(onGoingGame, nowEnvironment);
	inmarket->setGeometry(QRect(0,0,660, 450));
	inmarket->show();
}

void Map::setInLogHouse(){
	inloghouse = new InLogHouse(onGoingGame, nowEnvironment);
	inloghouse->setGeometry(QRect(0,0,660, 450));
	inloghouse->show();
}

void Map::setInStudentHall(){
	instudenthall = new InStudentHall(onGoingGame, nowEnvironment);
	instudenthall->setGeometry(QRect(0,0,660, 450));
	instudenthall->show();
}

void Map::setTA(){
	if(!nowActing){

		QPixmap BImage;
		BImage.load(QString::fromUtf8("Resources/White.png"));
		Screen = new QLabel(nowEnvironment);
		Screen->setScaledContents(true);
		Screen->setGeometry(QRect(0, 0, 660, 450));
		Screen->setPixmap(BImage);
		Screen->show();
		TA = new TestAssn(onGoingGame, Screen);
		TA->setGeometry(QRect(0, 0, 660, 450));
		TA->show();
		nowActing = true;
	}
	return;
}

TestAssn* Map::getTA(){
	return TA;
}