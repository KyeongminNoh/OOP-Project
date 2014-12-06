#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QFont>

class ManageGame;
class FieldScene;

class EndAlert : public QWidget{

	Q_OBJECT

public:
	EndAlert(FieldScene *field, QString Name, QWidget *parent = 0);

private:

	ManageGame *onGoingGame;
	QPushButton *Yes;
	QPushButton *No;
	QLabel *askalert;
	QString BuildingName;
	QPainter *ask;
	QFont *font;
	FieldScene *field;


public slots:
	void ClickNo();
	void ClickYes();
	void ClickNo2();
};