#include "FriendList.h"
#include "ManageGame.h"
#include "Assignment.h"
#include "Test.h"
#include "Map.h"

FriendList::FriendList(ManageGame *Game, QWidget *parent) : QLabel(parent){


	onGoingGame = Game;
	resize(660, 450);
	DrunkenFriend = new QPainter*[4];
	Senior = new QPainter*[3];
	SportFriend = new QPainter*[3];
	TopFriend = new QPainter*[3];
	Lover = new QPainter*[3];

	for(int i = 0; i<3; i++){
		DrunkenFriend[i] = new QPainter(this);
		Senior[i] = new QPainter(this);
		SportFriend[i] = new QPainter(this);
		TopFriend[i] = new QPainter(this);
		Lover[i] = new QPainter(this);
	}
	DrunkenFriend[3] = new QPainter(this);


	font = new QFont( "Resources/NanumBarunGothic.ttp");
	font->setKerning( true );
	font->setBold( true );
	font->setPixelSize( 20 );

	testfont = new QFont( "Resources/NanumBarunGothic.ttp");
	testfont->setKerning( true );
	testfont->setBold( true );
	testfont->setPixelSize( 30 );


	Back = new QPushButton(this);
	Back->setGeometry(QRect(510, 380, 140, 63));
	QIcon BackIcon;
    BackIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/GoBack_InGame.png")), QIcon::Normal, QIcon::Off);
	Back->setIcon(BackIcon);
	Back->setIconSize(QSize(130, 59));
	Back->setFlat(true);
	Back->show();

	show();

	repaint();
	QObject::connect(Back, SIGNAL(clicked()), onGoingGame,SLOT(CloseFL()));
	
	
	
	
	
	
	
	
}


void FriendList::paintEvent(QPaintEvent*){

	QString Num;
	QString sol;
	
	DrunkenFriend[0]->begin(this);
	DrunkenFriend[0]->setFont(*font);
	DrunkenFriend[0]->drawText(100, 100, Num.setNum(onGoingGame->getDF()));
	DrunkenFriend[0]->end();

	DrunkenFriend[1]->begin(this);
	DrunkenFriend[1]->setFont(*font);
	DrunkenFriend[1]->drawText(400, 80, Num.setNum(onGoingGame->getDF()*0.2));
	DrunkenFriend[1]->end();

	DrunkenFriend[2]->begin(this);
	DrunkenFriend[2]->setFont(*font);
	DrunkenFriend[2]->drawText(400, 100, Num.setNum(onGoingGame->getDF()*0.2));
	DrunkenFriend[2]->end();

	DrunkenFriend[3]->begin(this);
	DrunkenFriend[3]->setFont(*font);
	DrunkenFriend[3]->drawText(400, 120, Num.setNum(onGoingGame->getDF()*0.2));
	DrunkenFriend[3]->end();

	Senior[0]->begin(this);
	Senior[0]->setFont(*font);
	Senior[0]->drawText(100, 170, Num.setNum(onGoingGame->getS()));
	Senior[0]->end();

	Senior[1]->begin(this);
	Senior[1]->setFont(*font);
	Senior[1]->drawText(400, 160, Num.setNum(onGoingGame->getS()*1));
	Senior[1]->end();

	Senior[2]->begin(this);
	Senior[2]->setFont(*font);
	Senior[2]->drawText(400, 180, Num.setNum(onGoingGame->getS()*0.1));
	Senior[2]->end();

	SportFriend[0]->begin(this);
	SportFriend[0]->setFont(*font);
	SportFriend[0]->drawText(100, 240, Num.setNum(onGoingGame->getSF()));
	SportFriend[0]->end();

	SportFriend[1]->begin(this);
	SportFriend[1]->setFont(*font);
	SportFriend[1]->drawText(400, 230, Num.setNum(onGoingGame->getSF()*0.01));
	SportFriend[1]->end();

	SportFriend[2]->begin(this);
	SportFriend[2]->setFont(*font);
	SportFriend[2]->drawText(400, 250, Num.setNum(onGoingGame->getSF()*0.5));
	SportFriend[2]->end();

	TopFriend[0]->begin(this);
	TopFriend[0]->setFont(*font);
	TopFriend[0]->drawText(100, 310, Num.setNum(onGoingGame->getTF()));
	TopFriend[0]->end();

	TopFriend[1]->begin(this);
	TopFriend[1]->setFont(*font);
	TopFriend[1]->drawText(400, 300, Num.setNum(onGoingGame->getTF()*0.5));
	TopFriend[1]->end();

	TopFriend[2]->begin(this);
	TopFriend[2]->setFont(*font);
	TopFriend[2]->drawText(400, 320, Num.setNum(onGoingGame->getTF()*5));
	TopFriend[2]->end();

	Lover[0]->begin(this);
	Lover[0]->setFont(*font);
	Lover[0]->drawText(100, 380, Num.setNum(onGoingGame->getL()));
	Lover[0]->end();

	Lover[1]->begin(this);
	Lover[1]->setFont(*font);
	Lover[1]->drawText(100, 380, Num.setNum(onGoingGame->getL()*0.2));
	Lover[1]->end();
	
}

