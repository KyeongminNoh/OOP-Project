#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QFont>

class ManageGame;
class Map;

class InBuilding : public QWidget{

	Q_OBJECT

public:
	InBuilding(ManageGame *Game, QWidget *parent = 0);
protected:
	ManageGame *onGoingGame;
	QLabel *Screen;

public slots:

};