#include <QTimer>
#include <QLabel>
#include <QWidget>
#include <QPushButton>

class FieldScene;
class ManageGame;
class Building;
class Environment;
class AskAlert;
class NormalAlert;
class InGym;
class InDormitory;
class InEngineering;
class InCafeteria;
class InMarket;
class InLogHouse;
class InLibrary;
class InStudentHall;
class InLabor;
class TestAssn;
class FriendList;
class Semester;
class EndAlert;
class GradeReport;

//enum MouseFunction { MOUSE_MOVE, MOUSE_CLICK, MOUSE_DOWN, MOUSE_DRAG, MOUSE_UP };
//enum { CLICK_MOUSE_MOVE_RANGE = 6 };

class Map : public QWidget {
	Q_OBJECT

public:
	Map(bool Man, FieldScene *Field,int isSemester, QWidget *parent = 0);

	void SetScreen(bool isNight);
	bool NowActing(){return nowActing;}
	void SetActing(bool A){nowActing = A;}

	Semester* get_nowSemester(){ return nowSemester;}
	InGym* getInGym();
	InCafeteria* getInCafeteria();
	InMarket *getInMarket();
	InLogHouse *getInLogHouse();
	InStudentHall *getInStudentHall();
	InLibrary *getInLibrary();
	InLabor *getInLabor();

	TestAssn* getTA();
	FriendList* getFList();



	void setEndAlert(QString name);
	void setNormalAlert(QString name);
	void setManageGame(ManageGame *Game);
	ManageGame* getOnGoingGame(){return onGoingGame;};
	AskAlert* getAskAlert(){return askalert;};
	void DeleteAskAlert();
	void DeleteNormalAlert();
	void DeleteInBldg();
	void DeleteInDormitory();
	void DeleteInLibrary();
	void DeleteInEngineering();
	void DeleteInLabor();

	void DeleteTA();
	void DeleteFList();

	//void DeleteInCafeteria();
	void SetFriend();

	void createGymImage(int level);
	void createLibraryImage(int level);
	void createMarketImage(int level);
	void createLaborBuilding(int level);
	void createLogHouseImage(int level);
	void createStudentHall(int level);
private:
	qreal x, y, px, py;
	//int time, stoptime;

	QTimer *Timer;

	bool nowActing;

	FieldScene *field;

	Semester *nowSemester;
	ManageGame *onGoingGame;
	NormalAlert *normalalert;
	AskAlert *askalert;
	EndAlert *endalert;

	InGym *Inbuildingalert;
	InDormitory *indormitory;
	InEngineering *inengineering;
	InCafeteria *incafeteria;
	InMarket *inmarket;
	InLogHouse *inloghouse;
	InStudentHall *instudenthall;
	InLibrary *inlibrary;
	InLabor *inlabor;

	QLabel *Screen;
	TestAssn *TA;
	FriendList *FL;

	QLabel *nowEnvironment;
	QLabel *nowPlayer;

	QPushButton *GymImage;
	QPushButton *DormitoryImage;
	QPushButton *EngineeringImage;
	QPushButton *CafeteriaImage;
	QPushButton *LogHouseImage;
	QPushButton *LaborBuildingImage;
	QPushButton *StudentHallImage;
	QPushButton *MarketImage;
	QPushButton *LibraryImage;

	QPushButton *Home;

	QPushButton *Friend;
	int FriendType;

	GradeReport* card;

	QLabel *Session1;

public slots:
	//void mousePressEvent(QMouseEvent *event);
	void setGymAlert();
	void setLibAlert();
	void setLabAlert();
	void setLogAlert();
	void setStuAlert();
	void setMarAlert();

	void setAskBack();


	void ResetPlayer();
	void MoveToEngineering();
	void MoveToCafeteria();
	void MoveToGym();
	void MoveToLaborBuilding();
	void MoveToDormitory();
	void MoveToStudentHall();
	void MoveToLogHouse();
	void MoveToLibrary();
	void MoveToMarket();

	void MoveToDrunkenFriend();
	void MoveToSenior();
	void MoveToSportFriend();
	void MoveToTopFriend();
	void MoveToLover();

	void MovePlayer();
	void DeleteTimer();

	void setExerAlert();
	void setGym_Upgrade_Alert();

	void setStudyAlert();
	void setLib_Upgrade_Alert();

	void setWorkAlert();
	void setLab_Upgrade_Alert();

	void setInCafeteria();
	void setInDormitory();
	void setInEngineering();
	void setInGym();
	void setInMarket();
	void setInLogHouse();
	void setInStudentHall();
	void setInLibrary();
	void setInLabor();

	void setGR();
	void setTA();
	void setFList();
	void DeleteFriend();
	void MakeFriend();
};
