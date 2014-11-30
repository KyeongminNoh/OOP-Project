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

class InCafeteria : public QWidget{

	Q_OBJECT

public:
	InCafeteria(ManageGame *Game, QWidget *parent = 0);
	void ReDraw();
protected:

	ManageGame *onGoingGame;
	QLabel *Screen;
	QPushButton *OK;
	QPushButton *UpgradeButton;
	QPushButton *EatB_Button;
	QPushButton *EatC_Button;
	QPushButton *EatD_Button;
	QPushButton *BackButton;
	AskAlert *askalert;
	NormalAlert *normalalert;

public slots:
	void setEatBAlert();
	void setEatCAlert();
	void setEatDAlert();
	void DeleteAskAlert();
	void DeleteNormalAlert();
	void setNormalAlert(QString Name);
	void setCaf_Upgrade_Alert();

};