#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QFont>

class ManageGame;
class Map;
class LoadScene;
class Semester;

class GradeTable : public QLabel{

	Q_OBJECT

public:
	GradeTable(LoadScene *S, int *arr,QWidget *parent = 0);

private:
	void paintEvent(QPaintEvent*);
	ManageGame *onGoingGame;
	QPushButton *backButton;
	QLabel *screen;
	QIcon SolveIcon;
	LoadScene *LS;
	QPainter **grading;
	QPainter *Total;
	int *grade;
	QFont *font;
	Semester* semester;
public slots:

	void ClickYes();

};