#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QFont>

class ManageGame;
class Map;
class FieldScene;
class Semester;

class GradeReport : public QLabel{

	Q_OBJECT

public:
	GradeReport(ManageGame *Game, Semester* S,FieldScene* F,QWidget *parent = 0);

private:
	void paintEvent(QPaintEvent*);
	ManageGame *onGoingGame;
	QPushButton *GoMain, *ExitGame;
	QIcon SolveIcon;
	QLabel *Screen;
	QPainter **Grade;
	QPainter *Total;
	
	QFont *font, *font2;
	FieldScene* field;
	Semester* semester;
public slots:

	void ClickNo();
	void ClickYes();

};