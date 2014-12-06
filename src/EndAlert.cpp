#include "EndAlert.h"

#include "FieldScene.h"

EndAlert::EndAlert(FieldScene* Field, QString Name, QWidget *parent) : QWidget(parent){
	field = Field;

	BuildingName = Name;
	resize(300, 225);

	QPixmap Image;
	if(BuildingName =="GameOver")
		Image.load(QString::fromUtf8("Resources/GameOver.png"));
	else if(BuildingName =="GoToMain")
		Image.load(QString::fromUtf8("Resources/AskGotoMain.png"));
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
	if(BuildingName =="GameOver")
		YesIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/GameOver_GoToMain.png")), QIcon::Normal, QIcon::Off);
	else if(BuildingName =="GoToMain")
		YesIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/Yes.png")), QIcon::Normal, QIcon::Off);

	Yes->setIcon(YesIcon);
	Yes->setIconSize(QSize(90, 36));
	Yes->setFlat(true);
	Yes->show();

	No = new QPushButton(askalert);
	No->setGeometry(QRect(170, 170, 100, 45));
	QIcon NoIcon;
	if(BuildingName =="GameOver")
		NoIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/GameOver_ExitGame.png")), QIcon::Normal, QIcon::Off);
	else if(BuildingName =="GoToMain")
		NoIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/No.png")), QIcon::Normal, QIcon::Off);
	No->setIcon(NoIcon);
	No->setIconSize(QSize(90, 36));
	No->setFlat(true);
	No->show();

	askalert->show();

	QObject::connect(Yes, SIGNAL(clicked()), SLOT(ClickYes()));
	if(BuildingName =="GameOver")
		QObject::connect(No, SIGNAL(clicked()), SLOT(ClickNo()));
	else if(BuildingName =="GoToMain")
		QObject::connect(No, SIGNAL(clicked()), SLOT(ClickNo2()));
	
}

void EndAlert::ClickNo(){
	field->ExitGame();
	//delete this;
}

void EndAlert::ClickNo2(){
	delete this;
}

void EndAlert::ClickYes(){
	field->ReturnStart();
	//delete this;
}