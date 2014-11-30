#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class Map;

class BuildWhat : public QWidget{

	Q_OBJECT

public:
	BuildWhat(Map *map, QWidget *parent=0);
	QPushButton *gym;
	QPushButton *lib;
	QPushButton *logH;
	QPushButton *stu;
	QPushButton *lab;
	QPushButton *mar;

	void setGymInactive();
	void setLibInactive();
	void setLogInactive();
	void setStuInactive();
	void setLabInactive();
	void setMarInactive();

private:
	Map *nowmap;
	QVBoxLayout *Menu;

public slots:
	void setGymIcon();
	void setLibIcon();
	void setLogIcon();
	void setStuIcon();
	void setLabIcon();
	void setMarIcon();
	void resetIcon();

	
};