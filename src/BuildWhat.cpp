#include "BuildWhat.h"

BuildWhat::BuildWhat(QWidget *parent) : QWidget(parent){

	gym = new QPushButton(this);
	lib = new QPushButton(this);
	lab = new QPushButton(this);
	logH = new QPushButton(this);
	stu = new QPushButton(this);
	mar = new QPushButton(this);

	QIcon gymB;
	gymB.addPixmap(QPixmap(QString::fromUtf8("Resources/GymButton.jpg")), QIcon::Normal, QIcon::Off);
	QIcon libB;
	libB.addPixmap(QPixmap(QString::fromUtf8("Resources/LibraryButton.jpg")), QIcon::Normal, QIcon::Off);
	QIcon labB;
	labB.addPixmap(QPixmap(QString::fromUtf8("Resources/LaborButton.jpg")), QIcon::Normal, QIcon::Off);
	QIcon logHB;
	logHB.addPixmap(QPixmap(QString::fromUtf8("Resources/LogHouseButton.jpg")), QIcon::Normal, QIcon::Off);
	QIcon stuB;
	stuB.addPixmap(QPixmap(QString::fromUtf8("Resources/StudentHallButton.jpg")), QIcon::Normal, QIcon::Off);
	QIcon marB;
	marB.addPixmap(QPixmap(QString::fromUtf8("Resources/MarketButton.jpg")), QIcon::Normal, QIcon::Off);

	//gym->setText("gym");
	gym->setGeometry(QRect(20, 50, 100, 45));
	gym->setIcon(gymB);
	gym->setIconSize(QSize(100, 50));
	gym->show();

	//lib->setText("library");
	lib->setGeometry(QRect(20, 110, 100, 45));
	lib->setIcon(libB);
	lib->setIconSize(QSize(100, 50));
	lib->show();

	//lab->setText("laborbuilding");
	lab->setGeometry(QRect(20, 170, 100, 45));
	lab->setIcon(labB);
	lab->setIconSize(QSize(100, 50));
	lab->show();

	//logH->setText("loghouse");
	logH->setGeometry(QRect(20, 230, 100, 45));
	logH->setIcon(logHB);
	logH->setIconSize(QSize(100, 50));
	logH->show();

	//stu->setText("studenthall");
	stu->setGeometry(QRect(20, 290, 100, 45));
	stu->setIcon(stuB);
	stu->setIconSize(QSize(100, 50));
	stu->show();

	//mar->setText("market");
	mar->setGeometry(QRect(20, 350, 100, 44));
	mar->setIcon(marB);
	mar->setIconSize(QSize(100, 50));
	mar->show();
}