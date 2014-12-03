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

class InMarket : public QWidget{

	Q_OBJECT

public:
	InMarket(ManageGame *Game, QWidget *parent = 0);
	void ReDraw();
protected:

	ManageGame *onGoingGame;
	QLabel *Screen;
	QPushButton *OK;
	QPushButton *UpgradeButton;
	QPushButton *Drink1_Button;
	QPushButton *Drink2_Button;
	QPushButton *Drink3_Button;
	QPushButton *BackButton;
	AskAlert *askalert;
	NormalAlert *normalalert;

public slots:
	void setDrink1Alert();
	void setDrink2Alert();
	void setDrink3Alert();
	void DeleteAskAlert();
	void DeleteNormalAlert();
	void setNormalAlert(QString Name);
	void setMar_Upgrade_Alert();

};