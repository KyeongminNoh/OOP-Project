#include "EndAlert.h"

#include "FieldScene.h"

EndAlert::EndAlert(FieldScene* Field, QString Name, QWidget *parent) : QWidget(parent){
	field = Field;

	BuildingName = Name;
	resize(300, 225);

	QPixmap Image;
	
	Image.load(QString::fromUtf8("Resources/AskGym.png"));

	askalert = new QLabel(this);
	askalert->setScaledContents(true);
	askalert->setGeometry(QRect(0, 0, 300, 225));
	askalert->setPixmap(Image);

	font = new QFont( "Resources/NanumBarunGothic.ttp");
	font->setKerning( true );
	font->setBold( true );
	font->setPixelSize( 20 );

	
	Yes = new QPushButton(askalert);
	Yes->setGeometry(QRect(30, 170, 100, 45));
	QIcon YesIcon;
    YesIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/Yes.png")), QIcon::Normal, QIcon::Off);
	Yes->setIcon(YesIcon);
	Yes->setIconSize(QSize(90, 36));
	Yes->setFlat(true);
	Yes->show();
	No = new QPushButton(askalert);
	No->setGeometry(QRect(170, 170, 100, 45));
	QIcon NoIcon;
    NoIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/No.png")), QIcon::Normal, QIcon::Off);
	No->setIcon(NoIcon);
	No->setIconSize(QSize(90, 36));
	No->setFlat(true);
	No->show();

	askalert->show();

	QObject::connect(Yes, SIGNAL(clicked()), SLOT(ClickYes()));

	QObject::connect(No, SIGNAL(clicked()), SLOT(ClickNo()));
	
}

void EndAlert::ClickNo(){
	field->ExitGame();
	//delete this;
}

void EndAlert::ClickYes(){
	field->ReturnStart();
	//delete this;
}