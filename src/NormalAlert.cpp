#include "NormalAlert.h"
#include "ManageGame.h"
#include "Map.h"

NormalAlert::NormalAlert(ManageGame *Game, QString Name, QString Canvas ,QWidget *parent) : QWidget(parent){

	alertType = Name;
	canvas = Canvas;
	onGoingGame = Game;
	resize(300, 150);

	QPixmap Image;
	normalalert = new QLabel(this);
	normalalert->setScaledContents(true);
	normalalert->setGeometry(QRect(0, 0, 300, 150));

	if(alertType == "Fin")
		Image.load(QString::fromUtf8("Resources/FinancialAlert.png"));
	else if(alertType == "BCom")
		Image.load(QString::fromUtf8("Resources/BuildComplete.png"));
	else if(alertType == "ECom")
		Image.load(QString::fromUtf8("Resources/BuildComplete.png"));
	else if(alertType == "Heal")
		Image.load(QString::fromUtf8("Resources/HealthAlert.png"));
	else if(alertType == "UCom")
		Image.load(QString::fromUtf8("Resources/UpgradeComplete.png"));
	else if(alertType == "Sleep"){
		Image.load(QString::fromUtf8("Resources/Dorm2.png"));
		resize(660, 450);
		normalalert->setGeometry(QRect(0, 0, 660, 450));
	}
	else if( alertType == "CTSleep"){
		Image.load(QString::fromUtf8("Resources/Dorm3.png"));
		resize(660, 450);
		normalalert->setGeometry(QRect(0, 0, 660, 450));
	}
	else if( alertType == "Beat")
		Image.load(QString::fromUtf8("Resources/B_notice.png"));
	else if( alertType == "Ceat")
		Image.load(QString::fromUtf8("Resources/C_notice.png"));
	else if( alertType == "Deat")
		Image.load(QString::fromUtf8("Resources/D_notice.png"));
	
	normalalert->setPixmap(Image);

	font = new QFont( "Resources/NanumBarunGothic.ttp");
	font->setKerning( true );
	font->setBold( true );
	font->setPixelSize( 20 );

	
	OK = new QPushButton(normalalert);
	OK->setGeometry(QRect(100, 90, 100, 50));
	QIcon OKIcon;
    OKIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/OK.png")), QIcon::Normal, QIcon::Off);
	OK->setIcon(OKIcon);
	OK->setIconSize(QSize(90, 36));
	if(alertType == "Sleep" || alertType == "CTSleep"){
		OK->setGeometry(QRect(260, 320, 140, 70));
		OK->setIconSize(QSize(130, 65));
	}
	OK->setFlat(true);
	OK->show();

	normalalert->show();

	if(canvas == "map")
		QObject::connect(OK, SIGNAL(clicked()), onGoingGame, SLOT(OKalert()));
	else{
		QObject::connect(OK, SIGNAL(clicked()), SLOT(SendOK()));
	}
}


void NormalAlert::paintEvent(QPaintEvent *event){

	
}

void NormalAlert::SendOK(){
	onGoingGame->OKBldgAlert(canvas);
}
