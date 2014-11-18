
#include <QLabel>
#include <QWidget>


class Building;
class Environment;

class Map : public QWidget {
	Q_OBJECT

public:
	Map(QWidget *parent = 0);

	void createGymImage(int level);
	void createLibraryImage(int level);
	void createMarketImage(int level);
	void createLaborBuilding(int level);
	void createLogHouseImage(int level);
	void createStudentHall(int level);
private:
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


};