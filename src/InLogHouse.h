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

class InLogHouse : public QWidget{

	Q_OBJECT

public:
	InLogHouse(ManageGame *Game, QWidget *parent = 0);
	void ReDraw();
protected:

	ManageGame *onGoingGame;
	QLabel *Screen;
	QPushButton *OK;
	QPushButton *UpgradeButton;
	QPushButton *LogA_Button;
	QPushButton *LogB_Button;
	QPushButton *LogC_Button;
	QPushButton *BackButton;
	AskAlert *askalert;
	NormalAlert *normalalert;

public slots:
	void setLogAAlert();
	void setLogBAlert();
	void setLogCAlert();
	void DeleteAskAlert();
	void DeleteNormalAlert();
	void setNormalAlert(QString Name);
	void setMar_Upgrade_Alert();

};