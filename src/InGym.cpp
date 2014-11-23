#include "InGym.h"

InGym::InGym(GameWindow* win, ManageGame* onGoingGame,FieldScene* preScene)
{
	window = win;

	Page = new QWidget(window);
	Page->resize(800,600);

	Title = new QLabel();
	Title->setScaledContents(true);
	Title->setGeometry(QRect(0,0,800,600));
    QPixmap image;
    image.load(QString::fromUtf8("Resources/White.png"));
    Title->setPixmap(image);

	window->setCentralWidget(Title);

	buildname = new QLabel(Title);
	buildname->setScaledContents(true);
	buildname->setGeometry(QRect(0,0,500,140));
	QPixmap buildnameImage;
	if(onGoingGame->getBuilding(3)->get_level()==1)
	{
		buildnameImage.load(QString::fromUtf8("Resources/Gym_Title_level1.png")); // 체력회복량까지
	}
	else if(onGoingGame->getBuilding(3)->get_level()==2)
	{
		buildnameImage.load(QString::fromUtf8("Resources/Gym_Title_level2.png"));
	}
	else if(onGoingGame->getBuilding(3)->get_level()==3)
	{
		buildnameImage.load(QString::fromUtf8("Resources/Gym_Title_level3.png"));
	}
	buildname->setPixmap(buildnameImage);

	QIcon ExerImage;
	ExerImage.addPixmap(QPixmap(QString::fromUtf8("Resources/ExerciseButton.png")), QIcon::Normal, QIcon::Off);

	QPushButton *ExerButton;
	ExerButton = new QPushButton(Title);
    ExerButton->setGeometry(QRect(120, 300, 120, 60));
	ExerButton->setIcon(ExerImage);
	ExerButton->setIconSize(QSize(120, 60));
	ExerButton->show();

	exerEff = new QLabel(Title);
	exerEff->setScaledContents(true);
	exerEff->setGeometry(QRect(120,250,200,60));
	QPixmap exerEffImage;
	if(onGoingGame->getBuilding(3)->get_level()==1)
	{
		exerEffImage.load(QString::fromUtf8("Resources/exerEff_level1.png")); // 운동효과
	}
	else if(onGoingGame->getBuilding(3)->get_level()==2)
	{
		exerEffImage.load(QString::fromUtf8("Resources/exerEff_level2.png"));
	}
	else if(onGoingGame->getBuilding(3)->get_level()==3)
	{
		exerEffImage.load(QString::fromUtf8("Resources/exerEff_level3.png"));
	}
	exerEff->setPixmap(exerEffImage);

	QObject::connect(ExerButton, SIGNAL(clicked()), this, SLOT(setExerAlert()));

	QIcon UpgradeImage;
	UpgradeImage.addPixmap(QPixmap(QString::fromUtf8("Resources/UpgradeButton.png")), QIcon::Normal, QIcon::Off);

	QPushButton *UpgradeButton;
	UpgradeButton = new QPushButton(Title);
    UpgradeButton->setGeometry(QRect(500, 440, 120, 60));
	UpgradeButton->setIcon(UpgradeImage);
	UpgradeButton->setIconSize(QSize(120, 60));
	UpgradeButton->show();

	QObject::connect(UpgradeButton, SIGNAL(clicked()), this, SLOT(setGym_Upgrade_Alert()));

	QIcon BackImage;
	BackImage.addPixmap(QPixmap(QString::fromUtf8("Resources/BackButton.png")), QIcon::Normal, QIcon::Off);

	QPushButton *BackButton;
	BackButton = new QPushButton(Title);
    BackButton->setGeometry(QRect(640, 440, 120, 60));
	BackButton->setIcon(BackImage);
	BackButton->setIconSize(QSize(120, 60));
	BackButton->show();

	Title->show();
	///////
}