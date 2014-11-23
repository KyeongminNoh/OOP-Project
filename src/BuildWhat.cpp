#include "BuildWhat.h"
#include <qtimer.h>
#include "Map.h"
#include "ManageGame.h"

BuildWhat::BuildWhat(Map *map, QWidget *parent) : QWidget(parent){

	nowmap = map;

	gym = new QPushButton(this);
	lib = new QPushButton(this);
	lab = new QPushButton(this);
	logH = new QPushButton(this);
	stu = new QPushButton(this);
	mar = new QPushButton(this);

	QIcon gymB;
	gymB.addPixmap(QPixmap(QString::fromUtf8("Resources/Gym_Inactivated.png")), QIcon::Normal, QIcon::Off);
	QIcon libB;
	libB.addPixmap(QPixmap(QString::fromUtf8("Resources/Library_Inactivated.png")), QIcon::Normal, QIcon::Off);
	QIcon labB;
	labB.addPixmap(QPixmap(QString::fromUtf8("Resources/Labor_Inactivated.png")), QIcon::Normal, QIcon::Off);
	QIcon logHB;
	logHB.addPixmap(QPixmap(QString::fromUtf8("Resources/LogHouse_Inactivated.png")), QIcon::Normal, QIcon::Off);
	QIcon stuB;
	stuB.addPixmap(QPixmap(QString::fromUtf8("Resources/StudentHall_Inactivated.png")), QIcon::Normal, QIcon::Off);
	QIcon marB;
	marB.addPixmap(QPixmap(QString::fromUtf8("Resources/Market_Inactivated.png")), QIcon::Normal, QIcon::Off);

	//gym->setText("gym");
	gym->setGeometry(QRect(20, 50, 100, 39));
	gym->setIcon(gymB);
	gym->setIconSize(QSize(100, 40));
	gym->show();

	//lib->setText("library");
	lib->setGeometry(QRect(20, 110, 100, 39));
	lib->setIcon(libB);
	lib->setIconSize(QSize(100, 40));
	lib->show();

	//lab->setText("laborbuilding");
	lab->setGeometry(QRect(20, 170, 100, 39));
	lab->setIcon(labB);
	lab->setIconSize(QSize(100, 40));
	lab->show();

	//logH->setText("loghouse");
	logH->setGeometry(QRect(20, 230, 100, 39));
	logH->setIcon(logHB);
	logH->setIconSize(QSize(100, 40));
	logH->show();

	//stu->setText("studenthall");
	stu->setGeometry(QRect(20, 290, 100, 39));
	stu->setIcon(stuB);
	stu->setIconSize(QSize(100, 40));
	stu->show();

	//mar->setText("market");
	mar->setGeometry(QRect(20, 350, 100, 40));
	mar->setIcon(marB);
	mar->setIconSize(QSize(100, 40));
	mar->show();
}

void BuildWhat::setGymIcon(){
	if(nowmap->getOnGoingGame()->getBuilding(3) == NULL){
		gym->setGeometry(QRect(22, 52, 100, 39));
		QTimer::singleShot(150, this, SLOT(resetIcon()));
		QTimer::singleShot(151, nowmap, SLOT(setGymAlert()));
	}
}

void BuildWhat::setLibIcon(){
	if(nowmap->getOnGoingGame()->getBuilding(6) == NULL){
		lib->setGeometry(QRect(22, 112, 100, 39));
		QTimer::singleShot(150, this, SLOT(resetIcon()));
		QTimer::singleShot(151, nowmap, SLOT(setLibAlert()));
	}
}

void BuildWhat::setLabIcon(){
	if(nowmap->getOnGoingGame()->getBuilding(4) == NULL){
		lab->setGeometry(QRect(22, 172, 100, 39));
		QTimer::singleShot(150, this, SLOT(resetIcon()));
		QTimer::singleShot(151, nowmap, SLOT(setLabAlert()));
	}
}

void BuildWhat::setStuIcon(){
	if(nowmap->getOnGoingGame()->getBuilding(5) == NULL){
		stu->setGeometry(QRect(22, 292, 100, 39));
		QTimer::singleShot(150, this, SLOT(resetIcon()));
		QTimer::singleShot(151, nowmap, SLOT(setStuAlert()));
	}
}

void BuildWhat::setLogIcon(){
	if(nowmap->getOnGoingGame()->getBuilding(7) == NULL){
		logH->setGeometry(QRect(22, 232, 100, 39));
		QTimer::singleShot(150, this, SLOT(resetIcon()));
		QTimer::singleShot(151, nowmap, SLOT(setLogAlert()));
	}
}

void BuildWhat::setMarIcon(){
	if(nowmap->getOnGoingGame()->getBuilding(8) == NULL){
		mar->setGeometry(QRect(22, 352, 100, 39));
		QTimer::singleShot(150, this, SLOT(resetIcon()));
		QTimer::singleShot(151, nowmap, SLOT(setMarAlert()));
	}
}
void BuildWhat::resetIcon(){
	gym->setGeometry(QRect(20, 50, 100, 39));
	lib->setGeometry(QRect(20, 110, 100, 39));
	lab->setGeometry(QRect(20, 170, 100, 39));
	stu->setGeometry(QRect(20, 290, 100, 39));
	logH->setGeometry(QRect(20, 230, 100, 39));
	mar->setGeometry(QRect(20, 350, 100, 39));
}