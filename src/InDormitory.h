#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QFont>

class ManageGame;
class Map;

class InDormitory : public QWidget{

	Q_OBJECT

public:
	InDormitory(ManageGame *Game, QWidget *parent = 0);

private:
	void paintEvent(QPaintEvent *event);
	ManageGame *onGoingGame;
	QPushButton *Yes;
	QPushButton *No;
	QLabel *Screen;
	QString BuildingName;
	QPainter *ask;
	QFont *font;


public slots:

};