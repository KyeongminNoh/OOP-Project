#include "InEngineering.h"
#include "ManageGame.h"
#include "Map.h"

InEngineering::InEngineering(ManageGame *Game, QWidget *parent) : QWidget(parent){


	onGoingGame = Game;
	resize(660, 450);

	QPixmap Image;
	
	for(int i =0; i<8; i++){
		if(onGoingGame->getAssn(i) == 1){
			Image.load(QString::fromUtf8("Resources/Engineering1.png"));
			onGoingGame->setAssn(i);
			break;
		}
		else
			Image.load(QString::fromUtf8("Resources/Engineering2.png"));
	}

	Screen = new QLabel(this);
	Screen->setScaledContents(true);
	Screen->setGeometry(QRect(0, 0, 660, 450));
	Screen->setPixmap(Image);

	font = new QFont( "Resources/NanumBarunGothic.ttp");
	font->setKerning( true );
	font->setBold( true );
	font->setPixelSize( 20 );

	
	OK = new QPushButton(Screen);
	OK->setGeometry(QRect(260, 320, 140, 63));
	QIcon OKIcon;
    OKIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/OK.png")), QIcon::Normal, QIcon::Off);
	OK->setIcon(OKIcon);
	OK->setIconSize(QSize(130, 59));
	OK->setFlat(true);
	OK->show();


	Screen->show();

	QObject::connect(OK, SIGNAL(clicked()), onGoingGame, SLOT(CloseEngineering()));



}


void InEngineering::paintEvent(QPaintEvent *event){
	ask = new QPainter(this);

	QString question, B;
	question.append("Do you want Build");
	
}