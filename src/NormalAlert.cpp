#include "NormalAlert.h"
#include "ManageGame.h"
#include "Map.h"

NormalAlert::NormalAlert(ManageGame *Game, QString Name, QWidget *parent) : QWidget(parent){

	alertType = Name;
	onGoingGame = Game;
	resize(300, 200);

	QPixmap Image;
	
	if(alertType == "Fin")
		Image.load(QString::fromUtf8("Resources/FinancialAlert.png"));
	else if(alertType == "BCom")
		Image.load(QString::fromUtf8("Resources/BuildComplete.png"));

	normalalert = new QLabel(this);
	normalalert->resize(300, 200);
	normalalert->setGeometry(QRect(0, 0, 300, 200));
	normalalert->setPixmap(Image);

	font = new QFont( "Resources/NanumBarunGothic.ttp");
	font->setKerning( true );
	font->setBold( true );
	font->setPixelSize( 20 );

	
	OK = new QPushButton(normalalert);
	OK->setText("OK");
	OK->resize(100, 50);
	OK->setGeometry(QRect(100, 125, 100, 50));

	normalalert->show();


	QObject::connect(OK, SIGNAL(clicked()), onGoingGame, SLOT(OKalert()));
}


void NormalAlert::paintEvent(QPaintEvent *event){

	
}
