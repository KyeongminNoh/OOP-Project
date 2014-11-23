#include "NormalAlert.h"
#include "ManageGame.h"
#include "Map.h"

NormalAlert::NormalAlert(ManageGame *Game, QString Name, QWidget *parent) : QWidget(parent){

	alertType = Name;
	onGoingGame = Game;
	resize(300, 150);

	QPixmap Image;
	
	if(alertType == "Fin")
		Image.load(QString::fromUtf8("Resources/FinancialAlert.png"));
	else if(alertType == "BCom")
		Image.load(QString::fromUtf8("Resources/BuildComplete.png"));
	else if(alertType == "Ecom")
		Image.load(QString::fromUtf8("Resources/ExerciseComplete.png"));
	else if(alertType == "Heal")
		Image.load(QString::fromUtf8("Resources/HealthAlert.png"));


	normalalert = new QLabel(this);
	normalalert->setScaledContents(true);
	normalalert->setGeometry(QRect(0, 0, 300, 150));
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
	OK->setFlat(true);
	OK->show();

	normalalert->show();


	QObject::connect(OK, SIGNAL(clicked()), onGoingGame, SLOT(OKalert()));
}


void NormalAlert::paintEvent(QPaintEvent *event){

	
}
