#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QFont>

class ManageGame;
class Map;

class InbuildingAlert : public QWidget{

	Q_OBJECT

public:
	InbuildingAlert(ManageGame *Game, QString Name, QWidget *parent = 0);
	void InGym(ManageGame *Game);
private:
//	void paintEvent(QPaintEvent *event);
	ManageGame *onGoingGame;
	QPushButton *OK;
	QLabel *Inbuildingalert;
	QString alertType;
	QFont *font;


public slots:

};