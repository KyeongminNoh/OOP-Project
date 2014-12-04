#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QFont>

class ManageGame;
class Map;

class TestAssn : public QLabel{

	Q_OBJECT

public:
	TestAssn(ManageGame *Game, QWidget *parent = 0);

private:
	void paintEvent(QPaintEvent*);
	ManageGame *onGoingGame;
	QPushButton *Back;
	QPushButton *Solve1, *Solve2, *Solve3, *Solve4, *Solve5, *Solve6, *Solve7, *Solve8;
	QLabel *Screen;
	QPainter *Assn1, *Assn2, *Assn3, *Assn4, *Assn5, *Assn6, *Assn7, *Assn8, *Midterm, *Final;
	QFont *font;


public slots:
	void SolveA1();
	void SolveA2();
	void SolveA3();
	void SolveA4();
	void SolveA5();
	void SolveA6();
	void SolveA7();
	void SolveA8();



};