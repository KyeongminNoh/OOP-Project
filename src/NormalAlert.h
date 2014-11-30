#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QFont>

class ManageGame;
class Map;

class NormalAlert : public QWidget{

	Q_OBJECT

public:
	NormalAlert(ManageGame *Game, QString Name, QString Canvas ,QWidget *parent = 0);

private:
	void paintEvent(QPaintEvent *event);
	ManageGame *onGoingGame;
	QPushButton *OK;
	QLabel *normalalert;
	QString alertType;
	QString canvas;
	QFont *font;


public slots:
	void SendOK();
};