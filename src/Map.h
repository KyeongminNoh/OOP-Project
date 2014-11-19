
#include <QLabel>
#include <QWidget>
#include <QPushButton>

class ManageGame;
class Building;
class Environment;
class AskAlert;
class NormalAlert;

class Map : public QWidget {
	Q_OBJECT

public:
	Map(QWidget *parent = 0);
	void setNormalAlert(QString name);
	void setManageGame(ManageGame *Game);
	ManageGame* getOnGoingGame(){return onGoingGame;};
	AskAlert* getAskAlert(){return askalert;};
	void DeleteAskAlert();
	void DeleteNormalAlert();
	void createGymImage(int level);
	void createLibraryImage(int level);
	void createMarketImage(int level);
	void createLaborBuilding(int level);
	void createLogHouseImage(int level);
	void createStudentHall(int level);
private:
	ManageGame *onGoingGame;
	NormalAlert *normalalert;
	AskAlert *askalert;
	QLabel *GymImage;
	QLabel *DormitoryImage;
	QLabel *EngineeringImage;
	QLabel *CafeteriaImage;
	QLabel *nowEnvironment;
	QLabel *LogHouseImage;
	QLabel *LaborBuildingImage;
	QLabel *StudentHallImage;
	QLabel *MarketImage;
	QLabel *LibraryImage;
	QLabel *Session1;

public slots:
	void setGymAlert();
	void setLibAlert();
	void setLabAlert();
	void setLogAlert();
	void setStuAlert();
	void setMarAlert();


};