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
#include "InLibrary.h"
#include "InLabor.h"
#include "Player.h"
#include "Semester.h"
#include "TestAssn.h"
#include "FriendList.h"
#include "EndAlert.h"
#include "GradeReport.h"
#include <QMouseEvent>
#include <QTimer>
#include <time.h>
#include <stdlib.h>

Map::Map(bool Man, FieldScene* Field ,int isSemester, QWidget *parent) : QWidget(parent){
	x =320;
	y =350;
	
	px = 1;
	py = 1;

	field = Field;

	nowActing = false;
	nowSemester = new Semester();
	nowSemester->set_CurrentSemester(isSemester);


	Friend = NULL;
	FriendType = 0;

	incafeteria = NULL;
	Inbuildingalert = NULL;
	inmarket = NULL;
	inloghouse = NULL;
	instudenthall = NULL;
	inlibrary = NULL;
	inlabor = NULL;

	askalert = NULL;
	normalalert = NULL;
	endalert = NULL;

	nowEnvironment = new QLabel(this);
	nowEnvironment->resize(660, 450);
	SetScreen(0);
	nowEnvironment->setScaledContents(true);
	nowEnvironment->setGeometry(QRect(0, 0, 660, 450));
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

	Home = new QPushButton(nowEnvironment);
	QIcon IHome;
    IHome.addPixmap(QPixmap(QString::fromUtf8("Resources/Home.png")), QIcon::Normal, QIcon::Off);
	Home->setIcon(IHome);
	Home->setGeometry(QRect(620, 60, 30, 30));
	Home->setIconSize(QSize(30, 30));
	Home->setFlat(true);
	Home->show();

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
	QObject::connect(Home, SIGNAL(clicked()), SLOT(setAskBack()));

}
void Map::SetScreen(bool isNight){
	QPixmap DayOrNight;
	if(isNight)
		DayOrNight.load(QString::fromUtf8("Resources/black.png"));
	else
		DayOrNight.load(QString::fromUtf8("Resources/white.png"));
	nowEnvironment->setPixmap(DayOrNight);
	nowEnvironment->show();
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
		if(endalert!=NULL){
			delete endalert;
			endalert = NULL;
		}
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
		if(endalert!=NULL){
			delete endalert;
			endalert = NULL;
		}
		askalert = new AskAlert(onGoingGame, "Exer",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void Map::setGymAlert(){
	if(askalert != NULL)
		return;
	else{
		if(endalert!=NULL){
			delete endalert;
			endalert = NULL;
		}
		askalert = new AskAlert(onGoingGame, "Gym",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}

}

void Map::setLib_Upgrade_Alert()
{
	if(askalert != NULL)
		return;
	else{
		if(endalert!=NULL){
			delete endalert;
			endalert = NULL;
		}
		askalert = new AskAlert(onGoingGame, "LibUpgrade",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}
void Map::setStudyAlert()
{
	if(askalert != NULL)
		return;
	else{
		if(endalert!=NULL){
			delete endalert;
			endalert = NULL;
		}
		askalert = new AskAlert(onGoingGame, "Study",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}
void Map::setLibAlert(){
	if(askalert != NULL)
		return;
	else{
		if(endalert!=NULL){
			delete endalert;
			endalert = NULL;
		}
		askalert = new AskAlert(onGoingGame, "Lib",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void Map::setLab_Upgrade_Alert()
{
	if(askalert != NULL)
		return;
	else{
		if(endalert!=NULL){
			delete endalert;
			endalert = NULL;
		}
		askalert = new AskAlert(onGoingGame, "LabUpgrade",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}
void Map::setWorkAlert()
{
	if(askalert != NULL)
		return;
	else{
		if(endalert!=NULL){
			delete endalert;
			endalert = NULL;
		}
		askalert = new AskAlert(onGoingGame, "Work",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}
void Map::setLabAlert(){
	if(askalert != NULL)
		return;
	else{
		if(endalert!=NULL){
			delete endalert;
			endalert = NULL;
		}
		askalert = new AskAlert(onGoingGame, "Lab",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void Map::setLogAlert(){
	if(askalert != NULL)
		return;
	else{
		if(endalert!=NULL){
			delete endalert;
			endalert = NULL;
		}
		askalert = new AskAlert(onGoingGame, "Log",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void Map::setStuAlert(){
	if(askalert != NULL)
		return;
	else{
		if(endalert!=NULL){
			delete endalert;
			endalert = NULL;
		}
		askalert = new AskAlert(onGoingGame, "Stu",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void Map::setMarAlert(){
	if(askalert != NULL)
		return;
	else{
		if(endalert!=NULL){
			delete endalert;
			endalert = NULL;
		}
		askalert = new AskAlert(onGoingGame, "Mar",nowEnvironment);
		askalert->setGeometry(QRect(110, 100, 300, 225));
		askalert->show();
	}
}

void Map::setNormalAlert(QString name){

	if(normalalert != NULL)
		delete normalalert;

	normalalert = new NormalAlert(onGoingGame, name, "map", nowEnvironment);
	normalalert->setGeometry(QRect(110, 150, 300, 150));
	if(name == "Sleep" || name == "CTSleep"){
		normalalert->setGeometry(QRect(0, 0, 660, 450));
	}

	normalalert->show();
	
}

void Map::setEndAlert(QString name){

	if(normalalert != NULL)
		delete normalalert;

	endalert = new EndAlert(field, name, nowEnvironment);
	endalert->setGeometry(QRect(110, 150, 300, 225));

	endalert->show();
	
}

void Map::DeleteAskAlert(){
	delete askalert;
	askalert = NULL;
	if(Friend != NULL)
		Friend->show();

	nowActing = false;
	ResetPlayer();
}

void Map::DeleteEndAlert(){
	delete endalert;
	endalert = NULL;
	if(Friend != NULL)
		Friend->show();

	nowActing = false;
	ResetPlayer();
}

void Map::DeleteNormalAlert(){
	delete normalalert;
	normalalert = NULL;
	if(Friend != NULL)
		Friend->show();
	ResetPlayer();
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
	delete inlibrary;
	inlibrary = NULL;
	delete inlabor;
	inlabor = NULL;
	ResetPlayer();
	if(Friend != NULL){
		Friend ->show();
	}
}

void Map::DeleteInDormitory()
{
	delete indormitory;
	indormitory = NULL;
	ResetPlayer();
	if(Friend != NULL){
		Friend ->show();
	}
}

void Map::DeleteInEngineering()
{
	delete inengineering;
	inengineering = NULL;
	ResetPlayer();
	if(Friend != NULL){
		Friend ->show();
	}
}

void Map::DeleteTA(){
	
	delete TA;
	TA = NULL;

	delete Screen;
	Screen = NULL;

	nowActing = false;

	if(Friend != NULL){
		Friend ->show();
	}
};

void Map::DeleteFList(){
	
	delete FL;
	FL = NULL;

	delete Screen;
	Screen = NULL;

	nowActing = false;

	if(Friend != NULL){
		Friend ->show();
	}
};

void Map::setManageGame(ManageGame *Game){
	onGoingGame = Game;
}

void Map::ResetPlayer(){
	x =320;
	y =350;

	nowPlayer->setGeometry(QRect(x, y, 40, 80));
	repaint();
	SetActing(false);
}

void Map::MovePlayer(){
	x -= px;
	y -= py;

	nowPlayer->setGeometry(QRect(x, y, 40, 80));
	repaint();
}

void Map::MoveToEngineering(){
	if(endalert!=NULL){
		delete endalert;
		endalert = NULL;
	}
	if((!nowActing)&&((askalert==NULL)&&(normalalert==NULL))){
	px = 5.77;
	py = 5.77;

	SetActing(true);
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(1300, this, SLOT(DeleteTimer()));
	QTimer::singleShot(1350, this, SLOT(setInEngineering()));
	Timer->start(20);
	}
}

void Map::MoveToCafeteria(){
	if(endalert!=NULL){
		delete endalert;
		endalert = NULL;
	}
	if((!nowActing)&&((askalert==NULL)&&(normalalert==NULL))){
	px = -6.4;
	py = 2;
	
	SetActing(true);
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(800, this, SLOT(DeleteTimer()));
	QTimer::singleShot(850, this, SLOT(setInCafeteria()));
	Timer->start(20);
	}
}


void Map::MoveToGym(){
	if(endalert!=NULL){
		delete endalert;
		endalert = NULL;
	}
	if((!nowActing)&&((askalert==NULL)&&(normalalert==NULL))){
	px = -3.5;
	py = 7.5;
	
	SetActing(true);
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(1000, this, SLOT(DeleteTimer()));
	QTimer::singleShot(1050, this, SLOT(setInGym()));
	Timer->start(30);
	}
}

void Map::MoveToLaborBuilding(){
	if(endalert!=NULL){
		delete endalert;
		endalert = NULL;
	}
	if((!nowActing)&&((askalert==NULL)&&(normalalert==NULL))){
	px = -5.5;
	py = 5.05;
	
	SetActing(true);
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(1000, this, SLOT(DeleteTimer()));
	QTimer::singleShot(1050, this, SLOT(setInLabor()));
	
	Timer->start(30);
	}
}

void Map::DeleteTimer(){
	delete Timer;
	px = 0;
	py = 0;
}

void Map::MoveToDormitory(){
	if(endalert!=NULL){
		delete endalert;
		endalert = NULL;
	}
	if((!nowActing)&&((askalert==NULL)&&(normalalert==NULL))){
	px = 0.9;
	py = 7;
	
	SetActing(true);
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(1200, this, SLOT(DeleteTimer()));
	QTimer::singleShot(1250, this, SLOT(setInDormitory()));
	Timer->start(30);
	}
}

void Map::MoveToStudentHall(){
	if(endalert!=NULL){
		delete endalert;
		endalert = NULL;
	}
	if((!nowActing)&&((askalert==NULL)&&(normalalert==NULL))){
	px = 3;
	py = 6.5;
	
	SetActing(true);
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(1200, this, SLOT(DeleteTimer()));
	QTimer::singleShot(1250, this, SLOT(setInStudentHall()));
	Timer->start(30);
	}
}

void Map::MoveToLogHouse(){
	if(endalert!=NULL){
		delete endalert;
		endalert = NULL;
	}
	if((!nowActing)&&((askalert==NULL)&&(normalalert==NULL))){
	px = -5.5;
	py = 7.3;
	
	SetActing(true);
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(1000, this, SLOT(DeleteTimer()));
	QTimer::singleShot(1050, this, SLOT(setInLogHouse()));
	Timer->start(30);
	}
}

void Map::MoveToLibrary(){
	if(endalert!=NULL){
		delete endalert;
		endalert = NULL;
	}
	if((!nowActing)&&((askalert==NULL)&&(normalalert==NULL))){
	px = 7;
	py = 4.7;
	
	SetActing(true);
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(1000, this, SLOT(DeleteTimer()));
	QTimer::singleShot(1050, this, SLOT(setInLibrary()));
	Timer->start(30);
	}
}

void Map::MoveToMarket(){
	if(endalert!=NULL){
		delete endalert;
		endalert = NULL;
	}
if((!nowActing)&&((askalert==NULL)&&(normalalert==NULL))){
	px = 6;
	py = -0.5;
	
	SetActing(true);
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(1000, this, SLOT(DeleteTimer()));
	QTimer::singleShot(1050, this, SLOT(setInMarket()));
	Timer->start(30);
	}
}

void Map::MoveToDrunkenFriend(){
	if(endalert!=NULL){
		delete endalert;
		endalert = NULL;
	}
	if((!nowActing)&&((askalert==NULL)&&(normalalert==NULL))){
	px = 5.5;
	py = 0;
	
	SetActing(true);
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(600, this, SLOT(DeleteTimer()));
	QTimer::singleShot(650, this, SLOT(MakeFriend()));
	Timer->start(30);
	}
}

void Map::MoveToSenior(){
	if(endalert!=NULL){
		delete endalert;
		endalert = NULL;
	}
	if((!nowActing)&&((askalert==NULL)&&(normalalert==NULL))){
	px = 4;
	py = 11.5;
	
	SetActing(true);
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(600, this, SLOT(DeleteTimer()));
	QTimer::singleShot(650, this, SLOT(MakeFriend()));
	Timer->start(30);
	}
}

void Map::MoveToSportFriend(){
	if(endalert!=NULL){
		delete endalert;
		endalert = NULL;
	}
	if((!nowActing)&&((askalert==NULL)&&(normalalert==NULL))){
	px = -3.5;
	py = 11.5;
	
	SetActing(true);
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(600, this, SLOT(DeleteTimer()));
	QTimer::singleShot(650, this, SLOT(MakeFriend()));
	Timer->start(30);
	}
}

void Map::MoveToTopFriend(){
	if(endalert!=NULL){
		delete endalert;
		endalert = NULL;
	}
	if((!nowActing)&&((askalert==NULL)&&(normalalert==NULL))){
	px = 7;
	py = 7.5;
	
	SetActing(true);
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(600, this, SLOT(DeleteTimer()));
	QTimer::singleShot(650, this, SLOT(MakeFriend()));
	Timer->start(30);
	}
}

void Map::MoveToLover(){
	if(endalert!=NULL){
		delete endalert;
		endalert = NULL;
	}
	if((!nowActing)&&((askalert==NULL)&&(normalalert==NULL))){
	px = -4;
	py = 1;
	
	SetActing(true);
	Timer = new QTimer(this);
	QObject::connect(Timer, SIGNAL(timeout()), SLOT(MovePlayer()));
	QTimer::singleShot(600, this, SLOT(DeleteTimer()));
	QTimer::singleShot(650, this, SLOT(MakeFriend()));
	Timer->start(30);
	}
}

void Map::setInGym(){

	Inbuildingalert = new InGym(onGoingGame, nowEnvironment);
	Inbuildingalert->setGeometry(QRect(0, 0, 660, 450));
	Inbuildingalert->show();
	if(Friend != NULL)
		Friend->hide();
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

InLibrary* Map::getInLibrary(){
	return inlibrary;
}
InLabor* Map::getInLabor(){
	return inlabor;
}

void Map::setInDormitory(){

	indormitory = new InDormitory(onGoingGame, nowEnvironment);
	indormitory->setGeometry(QRect(0, 0, 660, 450));
	indormitory->show();
	if(Friend != NULL)
		Friend->hide();
}

void Map::setInEngineering(){

	inengineering = new InEngineering(onGoingGame, nowEnvironment);
	inengineering->setGeometry(QRect(0, 0, 660, 450));
	inengineering->show();
	if(Friend != NULL)
		Friend->hide();
}

void Map::setInCafeteria(){

	if(onGoingGame->getisNight()){
		setNormalAlert("CantuseNight");
		return;
	}

	incafeteria = new InCafeteria(onGoingGame, nowEnvironment);
	incafeteria->setGeometry(QRect(0,0,660, 450));
	incafeteria->show();
	if(Friend != NULL)
		Friend->hide();
}

void Map::setInMarket(){

	inmarket = new InMarket(onGoingGame, nowEnvironment);
	inmarket->setGeometry(QRect(0,0,660, 450));
	inmarket->show();
	if(Friend != NULL)
		Friend->hide();
}

void Map::setInLogHouse(){

	if(!onGoingGame->getisNight()){
		setNormalAlert("CantuseDay");
		return;
	}

	inloghouse = new InLogHouse(onGoingGame, nowEnvironment);
	inloghouse->setGeometry(QRect(0,0,660, 450));
	inloghouse->show();
	if(Friend != NULL)
		Friend->hide();
}
void Map::setInLibrary(){

	inlibrary = new InLibrary(onGoingGame, nowEnvironment);
	inlibrary->setGeometry(QRect(0,0,660, 450));
	inlibrary->show();
	if(Friend != NULL)
		Friend->hide();
}
void Map::setInLabor(){

	inlabor = new InLabor(onGoingGame, nowEnvironment);
	inlabor->setGeometry(QRect(0,0,660, 450));
	inlabor->show();
	if(Friend != NULL)
		Friend->hide();
}

void Map::setInStudentHall(){

	instudenthall = new InStudentHall(onGoingGame, nowEnvironment);
	instudenthall->setGeometry(QRect(0,0,660, 450));
	instudenthall->show();
	if(Friend != NULL)
		Friend->hide();
}

void Map::setTA(){

	if(!nowActing){
		if(endalert!=NULL){
			delete endalert;
			endalert = NULL;
		}
		QPixmap BImage;
		BImage.load(QString::fromUtf8("Resources/TestAndAssn.png"));
		Screen = new QLabel(nowEnvironment);
		Screen->setScaledContents(true);
		Screen->setGeometry(QRect(0, 0, 660, 450));
		Screen->setPixmap(BImage);
		Screen->show();
		TA = new TestAssn(onGoingGame, Screen);
		TA->setGeometry(QRect(0, 0, 660, 450));
		TA->show();
		nowActing = true;

		if(Friend != NULL)
			Friend->hide();
	}
	return;
}

void Map::setFList(){
	
	if(!nowActing){
		if(endalert!=NULL){
			delete endalert;
			endalert = NULL;
		}
		QPixmap BImage;
		BImage.load(QString::fromUtf8("Resources/FriendList.png"));
		Screen = new QLabel(nowEnvironment);
		Screen->setScaledContents(true);
		Screen->setGeometry(QRect(0, 0, 660, 450));
		Screen->setPixmap(BImage);
		Screen->show();
		FL = new FriendList(onGoingGame, Screen);
		FL->setGeometry(QRect(0, 0, 660, 450));
		FL->show();
		nowActing = true;

		if(Friend != NULL)
			Friend->hide();
	}
	return;
}

void Map::setGR(){
		if(endalert!=NULL){
		delete endalert;
		endalert = NULL;
	}

		QPixmap BImage;
		BImage.load(QString::fromUtf8("Resources/Results.png"));
		Screen = new QLabel(nowEnvironment);
		Screen->setScaledContents(true);
		Screen->setGeometry(QRect(0, 0, 660, 450));
		Screen->setPixmap(BImage);
		Screen->show();
		card = new GradeReport(onGoingGame, nowSemester, field, Screen);
		card->setGeometry(QRect(0, 0, 660, 450));
		card->show();

		if(Friend != NULL)
			Friend->hide();
	

}

TestAssn* Map::getTA(){
	return TA;
}

FriendList* Map::getFList(){
	return FL;
}

void Map::SetFriend(){
	srand(time(NULL));

	int T = (rand()%30)+1;

	Friend = new QPushButton(nowEnvironment);
	//LogHouseImage->setScaledContents(true);
	
	QIcon IFriend;
	if(T>=0&&T<=10){
		FriendType = 1;
		IFriend.addPixmap(QPixmap(QString::fromUtf8("Resources/DrunkenFriend.png")), QIcon::Normal, QIcon::Off);
		Friend->setGeometry(QRect(140,350,70,80));
	}else if(T>10&&T<=18){
		FriendType = 2;
		IFriend.addPixmap(QPixmap(QString::fromUtf8("Resources/SeniorFriend.png")), QIcon::Normal, QIcon::Off);
		Friend->setGeometry(QRect(180,120,60,80));
	}else if(T>18&&T<=24){
		FriendType = 3;
		IFriend.addPixmap(QPixmap(QString::fromUtf8("Resources/HealthyFriend.png")), QIcon::Normal, QIcon::Off);
		Friend->setGeometry(QRect(430,120,60,80));	
	}else if(T>24&&T<=28){
		FriendType = 4;
		IFriend.addPixmap(QPixmap(QString::fromUtf8("Resources/StudyFriend.png")), QIcon::Normal, QIcon::Off);
		Friend->setGeometry(QRect(120,200,60,80));
	}else if(T>28&&T<=30){
		FriendType = 5;
		IFriend.addPixmap(QPixmap(QString::fromUtf8("Resources/LoverFriend.png")), QIcon::Normal, QIcon::Off);
		Friend->setGeometry(QRect(440,300,60,80));
	}
	
    
    Friend->setIcon(IFriend);
	Friend->setIconSize(QSize(80, 80));
	Friend->setFlat(true);
	Friend->show();

	if(nowActing)
		Friend->hide();

	if((askalert != NULL || normalalert != NULL || endalert != NULL)&&(FriendType==2 || FriendType == 4))
		Friend->hide();

	if(FriendType == 1)
		QObject::connect(Friend, SIGNAL(clicked()), SLOT(MoveToDrunkenFriend()));
	else if(FriendType == 2)
		QObject::connect(Friend, SIGNAL(clicked()), SLOT(MoveToSenior()));
	else if(FriendType == 3)
		QObject::connect(Friend, SIGNAL(clicked()), SLOT(MoveToSportFriend()));
	else if(FriendType == 4)
		QObject::connect(Friend, SIGNAL(clicked()), SLOT(MoveToTopFriend()));
	else if(FriendType == 5)
		QObject::connect(Friend, SIGNAL(clicked()), SLOT(MoveToLover()));

}

void Map::DeleteFriend(){
	if(Friend != NULL){
		Friend->hide();
		delete Friend;
	}
	Friend = NULL;
}

void Map::MakeFriend(){
	if(endalert!=NULL){
		delete endalert;
		endalert = NULL;
	}
	if(FriendType == 1){
		if(askalert != NULL)
			return;
		else{
			askalert = new AskAlert(onGoingGame, "DF",nowEnvironment);
			askalert->setGeometry(QRect(110, 100, 300, 225));
			askalert->show();
		}
	}else if(FriendType == 2){
		if(askalert != NULL)
			return;
		else{
			askalert = new AskAlert(onGoingGame, "S",nowEnvironment);
			askalert->setGeometry(QRect(110, 100, 300, 225));
			askalert->show();
		}
	}else if(FriendType == 3){
		if(askalert != NULL)
			return;
		else{
			askalert = new AskAlert(onGoingGame, "SF",nowEnvironment);
			askalert->setGeometry(QRect(110, 100, 300, 225));
			askalert->show();
		}
	}else if(FriendType == 4){
		if(askalert != NULL)
			return;
		else{
			askalert = new AskAlert(onGoingGame, "TF",nowEnvironment);
			askalert->setGeometry(QRect(110, 100, 300, 225));
			askalert->show();
		}
	}else if(FriendType == 5){
		if(askalert != NULL)
			return;
		else{
			askalert = new AskAlert(onGoingGame, "LO",nowEnvironment);
			askalert->setGeometry(QRect(110, 100, 300, 225));
			askalert->show();
		}
	}


}

void Map::setAskBack(){
	if(askalert != NULL)
		return;

	else{
	endalert = new EndAlert(field,"GoToMain",nowEnvironment);
	endalert->setGeometry(QRect(110, 100, 300, 225));
	endalert->show();
	}
}

