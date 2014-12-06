#include <QPushButton>
#include <QGridLayout>
#include <QTime>
#include <QTimer>
#include <QLabel>
#include <QWidget>
#include <QFont>
#include <QPainter>
#include "LoadScene.h"

#define LABORB_COST 20
#define STUHALL_COST 20
#define GYM_COST 20
#define LOGHOUSE_COST 20
#define LIBRARY_COST 20
#define MARKET_COST 30

class Assignment;
class Test;
class Player;
class Building;
class Friend;
class Environment;
class Map;
class BuildWhat;
class Semester;



class ManageGame : public QWidget {

	Q_OBJECT

public:
	ManageGame( int isMan, int isDayPerson, Map *map, BuildWhat *MB,struct data S,QWidget *parent = 0);

	bool getisNight(){return isNight;}
	void SetGrade();
	Building* getBuilding(int i);
	int getAssn(int i);
	void setAssn(int i);
	void SetStrings();
	void Build();
	void change_status();
	void change_InclineLonely(qreal d);
	void change_DeclineHealth(qreal i);
	void change_InclineFinance(qreal i);
	void Check_Assn();
	Player* get_onPlayer(){ return onPlayer;}
	Semester* get_nowSemester(){ return nowSemester;}
	Assignment* getAssignment(int i);
	Test* getTest(int i);


	void SolveAssn(int i);

	int getDF(){return DrunkenFriend;};
	int getS(){return Senior;};
	int getSF(){return SportFriend;};
	int getTF(){return TopFriend;};
	bool getL(){return Lover;};
private:
	void paintEvent(QPaintEvent *);
	
	Semester *nowSemester;
	QWidget *Parent;
	//QGridLayout *grid;
	QString s1, s2, s3, s4, g, st1, st2, st3, st4, gt, t, nt;
	QLabel *Page;
	QPainter *showst;
	QPainter *showh;
	QPainter *showw;
	QPainter *showS;
	QPainter *showgold;
	QPainter *showTime;
	QFont *font;

	bool isNight;

	int time;
	int three_M;
	int assnCheck[8];
	int testCheck[2];

	int SportFriend;
	int TopFriend;
	bool Lover;
	int Senior;
	int DrunkenFriend;

	int k_midterm;
	int k_finalterm;

	int startassn;
	int mulassn;

	QTimer *GameTimer;
	QTimer *MainTimer;
	Player *onPlayer;
	Assignment **Assignmentlist;
	Test **Testlist;
	Building **BuildingList;
	Friend **FriendList;
	Environment *nowEnvironment;
	bool giveAssn;
	qreal InclineLonely;
	qreal DeclineHealth;
	qreal InclineFinance;
	Map *ParentMap;
	BuildWhat *MenuBar;

public slots:
	void StartClock();
	void StartGame();
	void TakeGold();
	void OKalert();
	void OKBldgAlert(QString type);
	void BACKalert();
	void NoSleep();
	void CloseEngineering();
	void CloseTA();
	void CloseFL();

	void NothingInGym();
	void NothingInCaf();
	void NothingInMar();
	void NothingInLog();
	void NothingInStu();
	void NothingInLib();
	void NothingInLab();
	void NoBuild();
	void BuildCafeteria();
	void BuildMarket();
	void BuildGym();
	void BuildLaborBuilding();
	void BuildLibrary();
	void BuildLogHouse();
	void BuildStudentHall();



	void DoExer();
	void DoStudy();
	void DoWork();
	void Sleep();
	void EatinCaf(int T);
	void DrinkinMarket(int T);
	void EatinLogHouse(int T);
	void ClubActivity(int T);

	void MakeDF();
	void MakeS();
	void MakeSF();
	void MakeTF();
	void MakeLO();

};