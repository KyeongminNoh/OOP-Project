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

	ss=S;
	ParentMap = map;
	ParentMap->setManageGame(this);
	Parent = parent;
	MenuBar = MB;

	nowSemester = ParentMap->get_nowSemester();
	int i;
	for(i=1 ; i<=8 ; i++)
	{
		if(S.grade[i]==0){
				nowSemester->setPastGrade(i,"A+");
				nowSemester->setPastGradeNum(i,4.3);
		}
		else if(S.grade[i]==-1){
				nowSemester->setPastGrade(i,"A");
				nowSemester->setPastGradeNum(i,4);
		}
		else if(S.grade[i]==-2){
				nowSemester->setPastGrade(i,"A-");
				nowSemester->setPastGradeNum(i,3.7);
		}
		else if(S.grade[i]==-3){
				nowSemester->setPastGrade(i,"B+");
				nowSemester->setPastGradeNum(i,3.3);
		}
		else if(S.grade[i]==-4){
				nowSemester->setPastGrade(i,"B");
				nowSemester->setPastGradeNum(i,3);
		}
		else if(S.grade[i]==-5){
				nowSemester->setPastGrade(i,"B-");
				nowSemester->setPastGradeNum(i,2.7);
		}
		else if(S.grade[i]==-6){
				nowSemester->setPastGrade(i,"C+");
				nowSemester->setPastGradeNum(i,2.3);
		}
		else if(S.grade[i]==-7){
				nowSemester->setPastGrade(i,"C");
				nowSemester->setPastGradeNum(i,2);
		}
		else if(S.grade[i]==-8){
				nowSemester->setPastGrade(i,"C-");
				nowSemester->setPastGradeNum(i,1.7);
		}
		else if(S.grade[i]==-9){
				nowSemester->setPastGrade(i,"D+");
				nowSemester->setPastGradeNum(i,1.3);
		}
		else if(S.grade[i]==-10){
				nowSemester->setPastGrade(i,"D");
				nowSemester->setPastGradeNum(i,1);
		}
		else if(S.grade[i]==-11){
				nowSemester->setPastGrade(i,"D-");
				nowSemester->setPastGradeNum(i,0.7);
		}
		else if(S.grade[i]<=-12){
				nowSemester->setPastGrade(i,"F");
				nowSemester->setPastGradeNum(i,0);
		}
	}
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
	isNight = false;
	Build();
	resize(650,150);

	int j;
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

void ManageGame::SetGrade(){
	int A;
	A =0;
	for(int i=0; i<8; i++){
		if(Assignmentlist[i]!=NULL){
			if(Assignmentlist[i]->get_solved())
				A++;
		}
	}
	A -= 8;
	A += Testlist[0]->get_Score();
	A += Testlist[1]->get_Score();

	A = -A;

	
	if(A==0){
			nowSemester->setGrade("A+");
			nowSemester->setGradeNum(4.3);
	}
	else if(A==1){
			nowSemester->setGrade("A");
			nowSemester->setGradeNum(4);
	}
	else if(A==2){
			nowSemester->setGrade("A-");
			nowSemester->setGradeNum(3.7);
	}
	else if(A==3){
			nowSemester->setGrade("B+");
			nowSemester->setGradeNum(3.3);
	}
	else if(A==4){
			nowSemester->setGrade("B");
			nowSemester->setGradeNum(3);
	}
	else if(A==5){
			nowSemester->setGrade("B-");
			nowSemester->setGradeNum(2.7);
	}
	else if(A==6){
			nowSemester->setGrade("C+");
			nowSemester->setGradeNum(2.3);
	}
	else if(A==7){
			nowSemester->setGrade("C");
			nowSemester->setGradeNum(2);
	}
	else if(A==8){
			nowSemester->setGrade("C-");
			nowSemester->setGradeNum(1.7);
	}
	else if(A==9){
			nowSemester->setGrade("D+");
			nowSemester->setGradeNum(1.3);
	}
	else if(A==10){
			nowSemester->setGrade("D");
			nowSemester->setGradeNum(1);
	}
	else if(A==11){
			nowSemester->setGrade("D-");
			nowSemester->setGradeNum(0.7);
	}
	else if(A>12){
			nowSemester->setGrade("F");
			nowSemester->setGradeNum(0);
	}
	
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
	showst->drawText(80, 128, st1);
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

	if(onPlayer->get_Nocturnal()){
		if(isNight)
			onPlayer->set_Health(DeclineHealth+0.05);
		else
			onPlayer->set_Health(DeclineHealth);
	}else{
		if(isNight)
			onPlayer->set_Health(DeclineHealth);
		else
			onPlayer->set_Health(DeclineHealth+0.05);
	}
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
			ParentMap->getInLabor()->DeleteAskAlert();
			ParentMap->getInLabor()->setNormalAlert("Fin");
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
			ParentMap->getInLabor()->DeleteAskAlert();
			ParentMap->getInLabor()->setNormalAlert("Fin");
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
			ParentMap->getInLibrary()->DeleteAskAlert();
			ParentMap->getInLibrary()->setNormalAlert("Fin");
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
			ParentMap->getInLibrary()->DeleteAskAlert();
			ParentMap->getInLibrary()->setNormalAlert("Fin");
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

	if(time%90 == 0){
		isNight = isNight ?  0 : 1;
		ParentMap->SetScreen(isNight);
	}

	if(time%20 == 0){
		ParentMap->SetFriend();
		QTimer::singleShot(15000, ParentMap, SLOT(DeleteFriend()));
	}

	if(time%9 == 0)
	{
		change_status();
		if(onPlayer->get_Health()<=DeclineHealth*0 || onPlayer->get_Lonely()>=onPlayer->get_Max_Lonely()-InclineLonely*0)
		{
			delete MainTimer;
			ParentMap->setEndAlert("GameOver");
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
				ParentMap->setNormalAlert("Midterm");
			}
			if(three_M == 10){
				if(assnCheck[7] == 1){
					assnCheck[7] = 0;
				}
				Testlist[1] = new Test(onPlayer->get_Knowledge(), k_finalterm);
				delete MainTimer;
				SetGrade();
				ParentMap->setGR();
				int i;
				FILE *fp[5];
				FILE *fp2;
				if(ss.File<=4 && ss.File>=1)
				{
					if(ss.File==1)
						fp2 = fopen("savedata1.txt","w");
					else if(ss.File==2)
						fp2 = fopen("savedata2.txt","w");
					else if(ss.File==3)
						fp2 = fopen("savedata3.txt","w");
					else if(ss.File==4)
						fp2 = fopen("savedata4.txt","w");
				}
				else
				{
					fp[1] = fopen("savedata1.txt","r");
					fp[2] = fopen("savedata2.txt","r");
					fp[3] = fopen("savedata3.txt","r");
					fp[4] = fopen("savedata4.txt","r");
					for(i=1 ; i<=4 ; i++)
					{
						if(!fp[i])
						{
							break;
						}
						else
							fclose(fp[i]);
					}
					if(i==1)
						fp2 = fopen("savedata1.txt","w");
					else if(i==2)
						fp2 = fopen("savedata2.txt","w");
					else if(i==3)
						fp2 = fopen("savedata3.txt","w");
					else if(i==4)
						fp2 = fopen("savedata4.txt","w");
					else
						fp2 = fopen("savedata1.txt","w");
				}
				fprintf(fp2,"%d %d\n",((int)onPlayer->get_Man())+1,2-((int)onPlayer->get_Nocturnal()));
				fprintf(fp2,"%d %d %d %d %d\n",DrunkenFriend,Senior,SportFriend,TopFriend,(int)Lover);
				fprintf(fp2,"%d\n",(int)onPlayer->get_Max_Health());
				qreal *grad;
				grad=nowSemester->get_grade();
				for(i=0 ; i<8 ; i++)
				{
					if(grad[i]==4.3)
						fprintf(fp2,"0 ");
					else if(grad[i]==4)
						fprintf(fp2,"-1 ");
					else if(grad[i]==3.7)
						fprintf(fp2,"-2 ");
					else if(grad[i]==3.3)
						fprintf(fp2,"-3 ");
					else if(grad[i]==3)
						fprintf(fp2,"-4 ");
					else if(grad[i]==2.7)
						fprintf(fp2,"-5 ");
					else if(grad[i]==2.3)
						fprintf(fp2,"-6 ");
					else if(grad[i]==2)
						fprintf(fp2,"-7 ");
					else if(grad[i]==1.7)
						fprintf(fp2,"-8 ");
					else if(grad[i]==1.3)
						fprintf(fp2,"-9 ");
					else if(grad[i]==1)
						fprintf(fp2,"-10 ");
					else if(grad[i]==0.7)
						fprintf(fp2,"-11 ");
					else if(grad[i]==0)
						fprintf(fp2,"-12 ");
					else
						fprintf(fp2,"1 ");
				}
				fclose(fp2);
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
		DeclineHealth += 0.01;
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
