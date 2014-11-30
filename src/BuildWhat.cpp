#include "BuildWhat.h"
#include <qtimer.h>
#include "Map.h"
#include "ManageGame.h"
#include "Building.h"

BuildWhat::BuildWhat(Map *map, QWidget *parent) : QWidget(parent){

	nowmap = map;

	gym = new QPushButton(this);
	lib = new QPushButton(this);
	lab = new QPushButton(this);
	logH = new QPushButton(this);
	stu = new QPushButton(this);
	mar = new QPushButton(this);

	QIcon gymB;
	gymB.addPixmap(QPixmap(QString::fromUtf8("Resources/Gym_inactivated.png")), QIcon::Normal, QIcon::Off);
	QIcon libB;
	libB.addPixmap(QPixmap(QString::fromUtf8("Resources/Library_inactivated.png")), QIcon::Normal, QIcon::Off);
	QIcon labB;
	labB.addPixmap(QPixmap(QString::fromUtf8("Resources/Labor_inactivated.png")), QIcon::Normal, QIcon::Off);
	QIcon logHB;
	logHB.addPixmap(QPixmap(QString::fromUtf8("Resources/LogHouse_inactivated.png")), QIcon::Normal, QIcon::Off);
	QIcon stuB;
	stuB.addPixmap(QPixmap(QString::fromUtf8("Resources/StudentHall_inactivated.png")), QIcon::Normal, QIcon::Off);
	QIcon marB;
	marB.addPixmap(QPixmap(QString::fromUtf8("Resources/Market_inactivated.png")), QIcon::Normal, QIcon::Off);

	//gym->setText("gym");
	gym->setGeometry(QRect(15, 45, 110, 50));
	gym->setIcon(gymB);
	gym->setIconSize(QSize(100, 40));
	gym->setFlat(true);
	gym->show();

	//lib->setText("library");
	lib->setGeometry(QRect(15, 105, 110, 50));
	lib->setIcon(libB);
	lib->setIconSize(QSize(100, 40));
	lib->setFlat(true);
	lib->show();

	//lab->setText("laborbuilding");
	lab->setGeometry(QRect(15, 165, 110, 50));
	lab->setIcon(labB);
	lab->setIconSize(QSize(100, 40));
	lab->setFlat(true);
	lab->show();

	//logH->setText("loghouse");
	logH->setGeometry(QRect(15, 225, 110, 50));
	logH->setIcon(logHB);
	logH->setIconSize(QSize(100, 40));
	logH->setFlat(true);
	logH->show();

	//stu->setText("studenthall");
	stu->setGeometry(QRect(15, 285, 110, 50));
	stu->setIcon(stuB);
	stu->setIconSize(QSize(100, 40));
	stu->setFlat(true);
	stu->show();

	//mar->setText("market");
	mar->setGeometry(QRect(15, 345, 110, 50));
	mar->setIcon(marB);
	mar->setIconSize(QSize(100, 40));
	mar->setFlat(true);
	mar->show();
}

void BuildWhat::setGymIcon(){
	if(nowmap->getOnGoingGame()->getBuilding(3) == NULL){
		//gym->setGeometry(QRect(22, 52, 100, 39));
		//QTimer::singleShot(150, this, SLOT(resetIcon()));
		QTimer::singleShot(151, nowmap, SLOT(setGymAlert()));
	}
}

void BuildWhat::setLibIcon(){
	if(nowmap->getOnGoingGame()->getBuilding(6) == NULL){
		//lib->setGeometry(QRect(22, 112, 100, 39));
		//QTimer::singleShot(150, this, SLOT(resetIcon()));
		QTimer::singleShot(151, nowmap, SLOT(setLibAlert()));
	}
}

void BuildWhat::setLabIcon(){
	if(nowmap->getOnGoingGame()->getBuilding(4) == NULL){
		//lab->setGeometry(QRect(22, 172, 100, 39));
		//QTimer::singleShot(150, this, SLOT(resetIcon()));
		QTimer::singleShot(151, nowmap, SLOT(setLabAlert()));
	}
}

void BuildWhat::setStuIcon(){
	if(nowmap->getOnGoingGame()->getBuilding(5) == NULL){
		//stu->setGeometry(QRect(22, 292, 100, 39));
		//QTimer::singleShot(150, this, SLOT(resetIcon()));
		QTimer::singleShot(151, nowmap, SLOT(setStuAlert()));
	}
}

void BuildWhat::setLogIcon(){
	if(nowmap->getOnGoingGame()->getBuilding(7) == NULL){
		//logH->setGeometry(QRect(22, 232, 100, 39));
		//QTimer::singleShot(150, this, SLOT(resetIcon()));
		QTimer::singleShot(151, nowmap, SLOT(setLogAlert()));
	}
}

void BuildWhat::setMarIcon(){
	if(nowmap->getOnGoingGame()->getBuilding(8) == NULL){
		//mar->setGeometry(QRect(22, 352, 100, 39));
		//QTimer::singleShot(150, this, SLOT(resetIcon()));
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

void BuildWhat::setGymInactive(){
	QIcon gymB;
	if(nowmap->getOnGoingGame()->getBuilding(3)->get_level() == 1){
		gymB.addPixmap(QPixmap(QString::fromUtf8("Resources/Gym_lv1.png")), QIcon::Normal, QIcon::Off);
	}
	else if(nowmap->getOnGoingGame()->getBuilding(3)->get_level() == 2){
		gymB.addPixmap(QPixmap(QString::fromUtf8("Resources/Gym_lv2.png")), QIcon::Normal, QIcon::Off);
	}
	else{
		gymB.addPixmap(QPixmap(QString::fromUtf8("Resources/Gym_lv3.png")), QIcon::Normal, QIcon::Off);
	}

	gym->setGeometry(QRect(20, 50, 100, 40));
	gym->setIcon(gymB);
	gym->setIconSize(QSize(100, 40));
	gym->show();
}

void BuildWhat::setLibInactive(){
	QIcon LibB;
	LibB.addPixmap(QPixmap(QString::fromUtf8("Resources/Library_lv1.png")), QIcon::Normal, QIcon::Off);
	if(nowmap->getOnGoingGame()->getBuilding(6)->get_level() == 1){
		LibB.addPixmap(QPixmap(QString::fromUtf8("Resources/Library_lv1.png")), QIcon::Normal, QIcon::Off);
	}
	else if(nowmap->getOnGoingGame()->getBuilding(6)->get_level() == 2){
		LibB.addPixmap(QPixmap(QString::fromUtf8("Resources/Library_lv2.png")), QIcon::Normal, QIcon::Off);
	}
	else{
		LibB.addPixmap(QPixmap(QString::fromUtf8("Resources/Library_lv3.png")), QIcon::Normal, QIcon::Off);
	}

	lib->setGeometry(QRect(20, 110, 100, 40));
	lib->setIcon(LibB);
	lib->setIconSize(QSize(100, 40));
	lib->show();
}

void BuildWhat::setLogInactive(){
	QIcon LogB;
	if(nowmap->getOnGoingGame()->getBuilding(6)->get_level() == 1){
		LogB.addPixmap(QPixmap(QString::fromUtf8("Resources/LogHouse_lv1.png")), QIcon::Normal, QIcon::Off);
	}
	else if(nowmap->getOnGoingGame()->getBuilding(6)->get_level() == 2){
		LogB.addPixmap(QPixmap(QString::fromUtf8("Resources/LogHouse_lv2.png")), QIcon::Normal, QIcon::Off);
	}
	else{
		LogB.addPixmap(QPixmap(QString::fromUtf8("Resources/LogHouse_lv3.png")), QIcon::Normal, QIcon::Off);
	}

	logH->setGeometry(QRect(20, 230, 100, 40));
	logH->setIcon(LogB);
	logH->setIconSize(QSize(100, 40));
	logH->show();

}

void BuildWhat::setStuInactive(){
	QIcon StuB;
	if(nowmap->getOnGoingGame()->getBuilding(5)->get_level() == 1){
		StuB.addPixmap(QPixmap(QString::fromUtf8("Resources/StudentHall_lv1.png")), QIcon::Normal, QIcon::Off);
	}
	else if(nowmap->getOnGoingGame()->getBuilding(5)->get_level() == 2){
		StuB.addPixmap(QPixmap(QString::fromUtf8("Resources/StudentHall_lv2.png")), QIcon::Normal, QIcon::Off);
	}
	else{
		StuB.addPixmap(QPixmap(QString::fromUtf8("Resources/StudentHall_lv3.png")), QIcon::Normal, QIcon::Off);
	}

	stu->setGeometry(QRect(20, 290, 100, 40));
	stu->setIcon(StuB);
	stu->setIconSize(QSize(100, 40));
	stu->show();
}

void BuildWhat::setLabInactive(){
	QIcon LabB;
	if(nowmap->getOnGoingGame()->getBuilding(4)->get_level() == 1){
		LabB.addPixmap(QPixmap(QString::fromUtf8("Resources/Labor_lv1.png")), QIcon::Normal, QIcon::Off);
	}
	else if(nowmap->getOnGoingGame()->getBuilding(4)->get_level() == 2){
		LabB.addPixmap(QPixmap(QString::fromUtf8("Resources/Labor_lv2.png")), QIcon::Normal, QIcon::Off);
	}
	else{
		LabB.addPixmap(QPixmap(QString::fromUtf8("Resources/Labor_lv3.png")), QIcon::Normal, QIcon::Off);
	}

	lab->setGeometry(QRect(20, 170, 100, 40));
	lab->setIcon(LabB);
	lab->setIconSize(QSize(100, 40));
	lab->show();
}

void BuildWhat::setMarInactive(){
	QIcon MarB;
	if(nowmap->getOnGoingGame()->getBuilding(8)->get_level() == 1){
		MarB.addPixmap(QPixmap(QString::fromUtf8("Resources/Market_lv1.png")), QIcon::Normal, QIcon::Off);
	}
	else if(nowmap->getOnGoingGame()->getBuilding(8)->get_level() == 2){
		MarB.addPixmap(QPixmap(QString::fromUtf8("Resources/Market_lv2.png")), QIcon::Normal, QIcon::Off);
	}
	else{
		MarB.addPixmap(QPixmap(QString::fromUtf8("Resources/Market_lv3.png")), QIcon::Normal, QIcon::Off);
	}

	mar->setGeometry(QRect(20, 350, 100, 40));
	mar->setIcon(MarB);
	mar->setIconSize(QSize(100, 40));
	mar->show();
}