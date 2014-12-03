#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QFont>

class ManageGame;
class Map;

class AskAlert : public QWidget{

	Q_OBJECT

public:
	AskAlert(ManageGame *Game, QString Name, QWidget *parent = 0);

private:
	void paintEvent(QPaintEvent *event);
	ManageGame *onGoingGame;
	QPushButton *Yes;
	QPushButton *No;
	QLabel *askalert;
	QString BuildingName;
	QPainter *ask;
	QFont *font;


public slots:
	void EatB();
	void EatC();
	void EatD();
	void Drink1();
	void Drink2();
	void Drink3();
	void LogA();
	void LogB();
	void LogC();
	void ClubA();
	void ClubB();
	void ClubC();
};