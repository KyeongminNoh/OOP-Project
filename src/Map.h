#include <QTimer>
#include <QLabel>
#include <QWidget>
#include <QPushButton>

class ManageGame;
class Building;
class Environment;
class AskAlert;
class NormalAlert;
class InGym;
class InDormitory;
class InCafeteria;

//enum MouseFunction { MOUSE_MOVE, MOUSE_CLICK, MOUSE_DOWN, MOUSE_DRAG, MOUSE_UP };
//enum { CLICK_MOUSE_MOVE_RANGE = 6 };

class Map : public QWidget {
	Q_OBJECT

public:
	Map(bool Man, QWidget *parent = 0);
	InGym* getInGym();
	InCafeteria* getInCafeteria();

	void setNormalAlert(QString name);
	void setManageGame(ManageGame *Game);
	ManageGame* getOnGoingGame(){return onGoingGame;};
	AskAlert* getAskAlert(){return askalert;};
	void DeleteAskAlert();
	void DeleteNormalAlert();
	void DeleteInBldg();
	void DeleteInDormitory();
	//void DeleteInCafeteria();
	void createGymImage(int level);
	void createLibraryImage(int level);
	void createMarketImage(int level);
	void createLaborBuilding(int level);
	void createLogHouseImage(int level);
	void createStudentHall(int level);
private:
	qreal x, y, px, py;
	int time, stoptime;

	QTimer *Timer;

	ManageGame *onGoingGame;
	NormalAlert *normalalert;
	AskAlert *askalert;
	InGym *Inbuildingalert;
	InDormitory *indormitory;
	InCafeteria *incafeteria;

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
	QLabel *Session1;

public slots:
	//void mousePressEvent(QMouseEvent *event);
	void setGymAlert();
	void setLibAlert();
	void setLabAlert();
	void setLogAlert();
	void setStuAlert();
	void setMarAlert();


	void ResetPlayer();
	void MoveToEngineering();
	void MoveToCafeteria();
	void MoveToGym();
	void MoveToLaborBuilding();
	void MoveToDormitory();
	void MoveToStudentHall();
	void MoveToLogHouse();
	void MoveToLibrary();
	void MovePlayer();
	void DeleteTimer();

	void setExerAlert();
	void setGym_Upgrade_Alert();


	void setInCafeteria();
	void setInDormitory();
	void setInGym();
};
