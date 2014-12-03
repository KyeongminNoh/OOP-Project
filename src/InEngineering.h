#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QFont>

class ManageGame;
class Map;

class InEngineering : public QWidget{

	Q_OBJECT

public:
	InEngineering(ManageGame *Game, QWidget *parent = 0);

private:
	void paintEvent(QPaintEvent *event);
	ManageGame *onGoingGame;
	QPushButton *OK;
	QLabel *Screen;
	QString BuildingName;
	QPainter *ask;
	QFont *font;


public slots:

};