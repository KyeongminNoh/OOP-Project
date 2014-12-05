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
	else if(alertType == "ECom1")
		Image.load(QString::fromUtf8("Resources/exercise1_notice.png"));
	else if(alertType == "ECom2")
		Image.load(QString::fromUtf8("Resources/exercise2_notice.png"));
	else if(alertType == "ECom3")
		Image.load(QString::fromUtf8("Resources/exercise3_notice.png"));
	else if(alertType == "Heal")
		Image.load(QString::fromUtf8("Resources/exercise_notice.png"));
	else if(alertType == "WHeal")
		Image.load(QString::fromUtf8("Resources/labor_notice.png"));
	else if(alertType == "SHeal")
		Image.load(QString::fromUtf8("Resources/study_notice.png"));
	else if(alertType == "UCom")
		Image.load(QString::fromUtf8("Resources/UpgradeComplete.png"));
	else if(alertType == "SCom1")
		Image.load(QString::fromUtf8("Resources/study1_notice.png"));
	else if(alertType == "SCom2")
		Image.load(QString::fromUtf8("Resources/study2_notice.png"));
	else if(alertType == "SCom3")
		Image.load(QString::fromUtf8("Resources/study3_notice.png"));
	else if(alertType == "WCom1")
		Image.load(QString::fromUtf8("Resources/labor1_notice.png"));
	else if(alertType == "WCom2")
		Image.load(QString::fromUtf8("Resources/labor2_notice.png"));
	else if(alertType == "WCom3")
		Image.load(QString::fromUtf8("Resources/labor3_notice.png"));
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

	else if( alertType == "Drink1")
		Image.load(QString::fromUtf8("Resources/market1_notice.png"));
	else if( alertType == "Drink2")
		Image.load(QString::fromUtf8("Resources/market2_notice.png"));
	else if( alertType == "Drink3")
		Image.load(QString::fromUtf8("Resources/market3_notice.png"));
	else if( alertType == "MarFin")
		Image.load(QString::fromUtf8("Resources/market_notice.png"));

	else if( alertType == "AeatL")
		Image.load(QString::fromUtf8("Resources/log1_notice.png"));
	else if( alertType == "BeatL")
		Image.load(QString::fromUtf8("Resources/log2_notice.png"));
	else if( alertType == "CeatL")
		Image.load(QString::fromUtf8("Resources/log3_notice.png"));
	else if( alertType == "logFin")
		Image.load(QString::fromUtf8("Resources/log_notice.png"));

	else if( alertType == "clubA")
		Image.load(QString::fromUtf8("Resources/clubA_notice.png"));
	else if( alertType == "clubB")
		Image.load(QString::fromUtf8("Resources/clubB_notice.png"));
	else if( alertType == "clubC")
		Image.load(QString::fromUtf8("Resources/clubC_notice.png"));
	else if( alertType == "stuHea")
		Image.load(QString::fromUtf8("Resources/club_notice.png"));

	else if(alertType == "Solve")
		Image.load(QString::fromUtf8("Resources/SummitAssn.png"));
	else if(alertType == "lowKnow")
		Image.load(QString::fromUtf8("Resources/shortKnowledge.png"));
	else if(alertType == "Due")
		Image.load(QString::fromUtf8("Resources/LateAssn.png"));

	else if(alertType == "Over")
		Image.load(QString::fromUtf8("Resources/GameOver.png"));

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
