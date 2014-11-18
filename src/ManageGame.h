#include <QGridLayout>
#include <QTime>
#include <QTimer>
#include <QLabel>
#include <QWidget>
#include <QFont>
#include <QPainter>

#define LABORB_COST 500
#define STUHALL_COST 500
#define GYM_COST 500
#define LOGHOUSE_COST 500
#define LIBRARY_COST 500
#define MARKET_COST 500

class Player;
class Building;
class Friend;
class Environment;
class Map;


class ManageGame : public QWidget {

	Q_OBJECT

public:
	ManageGame( int isMan, int isDayPerson, Map *map, QWidget *parent = 0);

	void SetStrings();
	void Build();
	void change_status();
	void change_InclineLonely(qreal d);
	void change_DeclineHealth(qreal i);
	Player* get_onPlayer(){ return onPlayer;}

private:
	void paintEvent(QPaintEvent *);
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

public slots:
	void StartGame();
	void TakeGold();
	void BuildMarket();
	void BuildGym();
	void BuildLaborBuilding();
	void BuildLibrary();
	void BuildLogHouse();
	void BuildStudentHall();

};