#include "ManageGame.h"
#include "Player.h"
#include "Building.h"
#include "Cafeteria.h"
#include "Gym.h"
#include "Library.h"
#include "StudentHall.h"
#include "LogHouse.h"
#include "LaborBuilding.h"
#include "Market.h"
#include "Map.h"
#include "AskAlert.h"
#include <QMessageBox>


ManageGame::ManageGame(int isMan, int isDayPerson, Map *map,QWidget *parent) : QWidget(parent){

	ParentMap = map;
	ParentMap->setManageGame(this);
	Parent = parent;


	onPlayer = new Player(isMan -1 , isDayPerson - 1);
	InclineLonely = 1;
	DeclineHealth = -1;
	InclineFinance = 500;
	BuildingList = new Building*[9];
	for(int i = 0; i<9; i++)
		BuildingList[i] = NULL;

	resize(500,150);

	time = QTime::currentTime();


	font = new QFont( "Resources/NanumBarunGothic.ttp");
	font->setKerning( true );
	font->setBold( true );
	font->setPixelSize( 20 );

	GameTimer = new QTimer(this);
	//GameTimer2 = new QTimer(this);
	GoldTimer = new QTimer(this);
	repaint();
	QObject::connect(GameTimer, SIGNAL(timeout()), SLOT(StartGame()));
	QObject::connect(GoldTimer, SIGNAL(timeout()), SLOT(TakeGold()));

	GoldTimer->start(30000);
	GameTimer->start(5000);

}

void ManageGame::TakeGold(){
	onPlayer->set_Finance(InclineFinance);
}

void ManageGame::change_InclineLonely(qreal d){
	InclineLonely = InclineLonely - d;
}

void ManageGame::change_DeclineHealth(qreal i){
	DeclineHealth = DeclineHealth + i;
}

Building* ManageGame::getBuilding(int i){
	return BuildingList[i];
}

void ManageGame::SetStrings(){
	s1.clear();
	s1.append(" Lonely :");
	st1.setNum(onPlayer->get_Lonely());
	s1.append(st1);
	s2.clear();
	s2.append(" Health : ");
	st2.setNum(onPlayer->get_Health());
	s2.append(st2);
	s3.clear();
	s3.append(" Wisdom : ");
	st3.setNum(onPlayer->get_Knowledge());
	s3.append(st3);
	s4.clear();
	s4.append(" Sociality : ");
	st4.setNum(onPlayer->get_Sociality());
	s4.append(st4);
	g.clear();
	g.append(" Gold : ");
	gt.setNum(onPlayer->get_Finance());
	g.append(gt);

}

void ManageGame::paintEvent(QPaintEvent *){

	SetStrings();

	showst = new QPainter(this);
	showst->begin(this);
	showst->setFont(*font);
	showst->drawText(50, 45, s1);
	showst->end();

	showh = new QPainter(this);
	showh->begin(this);
	showh->setFont(*font);
	showh->drawText(50, 85, s2);
	showh->end();

	showgold = new QPainter(this);
	showgold->begin(this);
	showgold->setFont(*font);
	showgold->drawText(50, 125, g);
	showgold->end();

	showw = new QPainter(this);
	showw->begin(this);
	showw->setFont(*font);
	showw->drawText(220, 45, s3);
	showw->end();

	showS = new QPainter(this);
	showS->begin(this);
	showS->setFont(*font);
	showS->drawText(220, 85, s4);
	showS->end();
}


void ManageGame::change_status(){
	onPlayer->set_Lonely(InclineLonely);
	onPlayer->set_Health(DeclineHealth);
	repaint();
}

void ManageGame::Build(){

}


void ManageGame::BuildMarket(){
	if(BuildingList[8] == NULL){
		if(onPlayer->get_Finance() >= MARKET_COST){
			onPlayer->set_Finance(-MARKET_COST);
			repaint();
			BuildingList[8] = new Market(this);
			ParentMap->createMarketImage(1);
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("BCom");
		}
		else{
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("Fin");
		}
	}
	else if(BuildingList[8]->get_level() == 1){
		if(onPlayer->get_Finance() >= BuildingList[8]->get_UpgradeCost()){
			onPlayer->set_Finance(BuildingList[8]->get_UpgradeCost());
			repaint();
			BuildingList[8]->Upgrade(this);
		}
	}
	else{
		if(onPlayer->get_Finance() >= BuildingList[8]->get_UpgradeCost()){
			onPlayer->set_Finance(BuildingList[8]->get_UpgradeCost());
			repaint();
			BuildingList[8]->Upgrade2(this);
		}
	}
}



void ManageGame::BuildGym(){
	if(BuildingList[3] == NULL){
		if(onPlayer->get_Finance() >= GYM_COST){
			onPlayer->set_Finance(-GYM_COST);
			repaint();
			BuildingList[3] = new Gym(this);
			ParentMap->createGymImage(1);
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("BCom");
		}
		else{
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("Fin");
		}
	}
	else if(BuildingList[3]->get_level() == 1){
		if(onPlayer->get_Finance() >= BuildingList[3]->get_UpgradeCost()){
			onPlayer->set_Finance(BuildingList[3]->get_UpgradeCost());
			repaint();
			BuildingList[3]->Upgrade(this);
		}
	}
	else{
		if(onPlayer->get_Finance() >= BuildingList[3]->get_UpgradeCost()){
			onPlayer->set_Finance(BuildingList[3]->get_UpgradeCost());
			repaint();
			BuildingList[3]->Upgrade2(this);
		}
	}
	
}

void ManageGame::BuildLaborBuilding(){
	if(BuildingList[4] == NULL){
		if(onPlayer->get_Finance() >= LABORB_COST){
			onPlayer->set_Finance(-LABORB_COST);
			repaint();
			BuildingList[4] = new LaborBuilding(this);
			ParentMap->createLaborBuilding(1);
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("BCom");
		}
		else{
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("Fin");
		}
	}
	else if(BuildingList[4]->get_level() == 1){
		if(onPlayer->get_Finance() >= BuildingList[4]->get_UpgradeCost()){
			onPlayer->set_Finance(BuildingList[4]->get_UpgradeCost());
			repaint();
			BuildingList[4]->Upgrade(this);
		}
	}
	else{
		if(onPlayer->get_Finance() >= BuildingList[4]->get_UpgradeCost()){
			onPlayer->set_Finance(BuildingList[4]->get_UpgradeCost());
			repaint();
			BuildingList[4]->Upgrade2(this);
		}
	}
	
}

void ManageGame::BuildStudentHall(){
	if(BuildingList[5] == NULL){
		if(onPlayer->get_Finance() >= STUHALL_COST){
			onPlayer->set_Finance(-STUHALL_COST);
			repaint();
			BuildingList[5] = new StudentHall(this);
			ParentMap->createStudentHall(1);
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("BCom");
		}
		else{
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("Fin");
		}
	}
	else if(BuildingList[5]->get_level() == 1){
		if(onPlayer->get_Finance() >= BuildingList[5]->get_UpgradeCost()){
			onPlayer->set_Finance(BuildingList[5]->get_UpgradeCost());
			repaint();
			BuildingList[5]->Upgrade(this);
		}
	}
	else{
		if(onPlayer->get_Finance() >= BuildingList[5]->get_UpgradeCost()){
			onPlayer->set_Finance(BuildingList[5]->get_UpgradeCost());
			repaint();
			BuildingList[5]->Upgrade2(this);
		}
	}
}

void ManageGame::BuildLibrary(){
	if(BuildingList[6] == NULL){
		if(onPlayer->get_Finance() >= LIBRARY_COST){
			onPlayer->set_Finance(-LIBRARY_COST);
			repaint();
			BuildingList[6] = new Library(this);
			ParentMap->createLibraryImage(1);
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("BCom");
		}
		else{
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("Fin");
		}
	}
	else if(BuildingList[6]->get_level() == 1){
		if(onPlayer->get_Finance() >= BuildingList[6]->get_UpgradeCost()){
			onPlayer->set_Finance(BuildingList[6]->get_UpgradeCost());
			repaint();
			BuildingList[6]->Upgrade(this);
		}
	}
	else{
		if(onPlayer->get_Finance() >= BuildingList[6]->get_UpgradeCost()){
			onPlayer->set_Finance(BuildingList[6]->get_UpgradeCost());
			repaint();
			BuildingList[6]->Upgrade2(this);
		}
	}
	
}

void ManageGame::NoBuild(){
	ParentMap->DeleteAskAlert();
}

void ManageGame::BuildLogHouse(){
	if(BuildingList[7] == NULL){
		if(onPlayer->get_Finance() >= LOGHOUSE_COST){
			onPlayer->set_Finance(-LOGHOUSE_COST);
			repaint();
			BuildingList[7] = new LogHouse(this);
			ParentMap->createLogHouseImage(1);
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("BCom");
		}
		else{
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("Fin");
		}
	}
	else if(BuildingList[6]->get_level() == 1){
		if(onPlayer->get_Finance() >= BuildingList[7]->get_UpgradeCost()){
			onPlayer->set_Finance(BuildingList[7]->get_UpgradeCost());
			repaint();
			BuildingList[7]->Upgrade(this);
		}
	}
	else{
		if(onPlayer->get_Finance() >= BuildingList[7]->get_UpgradeCost()){
			onPlayer->set_Finance(BuildingList[7]->get_UpgradeCost());
			repaint();
			BuildingList[7]->Upgrade2(this);
		}
	}

	
}
void ManageGame::DoExer()
{
	if(onPlayer->get_Health() >= 1) // 운동시 필요 체력
	{
//		onPlayer->set_Health();
//		onPlayer->set_Max_Health();
		ParentMap->setNormalAlert("ECom");
	}
	else
	{
		ParentMap->setNormalAlert("Heal");
	}
}
void ManageGame::UpgradeGym()
{
	if(onPlayer->get_Finance() >= BuildingList[3]->get_UpgradeCost())
	{
		onPlayer->set_Finance(BuildingList[3]->get_UpgradeCost());
		if(BuildingList[3]->get_level()==1)
			BuildingList[3]->Upgrade(this);
		else if(BuildingList[3]->get_level()==2)
			BuildingList[3]->Upgrade2(this);
	}
}
void ManageGame::OKalert(){
	ParentMap->DeleteNormalAlert();
}

void ManageGame::StartGame(){

	change_status();
	
}

