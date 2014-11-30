#include "InDormitory.h"
#include "ManageGame.h"
#include "Map.h"

InDormitory::InDormitory(ManageGame *Game, QWidget *parent) : QWidget(parent){


	onGoingGame = Game;
	resize(660, 450);

	QPixmap Image;
	
	
	Image.load(QString::fromUtf8("Resources/Dorm1.png"));
	

	Screen = new QLabel(this);
	Screen->setScaledContents(true);
	Screen->setGeometry(QRect(0, 0, 660, 450));
	Screen->setPixmap(Image);

	font = new QFont( "Resources/NanumBarunGothic.ttp");
	font->setKerning( true );
	font->setBold( true );
	font->setPixelSize( 20 );

	
	Yes = new QPushButton(Screen);
	Yes->setGeometry(QRect(160, 320, 140, 63));
	QIcon YesIcon;
    YesIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/Yes.png")), QIcon::Normal, QIcon::Off);
	Yes->setIcon(YesIcon);
	Yes->setIconSize(QSize(130, 59));
	Yes->setFlat(true);
	Yes->show();
	No = new QPushButton(Screen);
	No->setGeometry(QRect(360, 320, 140, 63));
	QIcon NoIcon;
    NoIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/No.png")), QIcon::Normal, QIcon::Off);
	No->setIcon(NoIcon);
	No->setIconSize(QSize(130, 59));
	No->setFlat(true);
	No->show();

	Screen->show();

	QObject::connect(Yes, SIGNAL(clicked()), onGoingGame,SLOT(Sleep()));


	QObject::connect(No, SIGNAL(clicked()), onGoingGame, SLOT(NoSleep()));
}


void InDormitory::paintEvent(QPaintEvent *event){
	ask = new QPainter(this);

	QString question, B;
	question.append("Do you want Build");
	
}