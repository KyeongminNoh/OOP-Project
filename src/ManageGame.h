#include <QPushButton>
#include <QGridLayout>
#include <QTime>
#include <QTimer>
#include <QLabel>
#include <QWidget>
#include <QFont>
#include <QPainter>

#define LABORB_COST 20
#define STUHALL_COST 20
#define GYM_COST 20
#define LOGHOUSE_COST 20
#define LIBRARY_COST 20
#define MARKET_COST 30


class Player;
class Building;
class Friend;
class Environment;
class Map;
class BuildWhat;


class ManageGame : public QWidget {

	Q_OBJECT

public:
	ManageGame( int isMan, int isDayPerson, Map *map, BuildWhat *MB,QWidget *parent = 0);

	Building* getBuilding(int i);
	void SetStrings();
	void Build();
	void change_status();
	void change_InclineLonely(qreal d);
	void change_DeclineHealth(qreal i);
	void change_InclineFinance(qreal i);
	Player* get_onPlayer(){ return onPlayer;}

private:
	void paintEvent(QPaintEvent *);
	
	QWidget *Parent;
	//QGridLayout *grid;
	QString s1, s2, s3, s4, g, st1, st2, st3, st4, gt;
	QLabel *Page;
	QPainter *showst;
	QPainter *showh;
	QPainter *showw;
	QPainter *showS;
	QPainter *showgold;
	QFont *font;
	QTime time;
	QTimer *GameTimer;
	QTimer *GoldTimer;
	Player *onPlayer;
	Building **BuildingList;
	Friend **FriendList;
	Environment *nowEnvironment;
	qreal InclineLonely;
	qreal DeclineHealth;
	qreal InclineFinance;
	Map *ParentMap;
	BuildWhat *MenuBar;

public slots:
	void StartGame();
	void TakeGold();
	void OKalert();
	void OKBldgAlert(QString type);
	void BACKalert();
	void NoSleep();

	void NothingInGym();
	void NothingInCaf();
	void NoBuild();
	void BuildCafeteria();
	void BuildMarket();
	void BuildGym();
	void BuildLaborBuilding();
	void BuildLibrary();
	void BuildLogHouse();
	void BuildStudentHall();



	void DoExer();
	void Sleep();
	void EatinCaf(int T);
//	void UpgradeGym();
//	void UpgradeMarket();
//	void UpgradeLaborBuilding();
//	void UpgradeLibrary();
//	void UpgradeLogHouse();
//	void UpgradeStudentHall();
};