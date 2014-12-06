#include "ManageGame.h"
#include "Player.h"
#include "Semester.h"
#include "Building.h"
#include "Dormitory.h"
#include "Cafeteria.h"
#include "Gym.h"
#include "Library.h"
#include "StudentHall.h"
#include "LogHouse.h"
#include "LaborBuilding.h"
#include "Market.h"
#include "Map.h"
#include "AskAlert.h"
#include "BuildWhat.h"
#include "InGym.h"
#include "InCafeteria.h"
#include "InMarket.h"
#include "InLogHouse.h"
#include "InLibrary.h"
#include "InLabor.h"
#include "InStudentHall.h"
#include "Assignment.h"
#include "Test.h"
#include "TestAssn.h"
#include <QMessageBox>


ManageGame::ManageGame(int isMan, int isDayPerson, Map *map,  BuildWhat *MB,struct data S,QWidget *parent) : QWidget(parent){

	ParentMap = map;
	ParentMap->setManageGame(this);
	Parent = parent;
	MenuBar = MB;

	nowSemester = ParentMap->get_nowSemester();

	onPlayer = new Player(isMan -1 , isDayPerson - 1);
	if(!(S.Max_Heal<=90 || S.Max_Heal>=10000))
	{
		onPlayer->set_Max_Health(S.Max_Heal-onPlayer->get_Max_Health());
		onPlayer->set_Health(S.Max_Heal);
	}
	if(ParentMap->get_nowSemester()->get_CurrentSemester()==1)
	{
		InclineLonely = 0.5;
		DeclineHealth = -0.6;
		k_midterm = 10;
		k_finalterm = 20;
		startassn = 2;
		mulassn = 2;
	}
	else if(ParentMap->get_nowSemester()->get_CurrentSemester()==2)
	{
		InclineLonely = 0.6;
		DeclineHealth = -0.7;
		k_midterm = 15;
		k_finalterm = 30;
		startassn = 3;
		mulassn = 3;
	}
	else if(ParentMap->get_nowSemester()->get_CurrentSemester()==3)
	{
		InclineLonely = 0.7;
		DeclineHealth = -0.9;
		k_midterm = 22;
		k_finalterm = 38;
		startassn = 10;
		mulassn = 3;
	}
	else if(ParentMap->get_nowSemester()->get_CurrentSemester()==4)
	{
		InclineLonely = 0.8;
		DeclineHealth = -1.1;
		k_midterm = 28;
		k_finalterm = 48;
		startassn = 12;
		mulassn = 4;
	}
	else if(ParentMap->get_nowSemester()->get_CurrentSemester()==5)
	{
		InclineLonely = 0.9;
		DeclineHealth = -1.3;
		k_midterm = 36;
		k_finalterm = 57;
		startassn = 20;
		mulassn = 4;
	}
	else if(ParentMap->get_nowSemester()->get_CurrentSemester()==6)
	{
		InclineLonely = 1.0;
		DeclineHealth = -1.5;
		k_midterm = 43;
		k_finalterm = 68;
		startassn = 23;
		mulassn = 5;
	}
	else if(ParentMap->get_nowSemester()->get_CurrentSemester()==7)
	{
		InclineLonely = 1.1;
		DeclineHealth = -1.7;
		k_midterm = 50;
		k_finalterm = 76;
		startassn = 30;
		mulassn = 5;
	}
	else if(ParentMap->get_nowSemester()->get_CurrentSemester()==8)
	{
		InclineLonely = 1.25;
		DeclineHealth = -2.0;
		k_midterm = 58;
		k_finalterm = 88;
		startassn = 34;
		mulassn = 6;
	}
	InclineFinance = 1;

	three_M = 0;
	
	Testlist = new Test*[2];
	Assignmentlist = new Assignment*[8];
	BuildingList = new Building*[9];
	for(int i = 0; i<9; i++){
		if(i<2){
			Testlist[i] = NULL;
			testCheck[i]=0;
		}
		if(i<8){
			Assignmentlist[i] = NULL;
			assnCheck[i]=0;
		}
		BuildingList[i] = NULL;
	}
	Build();
	resize(650,150);

	int i,j;
	for(i=1 ; i<=5 ; i++)
	{
		if(S.Friend_num[i]<=0 || S.Friend_num[i]>=1000)
			S.Friend_num[i]=0;
		for(j=1 ; j<=S.Friend_num[i] ; j++)
			onPlayer->add_Friend();
	}
	SportFriend = S.Friend_num[3];
	Senior = S.Friend_num[2];
	DrunkenFriend = S.Friend_num[1];
	Lover = (bool)S.Friend_num[5];
	TopFriend = S.Friend_num[4];

	time = 0;

	font = new QFont( "Resources/NanumBarunGothic.ttp");
	font->setKerning( true );
	font->setBold( true );
	font->setPixelSize( 21 );
	
	showst = new QPainter(this);
	showh = new QPainter(this);
	showgold = new QPainter(this);
	showw = new QPainter(this);
	showS = new QPainter(this);
	showTime = new QPainter(this);


	MainTimer = new QTimer(this);

	repaint();

	QObject::connect(MainTimer, SIGNAL(timeout()), SLOT(StartClock()));

	MainTimer->start(1000);
}

void ManageGame::TakeGold(){
	onPlayer->set_Finance(InclineFinance);
}

void ManageGame::change_InclineLonely(qreal d){
		InclineLonely = InclineLonely - d;
}

void ManageGame::change_InclineFinance(qreal i){
	InclineFinance += i;
}

void ManageGame::change_DeclineHealth(qreal i){
	DeclineHealth = DeclineHealth + i;
}

Building* ManageGame::getBuilding(int i){
	return BuildingList[i];
}

Assignment* ManageGame::getAssignment(int i){
	return Assignmentlist[i];
}

Test* ManageGame::getTest(int i){
	return Testlist[i];
}

int ManageGame::getAssn(int i){
	return assnCheck[i];
}

void ManageGame::setAssn(int i){
	assnCheck[i] = 2;
	Assignmentlist[i] = new Assignment(i+1, startassn+(mulassn*i));
}

void ManageGame::SetStrings(){

	st1.setNum(onPlayer->get_Lonely());


	st2.setNum(onPlayer->get_Health());

	st3.setNum(onPlayer->get_Knowledge());

	st4.setNum(onPlayer->get_Sociality());

	gt.setNum(onPlayer->get_Finance());

	t.clear();
	nt.setNum(time/60);
	t.append(nt+":");
	nt.setNum(time%60);
	t.append(nt);

}

void ManageGame::paintEvent(QPaintEvent *){

	SetStrings();

	
	showst->begin(this);
	showst->setFont(*font);
	showst->drawText(90, 128, st1);
	showst->end();

	
	showh->begin(this);
	showh->setFont(*font);
	showh->drawText(205, 128, st2);
	showh->end();

	
	showgold->begin(this);
	showgold->setFont(*font);
	showgold->drawText(353, 128, gt);
	showgold->end();

	
	showw->begin(this);
	showw->setFont(*font);
	showw->drawText(580, 82, st3);
	showw->end();


	showS->begin(this);
	showS->setFont(*font);
	showS->drawText(580, 126, st4);
	showS->end();


	showTime->begin(this);
	showTime->setFont(*font);
	showTime->drawText(580, 36, t);
	showTime->end();
}

void ManageGame::change_status(){
	if(Lover){
		if(onPlayer->get_Lonely()<5)
			onPlayer->set_Lonely(InclineLonely);
		else if(onPlayer->get_Lonely()>5)
			onPlayer->set_Lonely();
	}else{
		onPlayer->set_Lonely(InclineLonely);
	}
	onPlayer->set_Health(DeclineHealth);
	repaint();
}

void ManageGame::Build(){
	BuildingList[0] = new Dormitory(this);
	BuildingList[1] = new Cafeteria(this);
}

void ManageGame::BuildMarket(){
	if(BuildingList[8] == NULL){
		if(onPlayer->get_Finance() >= MARKET_COST){
			onPlayer->set_Finance(-MARKET_COST);
			repaint();
			BuildingList[8] = new Market(this);
			ParentMap->createMarketImage(1);
			ParentMap->DeleteAskAlert();
			MenuBar->setMarInactive();
			ParentMap->setNormalAlert("BCom");
		}
		else{
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("Fin");
		}
	}
	else if(BuildingList[8]->get_level() == 1){
		if(onPlayer->get_Finance() >= BuildingList[8]->get_UpgradeCost()){
			onPlayer->set_Finance(-BuildingList[8]->get_UpgradeCost());
			repaint();
			BuildingList[8]->Upgrade(this);
			ParentMap->getInMarket()->DeleteAskAlert();
			MenuBar->setMarInactive();
			ParentMap->getInMarket()->setNormalAlert("UCom");
			ParentMap->getInMarket()->ReDraw();
		}
		else{
			ParentMap->getInMarket()->DeleteAskAlert();
			ParentMap->getInMarket()->setNormalAlert("Fin");
		}
	}
	else if(BuildingList[8]->get_level() == 2){
		if(onPlayer->get_Finance() >= BuildingList[8]->get_UpgradeCost()){
			onPlayer->set_Finance(-BuildingList[8]->get_UpgradeCost());
			repaint();
			BuildingList[8]->Upgrade2(this);
			ParentMap->getInMarket()->DeleteAskAlert();
			MenuBar->setMarInactive();
			ParentMap->getInMarket()->setNormalAlert("UCom");
			ParentMap->getInMarket()->ReDraw();
		}
		else{
			ParentMap->getInMarket()->DeleteAskAlert();
			ParentMap->getInMarket()->setNormalAlert("Fin");
		}
	}
}

void ManageGame::BuildCafeteria(){
	if(BuildingList[1]->get_level() == 1){
		if(onPlayer->get_Finance() >= BuildingList[1]->get_UpgradeCost()){
			onPlayer->set_Finance(-BuildingList[1]->get_UpgradeCost());
			repaint();
			BuildingList[1]->Upgrade(this);
			ParentMap->getInCafeteria()->DeleteAskAlert();
			ParentMap->getInCafeteria()->setNormalAlert("UCom");
			ParentMap->getInCafeteria()->ReDraw();
		}
		else{
			ParentMap->getInCafeteria()->DeleteAskAlert();
			ParentMap->getInCafeteria()->setNormalAlert("Fin");
		}
	}
	else if(BuildingList[1]->get_level() == 2){
		if(onPlayer->get_Finance() >= BuildingList[1]->get_UpgradeCost()){
			onPlayer->set_Finance(-BuildingList[1]->get_UpgradeCost());
			repaint();
			BuildingList[1]->Upgrade2(this);
			ParentMap->getInCafeteria()->DeleteAskAlert();
			ParentMap->getInCafeteria()->setNormalAlert("UCom");
			ParentMap->getInCafeteria()->ReDraw();
		}
		else{
			ParentMap->getInCafeteria()->DeleteAskAlert();
			ParentMap->getInCafeteria()->setNormalAlert("Fin");
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
			MenuBar->setGymInactive();
			ParentMap->setNormalAlert("BCom");
		}
		else{
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("Fin");
		}
	}
	else if(BuildingList[3]->get_level() == 1){
		if(onPlayer->get_Finance() >= BuildingList[3]->get_UpgradeCost()){
			onPlayer->set_Finance(-BuildingList[3]->get_UpgradeCost());
			repaint();
			BuildingList[3]->Upgrade(this);
			ParentMap->getInGym()->DeleteAskAlert();
			MenuBar->setGymInactive();
			ParentMap->getInGym()->setNormalAlert("UCom");
			ParentMap->getInGym()->ReDraw();
		}
		else{
			ParentMap->getInGym()->DeleteAskAlert();
			ParentMap->getInGym()->setNormalAlert("Fin");
		}
	}
	else if(BuildingList[3]->get_level() == 2){
		if(onPlayer->get_Finance() >= BuildingList[3]->get_UpgradeCost()){
			onPlayer->set_Finance(-BuildingList[3]->get_UpgradeCost());
			repaint();
			BuildingList[3]->Upgrade2(this);
			ParentMap->getInGym()->DeleteAskAlert();
			MenuBar->setGymInactive();
			ParentMap->getInGym()->setNormalAlert("UCom");
			ParentMap->getInGym()->ReDraw();
		}
		else{
			ParentMap->getInGym()->DeleteAskAlert();
			ParentMap->getInGym()->setNormalAlert("Fin");
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
			MenuBar->setLabInactive();
			ParentMap->setNormalAlert("BCom");
		}
		else{
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("Fin");
		}
	}
	else if(BuildingList[4]->get_level() == 1){
		if(onPlayer->get_Finance() >= BuildingList[4]->get_UpgradeCost()){
			onPlayer->set_Finance(-BuildingList[4]->get_UpgradeCost());
			repaint();
			BuildingList[4]->Upgrade(this);
			ParentMap->getInLabor()->DeleteAskAlert();
			MenuBar->setLabInactive();
			ParentMap->getInLabor()->setNormalAlert("UCom");
			ParentMap->getInLabor()->ReDraw();
		}
		else{
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("Fin");
		}
	}
	else if(BuildingList[4]->get_level() == 2){
		if(onPlayer->get_Finance() >= BuildingList[4]->get_UpgradeCost()){
			onPlayer->set_Finance(-BuildingList[4]->get_UpgradeCost());
			repaint();
			BuildingList[4]->Upgrade2(this);
			ParentMap->getInLabor()->DeleteAskAlert();
			MenuBar->setLabInactive();
			ParentMap->getInLabor()->setNormalAlert("UCom");
			ParentMap->getInLabor()->ReDraw();
		}
		else{
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("Fin");
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
			MenuBar->setStuInactive();
			ParentMap->setNormalAlert("BCom");
		}
		else{
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("Fin");
		}
	}
	else if(BuildingList[5]->get_level() == 1){
		if(onPlayer->get_Finance() >= BuildingList[5]->get_UpgradeCost()){
			onPlayer->set_Finance(-BuildingList[5]->get_UpgradeCost());
			repaint();
			BuildingList[5]->Upgrade(this);
			ParentMap->getInStudentHall()->DeleteAskAlert();
			MenuBar->setStuInactive();
			ParentMap->getInStudentHall()->setNormalAlert("UCom");
			ParentMap->getInStudentHall()->ReDraw();
		}
		else{
			ParentMap->getInStudentHall()->DeleteAskAlert();
			ParentMap->getInStudentHall()->setNormalAlert("Fin");
		}
	}
	else if(BuildingList[5]->get_level() == 2){
		if(onPlayer->get_Finance() >= BuildingList[5]->get_UpgradeCost()){
			onPlayer->set_Finance(-BuildingList[5]->get_UpgradeCost());
			repaint();
			BuildingList[5]->Upgrade2(this);
			ParentMap->getInStudentHall()->DeleteAskAlert();
			MenuBar->setStuInactive();
			ParentMap->getInStudentHall()->setNormalAlert("UCom");
			ParentMap->getInStudentHall()->ReDraw();
		}
		else{
			ParentMap->getInStudentHall()->DeleteAskAlert();
			ParentMap->getInStudentHall()->setNormalAlert("Fin");
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
			MenuBar->setLibInactive();
			ParentMap->setNormalAlert("BCom");
		}
		else{
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("Fin");
		}
	}
	else if(BuildingList[6]->get_level() == 1){
		if(onPlayer->get_Finance() >= BuildingList[6]->get_UpgradeCost()){
			onPlayer->set_Finance(-BuildingList[6]->get_UpgradeCost());
			repaint();
			BuildingList[6]->Upgrade(this);
			ParentMap->getInLibrary()->DeleteAskAlert();
			MenuBar->setLibInactive();
			ParentMap->getInLibrary()->setNormalAlert("UCom");
			ParentMap->getInLibrary()->ReDraw();
		}
		else{
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("Fin");
		}
	}
	else if(BuildingList[6]->get_level() == 2){
		if(onPlayer->get_Finance() >= BuildingList[6]->get_UpgradeCost()){
			onPlayer->set_Finance(-BuildingList[6]->get_UpgradeCost());
			repaint();
			BuildingList[6]->Upgrade2(this);
			ParentMap->getInLibrary()->DeleteAskAlert();
			MenuBar->setLibInactive();
			ParentMap->getInLibrary()->setNormalAlert("UCom");
			ParentMap->getInLibrary()->ReDraw();
		}
		else{
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("Fin");
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
			MenuBar->setLogInactive();
			ParentMap->setNormalAlert("BCom");
		}
		else{
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("Fin");
		}
	}
	else if(BuildingList[7]->get_level() == 1){
		if(onPlayer->get_Finance() >= BuildingList[7]->get_UpgradeCost()){
			onPlayer->set_Finance(-BuildingList[7]->get_UpgradeCost());
			repaint();
			BuildingList[7]->Upgrade(this);
			ParentMap->getInLogHouse()->DeleteAskAlert();
			MenuBar->setLogInactive();
			ParentMap->getInLogHouse()->setNormalAlert("UCom");
			ParentMap->getInLogHouse()->ReDraw();
		}
		else{
			ParentMap->getInLogHouse()->DeleteAskAlert();
			ParentMap->getInLogHouse()->setNormalAlert("Fin");
		}
	}
	else if(BuildingList[7]->get_level() == 2){
		if(onPlayer->get_Finance() >= BuildingList[7]->get_UpgradeCost()){
			onPlayer->set_Finance(-BuildingList[7]->get_UpgradeCost());
			repaint();
			BuildingList[7]->Upgrade2(this);
			ParentMap->getInLogHouse()->DeleteAskAlert();
			MenuBar->setLogInactive();
			ParentMap->getInLogHouse()->setNormalAlert("UCom");
			ParentMap->getInLogHouse()->ReDraw();
		}
		else{
			ParentMap->getInLogHouse()->DeleteAskAlert();
			ParentMap->getInLogHouse()->setNormalAlert("Fin");
		}
	}

	
}

void ManageGame::DoExer()
{
	qreal FH = SportFriend * 0.5;

if(BuildingList[3]->get_level() == 1){
	if(onPlayer->get_Health() >= 10) // 운동시 필요 체력
	{
		onPlayer->set_Health(-10);
		onPlayer->set_Max_Health(5+FH);
		ParentMap->getInGym()->DeleteAskAlert();
		ParentMap->getInGym()->setNormalAlert("ECom1");
		repaint();
	}
	else
	{
		ParentMap->getInGym()->DeleteAskAlert();
		ParentMap->setNormalAlert("Heal");
	}
}
else if(BuildingList[3]->get_level() == 2){
	if(onPlayer->get_Health() >= 15) // 운동시 필요 체력
	{
		onPlayer->set_Health(-15);
		onPlayer->set_Max_Health(10+FH);
		ParentMap->getInGym()->DeleteAskAlert();
		ParentMap->getInGym()->setNormalAlert("ECom2");
		repaint();
	}
	else
	{
		ParentMap->getInGym()->DeleteAskAlert();
		ParentMap->setNormalAlert("Heal");
	}
}
else if(BuildingList[3]->get_level() == 3){
	if(onPlayer->get_Health() >= 20) // 운동시 필요 체력
	{
		onPlayer->set_Health(-20);
		onPlayer->set_Max_Health(20+FH);
		ParentMap->getInGym()->DeleteAskAlert();
		ParentMap->getInGym()->setNormalAlert("ECom3");
		repaint();
	}
	else
	{
		ParentMap->getInGym()->DeleteAskAlert();
		ParentMap->setNormalAlert("Heal");
	}
}
}

void ManageGame::DoStudy()
{
	qreal FS = TopFriend * 0.5;

if(BuildingList[6]->get_level() == 1){
	if(onPlayer->get_Health() >= 10) // 공부시 필요 체력
	{
		onPlayer->set_Health(-10);
		onPlayer->set_Knowledge(1+FS);
		ParentMap->getInLibrary()->DeleteAskAlert();
		ParentMap->getInLibrary()->setNormalAlert("SCom1");
		repaint();
	}
	else
	{
		ParentMap->getInLibrary()->DeleteAskAlert();
		ParentMap->setNormalAlert("SHeal");
	}
}
else if(BuildingList[6]->get_level() == 2){
	if(onPlayer->get_Health() >= 15) // 운동시 필요 체력
	{
		onPlayer->set_Health(-15);
		onPlayer->set_Knowledge(3+FS);
		ParentMap->getInLibrary()->DeleteAskAlert();
		ParentMap->getInLibrary()->setNormalAlert("SCom2");
		repaint();
	}
	else
	{
		ParentMap->getInLibrary()->DeleteAskAlert();
		ParentMap->setNormalAlert("SHeal");
	}
}
else if(BuildingList[6]->get_level() == 3){
	if(onPlayer->get_Health() >= 20) // 운동시 필요 체력
	{
		onPlayer->set_Health(-20);
		onPlayer->set_Knowledge(5+FS);
		ParentMap->getInLibrary()->DeleteAskAlert();
		ParentMap->getInLibrary()->setNormalAlert("SCom3");
		repaint();
	}
	else
	{
		ParentMap->getInLibrary()->DeleteAskAlert();
		ParentMap->setNormalAlert("SHeal");
	}
}
}

void ManageGame::DoWork()
{
if(BuildingList[4]->get_level() == 1){
	if(onPlayer->get_Health() >= 20) // 공부시 필요 체력
	{
		onPlayer->set_Health(-20);
		onPlayer->set_Finance(10);
		ParentMap->getInLabor()->DeleteAskAlert();
		ParentMap->getInLabor()->setNormalAlert("WCom1");
		repaint();
	}
	else
	{
		ParentMap->getInLabor()->DeleteAskAlert();
		ParentMap->setNormalAlert("WHeal");
	}
}
else if(BuildingList[4]->get_level() == 2){
	if(onPlayer->get_Health() >= 30) // 운동시 필요 체력
	{
		onPlayer->set_Health(-30);
		onPlayer->set_Finance(20);
		ParentMap->getInLabor()->DeleteAskAlert();
		ParentMap->getInLabor()->setNormalAlert("WCom2");
		repaint();
	}
	else
	{
		ParentMap->getInLabor()->DeleteAskAlert();
		ParentMap->setNormalAlert("WHeal");
	}
}
else if(BuildingList[4]->get_level() == 3){
	if(onPlayer->get_Health() >= 40) // 운동시 필요 체력
	{
		onPlayer->set_Health(-40);
		onPlayer->set_Finance(30);
		ParentMap->getInLabor()->DeleteAskAlert();
		ParentMap->getInLabor()->setNormalAlert("WCom3");
		repaint();
	}
	else
	{
		ParentMap->getInLabor()->DeleteAskAlert();
		ParentMap->setNormalAlert("WHeal");
	}
}
}

void ManageGame::OKalert(){
	ParentMap->DeleteNormalAlert();
}

void ManageGame::OKBldgAlert(QString Type){
	if(Type == "Gym")
		ParentMap->getInGym()->DeleteNormalAlert();
	if(Type == "Caf")
		ParentMap->getInCafeteria()->DeleteNormalAlert();
	if(Type == "Lib")
		ParentMap->getInLibrary()->DeleteNormalAlert();
	if(Type == "Lab")
		ParentMap->getInLabor()->DeleteNormalAlert();
	if(Type == "Mar")
		ParentMap->getInMarket()->DeleteNormalAlert();
	if(Type == "Log")
		ParentMap->getInLogHouse()->DeleteNormalAlert();
	if(Type == "Stu")
		ParentMap->getInStudentHall()->DeleteNormalAlert();
}

void ManageGame::BACKalert()
{
	ParentMap->DeleteInBldg();
}

void ManageGame::StartClock(){
	time++;
	repaint();

	if(time%6 == 0){
		ParentMap->SetFriend();
		QTimer::singleShot(5000, ParentMap, SLOT(DeleteFriend()));
	}

	if(time%9 == 0)
	{
		change_status();
		if(onPlayer->get_Health()<=DeclineHealth*0 || onPlayer->get_Lonely()>=onPlayer->get_Max_Lonely()-InclineLonely*0)
		{
			delete MainTimer;
			ParentMap->setNormalAlert("Over");
		}
	
	}

	if(time%36 == 0)
		onPlayer->set_Finance(InclineFinance);

	if(three_M <= 10)
		Check_Assn();

	repaint();

}

void ManageGame::Check_Assn(){
	if(time%180 == 0 ){
		three_M++;
		if(three_M%5 == 0){
			if(three_M == 5){
				if(assnCheck[3] == 1){
					assnCheck[3] = 0;
				}
				Testlist[0] = new Test(onPlayer->get_Knowledge(), k_midterm);
			}
			if(three_M == 10){
				if(assnCheck[7] == 1){
					assnCheck[7] = 0;
				}
				Testlist[1] = new Test(onPlayer->get_Knowledge(), k_finalterm);
			}
		}
		else{
			if(three_M == 1)
				assnCheck[three_M - 1] = 1;
			else if(three_M < 5){
				if(assnCheck[three_M - 2] != 2){
					assnCheck[three_M - 2] = 0;
				}else if(assnCheck[three_M - 2] = 2){
					Assignmentlist[three_M - 2]->set_Cannotsolve();
				}
				assnCheck[three_M - 1] = 1;
			}
			else{
				if(assnCheck[three_M - 3] != 2){
					assnCheck[three_M - 3] = 0;
				}else if(assnCheck[three_M - 3] = 2){
					Assignmentlist[three_M - 3]->set_Cannotsolve();
				}
				assnCheck[three_M - 2] = 1;
			}
		}
	}
}

void ManageGame::StartGame(){

	change_status();
	
}

void ManageGame::Sleep(){
	if(BuildingList[0]->get_level() < 3){
		BuildingList[0]->Upgrade(this);
		ParentMap->DeleteInDormitory();
		repaint();
		ParentMap->setNormalAlert("Sleep");

	}
	else{
		ParentMap->DeleteInDormitory();
		ParentMap->setNormalAlert("CTSleep");
	}
}

void ManageGame::NoSleep(){
	ParentMap->DeleteInDormitory();
}

void ManageGame::CloseEngineering(){
	ParentMap->DeleteInEngineering();
}

void ManageGame::CloseTA(){
	ParentMap->DeleteTA();
}

void ManageGame::CloseFL(){
	ParentMap->DeleteFList();
}

void ManageGame::NothingInGym(){
	ParentMap->getInGym()->DeleteAskAlert();
};

void ManageGame::NothingInLib(){
	ParentMap->getInLibrary()->DeleteAskAlert();
};
void ManageGame::NothingInLab(){
	ParentMap->getInLabor()->DeleteAskAlert();
};
void ManageGame::NothingInCaf(){
	ParentMap->getInCafeteria()->DeleteAskAlert();
};

void ManageGame::NothingInMar(){
	ParentMap->getInMarket()->DeleteAskAlert();
};

void ManageGame::NothingInLog(){
	ParentMap->getInLogHouse()->DeleteAskAlert();
};

void ManageGame::NothingInStu(){
	ParentMap->getInStudentHall()->DeleteAskAlert();
}

void ManageGame::EatinCaf(int T){
	qreal FF = -(0.1 * Senior);

	if(T == 1){
		if(onPlayer->get_Finance() >= (5+FF)){
			onPlayer->set_Finance(-(5+FF));
			onPlayer->set_Health(3);
			ParentMap->getInCafeteria()->DeleteAskAlert();
			repaint();
			ParentMap->getInCafeteria()->setNormalAlert("Beat");
		}
		else{
			ParentMap->getInCafeteria()->DeleteAskAlert();
			ParentMap->getInCafeteria()->setNormalAlert("Fin");
		}
	}
	else if(T == 2){
		if(onPlayer->get_Finance() >= (7+FF)){
			onPlayer->set_Finance(-(7+FF));
			onPlayer->set_Health(5);
			ParentMap->getInCafeteria()->DeleteAskAlert();
			repaint();
			ParentMap->getInCafeteria()->setNormalAlert("Ceat");
		}
		else{
			ParentMap->getInCafeteria()->DeleteAskAlert();
			ParentMap->getInCafeteria()->setNormalAlert("Fin");
		}
	}
	else if(T == 3){
		if(onPlayer->get_Finance() >= (10+FF)){
			onPlayer->set_Finance(-(10+FF));
			onPlayer->set_Health(8);
			ParentMap->getInCafeteria()->DeleteAskAlert();
			repaint();
			ParentMap->getInCafeteria()->setNormalAlert("Deat");
		}
		else{
			ParentMap->getInCafeteria()->DeleteAskAlert();
			ParentMap->getInCafeteria()->setNormalAlert("Fin");
		}
	}

}

void ManageGame::DrinkinMarket(int T){
	qreal FH = 0.2 * DrunkenFriend;
	qreal FF = (0.2 * DrunkenFriend) - (0.1 * Senior);
	qreal FL = 0.2 * DrunkenFriend;

	if(T == 1){
		if(onPlayer->get_Finance() >= (10 + FF)){
			if(onPlayer->get_Health() >= (6+FH)){
				onPlayer->set_Finance(-(10+FF));
				onPlayer->set_Health(-(6+FH));
				onPlayer->set_Lonely(-(5+FL));
				ParentMap->getInMarket()->DeleteAskAlert();
				repaint();
				ParentMap->getInMarket()->setNormalAlert("Drink1");
			}else{
				ParentMap->getInMarket()->DeleteAskAlert();
				ParentMap->getInMarket()->setNormalAlert("MarHea");
			}
		}
		else{
			ParentMap->getInMarket()->DeleteAskAlert();
			ParentMap->getInMarket()->setNormalAlert("MarFin");
		}
	}
	else if(T == 2){
		if(onPlayer->get_Finance() >= (12+FF)){
			if(onPlayer->get_Health() >= (8+FH)){
				onPlayer->set_Finance(-(12+FF));
				onPlayer->set_Health(-(8+FH));
				onPlayer->set_Lonely(-(10+FL));
				ParentMap->getInMarket()->DeleteAskAlert();
				repaint();
				ParentMap->getInMarket()->setNormalAlert("Drink2");
			}else{
				ParentMap->getInMarket()->DeleteAskAlert();
				ParentMap->getInMarket()->setNormalAlert("MarHea");
			}
		}
		else{
			ParentMap->getInMarket()->DeleteAskAlert();
			ParentMap->getInMarket()->setNormalAlert("MarFin");
		}
	}
	else if(T == 3){
		if(onPlayer->get_Finance() >= (15+FF)){
			if(onPlayer->get_Health() >= (10+FH)){

				onPlayer->set_Finance(-(15+FF));
				onPlayer->set_Health(-(10+FH));
				onPlayer->set_Lonely(-(15+FL));
				ParentMap->getInMarket()->DeleteAskAlert();
				repaint();
				ParentMap->getInMarket()->setNormalAlert("Drink3");
			}else{
				ParentMap->getInMarket()->DeleteAskAlert();
				ParentMap->getInMarket()->setNormalAlert("MarHea");
			}
		}
		else{
			ParentMap->getInMarket()->DeleteAskAlert();
			ParentMap->getInMarket()->setNormalAlert("MarFin");
		}
	}

}

void ManageGame::EatinLogHouse(int T){
	qreal FF = -(0.1 * Senior);

	if(T == 1){
		if(onPlayer->get_Finance() >= (5+FF)){
			onPlayer->set_Finance(-(5+FF));
			onPlayer->set_Health(2);
			ParentMap->getInLogHouse()->DeleteAskAlert();
			repaint();
			ParentMap->getInLogHouse()->setNormalAlert("AeatL");
		}
		else{
			ParentMap->getInLogHouse()->DeleteAskAlert();
			ParentMap->getInLogHouse()->setNormalAlert("logFin");
		}
	}
	else if(T == 2){
		if(onPlayer->get_Finance() >= (7+FF)){
			onPlayer->set_Finance(-(7+FF));
			onPlayer->set_Health(4);
			ParentMap->getInLogHouse()->DeleteAskAlert();
			repaint();
			ParentMap->getInLogHouse()->setNormalAlert("BeatL");
		}
		else{
			ParentMap->getInLogHouse()->DeleteAskAlert();
			ParentMap->getInLogHouse()->setNormalAlert("logFin");
		}
	}
	else if(T == 3){
		if(onPlayer->get_Finance() >= (10+FF)){
			onPlayer->set_Finance(-(10+FF));
			onPlayer->set_Health(7);
			ParentMap->getInLogHouse()->DeleteAskAlert();
			repaint();
			ParentMap->getInLogHouse()->setNormalAlert("CeatL");
		}
		else{
			ParentMap->getInLogHouse()->DeleteAskAlert();
			ParentMap->getInLogHouse()->setNormalAlert("logFin");
		}
	}

}

void ManageGame::ClubActivity(int T){
	if(T == 1){
		if(onPlayer->get_Health() >= 5){
			onPlayer->set_Health(-5);
			onPlayer->set_Lonely(-4);
			ParentMap->getInStudentHall()->DeleteAskAlert();
			repaint();
			ParentMap->getInStudentHall()->setNormalAlert("clubA");
		}
		else{
			ParentMap->getInStudentHall()->DeleteAskAlert();
			ParentMap->getInStudentHall()->setNormalAlert("stuHea");
		}
	}
	else if(T == 2){
		if(onPlayer->get_Health() >= 7){
			onPlayer->set_Health(-7);
			onPlayer->set_Lonely(-8);
			ParentMap->getInStudentHall()->DeleteAskAlert();
			repaint();
			ParentMap->getInStudentHall()->setNormalAlert("clubB");
		}
		else{
			ParentMap->getInStudentHall()->DeleteAskAlert();
			ParentMap->getInStudentHall()->setNormalAlert("stuHea");
		}
	}
	else if(T == 3){
		if(onPlayer->get_Health() >= 9){
			onPlayer->set_Health(-9);
			onPlayer->set_Lonely(-12);
			ParentMap->getInStudentHall()->DeleteAskAlert();
			repaint();
			ParentMap->getInStudentHall()->setNormalAlert("clubC");
		}
		else{
			ParentMap->getInStudentHall()->DeleteAskAlert();
			ParentMap->getInStudentHall()->setNormalAlert("stuHea");
		}
	}

}

void ManageGame::SolveAssn(int i){
	int FS = (Senior * 1) + (TopFriend * 5);

	if(Assignmentlist[i]==NULL)
		return;

	if(!Assignmentlist[i]->get_solved()){
		if(!Assignmentlist[i]->get_Cannotsolve()){
			if(onPlayer->get_Knowledge()>=(Assignmentlist[i]->get_KnowReq() - FS)){
				Assignmentlist[i]->set_solve();
				ParentMap->getTA()->repaint();
				ParentMap->setNormalAlert("Solve");
			}
			else{
				ParentMap->setNormalAlert("lowKnow");
				return;
			}
		}else{
			ParentMap->setNormalAlert("Due");
			return;
		}
	}
}

void ManageGame::MakeDF(){
	ParentMap->DeleteAskAlert();
	DrunkenFriend++;
	onPlayer->add_Friend();
	ParentMap->setNormalAlert("FMCom");
	ParentMap->DeleteFriend();
};

void ManageGame::MakeS(){
	if(onPlayer->get_Sociality() >= 3){
		ParentMap->DeleteAskAlert();
		Senior++;
		onPlayer->add_Friend();
		ParentMap->setNormalAlert("FMCom");
		ParentMap->DeleteFriend();
	}else{
		ParentMap->DeleteAskAlert();
		ParentMap->setNormalAlert("SSoc");
	}
};

void ManageGame::MakeSF(){
	if(onPlayer->get_Sociality() >= 5){
		ParentMap->DeleteAskAlert();
		SportFriend++;
		DeclineHealth -= 0.01;
		onPlayer->add_Friend();
		ParentMap->setNormalAlert("FMCom");
		ParentMap->DeleteFriend();
	}else{
		ParentMap->DeleteAskAlert();
		ParentMap->setNormalAlert("SSoc");
	}
};

void ManageGame::MakeTF(){
	if(onPlayer->get_Sociality() >= 10){
		ParentMap->DeleteAskAlert();
		TopFriend++;
		onPlayer->add_Friend();
		ParentMap->setNormalAlert("FMCom");
		ParentMap->DeleteFriend();
	}else{
		ParentMap->DeleteAskAlert();
		ParentMap->setNormalAlert("SSoc");
	}
};

void ManageGame::MakeLO(){
	if(!Lover){
		if(onPlayer->get_Sociality() >= 20){
			ParentMap->DeleteAskAlert();
			Lover = true;
			onPlayer->add_Friend();
			InclineFinance -= 0.2;
			ParentMap->setNormalAlert("FMCom");
			ParentMap->DeleteFriend();
		}else{
			ParentMap->DeleteAskAlert();
			ParentMap->setNormalAlert("SSoc");
		}
	}else{
		ParentMap->DeleteAskAlert();
		ParentMap->setNormalAlert("HaveLover");
	}
};
