#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QFont>


class ManageGame;
class Map;
class AskAlert;
class NormalAlert;

class InGym : public QWidget{

	Q_OBJECT

public:
	InGym(ManageGame *Game, QWidget *parent = 0);
	void ReDraw();
protected:

	ManageGame *onGoingGame;
	QLabel *Screen;
	QPushButton *OK;
	AskAlert *askalert;
	NormalAlert *normalalert;

public slots:
	void DeleteAskAlert();
	void DeleteNormalAlert();
	void setNormalAlert(QString Name);
	void setGym_Upgrade_Alert();
	void setExerAlert();
};