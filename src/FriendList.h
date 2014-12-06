#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QFont>

class ManageGame;
class Map;

class FriendList : public QLabel{

	Q_OBJECT

public:
	FriendList(ManageGame *Game, QWidget *parent = 0);

private:
	void paintEvent(QPaintEvent*);
	ManageGame *onGoingGame;
	QPushButton *Back;
	QIcon SolveIcon;
	QLabel *Screen;
	QPainter **DrunkenFriend, **Senior, **SportFriend, **TopFriend, **Lover;
	
	QFont *font, *testfont;


public slots:



};