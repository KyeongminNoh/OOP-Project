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

class InStudentHall : public QWidget{

	Q_OBJECT

public:
	InStudentHall(ManageGame *Game, QWidget *parent = 0);
	void ReDraw();
protected:

	ManageGame *onGoingGame;
	QLabel *Screen;
	QPushButton *OK;
	QPushButton *UpgradeButton;
	QPushButton *clubA_Button;
	QPushButton *clubB_Button;
	QPushButton *clubC_Button;
	QPushButton *BackButton;
	AskAlert *askalert;
	NormalAlert *normalalert;

public slots:
	void setclubAAlert();
	void setclubBAlert();
	void setclubCAlert();
	void DeleteAskAlert();
	void DeleteNormalAlert();
	void setNormalAlert(QString Name);
	void setMar_Upgrade_Alert();

};