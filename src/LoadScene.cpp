#include "LoadScene.h"
#include "FieldScene.h"
//#include "SelectScene.h"
#include <QMouseEvent>
#include <QTimer>
#include "StartScene.h"

// save에 넣어야 될것 : 성별, 야행성, 건물 레벨, 친구 수(사교성), 최대 체력 , 학기 마다 성적
// 표시할 정보 : 저장된 시간, 성별, 학기 수
// 1 : dorm, 2 : engi~building, 3: gym, 4: Lab, 5: studenthall, 6 : libaray 7 : log, 8 : Market
// 1 : 술고래 2 : 선배 3 : 헬스 4 : 과탑 5 : 이성
// 
/* savedata form
   2 2					---> 남자 주행성
   0 0 0 0 0			---> 친구 수
   100				---> 최대 체력
   -1 -1 -1 -1 1 1 1 1	---> A0 A0 A0 A0 진행x 진행x 진행x 진행x
*/
LoadScene::LoadScene(GameWindow* win)
{
	window = win;
	setMouseTracking(true);

	Page = new QWidget(window);
	Page->resize(800,600);

	Title = new QLabel();
	Title->setScaledContents(true);
	Title->setGeometry(QRect(0,0,800,600));
    QPixmap image;
    image.load(QString::fromUtf8("Resources/White.png"));
    Title->setPixmap(image);

	window->setCentralWidget(Title);


	QIcon showIcon;
	showIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/GradeShow.png")), QIcon::Normal, QIcon::Off);
	QIcon NextIcon;
	NextIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/GoStart.png")), QIcon::Normal, QIcon::Off);
	QIcon BackIcon;
	BackIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/GoBack.png")), QIcon::Normal, QIcon::Off);

	QIcon SaveIcon1;
	SaveIcon1.addPixmap(QPixmap(QString::fromUtf8("Resources/savefile1.png")), QIcon::Normal, QIcon::Off);
	QIcon SaveIcon2;
	SaveIcon2.addPixmap(QPixmap(QString::fromUtf8("Resources/savefile2.png")), QIcon::Normal, QIcon::Off);
	QIcon SaveIcon3;
	SaveIcon3.addPixmap(QPixmap(QString::fromUtf8("Resources/savefile3.png")), QIcon::Normal, QIcon::Off);
	QIcon SaveIcon4;
	SaveIcon4.addPixmap(QPixmap(QString::fromUtf8("Resources/savefile4.png")), QIcon::Normal, QIcon::Off);

	Head = new QLabel(Title);
	Head->setScaledContents(true);
	Head->setGeometry(QRect(270,45,250,80));
    QPixmap Himage;
    Himage.load(QString::fromUtf8("Resources/LoadData.png"));
    Head->setPixmap(Himage);
	Head->show();

	FILE *fp[5];
	fp[1] = fopen("savedata1.txt","r");
	fp[2] = fopen("savedata2.txt","r");
	fp[3] = fopen("savedata3.txt","r");
	fp[4] = fopen("savedata4.txt","r");

	int i,j;
	QLabel *Load;
	QPushButton *loadButton[5];

	Person = new QLabel(Title);
	Person->setScaledContents(true);
	Person->setGeometry(QRect(425,250,250,250));
	Night = new QLabel(Title);
	Night->setScaledContents(true);
	Night->setGeometry(QRect(425,200,50,50));
	Session1 = new QLabel(Title);
	Session1->setScaledContents(true);
	Session1->setGeometry(QRect(550, 200, 100, 45));
	for(i=1 ; i<=4 ; i++)
	{
		if(fp[i]!=NULL)
		{
			int check=0;
			fscanf(fp[i],"%d %d",&s[i].isMan,&s[i].isDayPerson);
//			for(j=1 ; j<=8 ; j++)
//				fscanf(fp[i],"%d ",&BuildingLevel[i][j]);
			for(j=1 ; j<=5 ; j++)
				fscanf(fp[i],"%d ",&s[i].Friend_num[j]);
			fscanf(fp[i],"%d",&s[i].Max_Heal);
			for(j=1 ; j<=8 ; j++)
			{
				fscanf(fp[i],"%d ",&s[i].grade[j]);
				if(s[i].grade[j]==1 && check==0)
				{
					s[i].isSemester=j;
					check=1;
				}
			}
			loadButton[i] = new QPushButton(Title);
			loadButton[i]->setGeometry(QRect(165, 80+90*i, 210, 70));
			if(i==1)
				loadButton[i]->setIcon(SaveIcon1);
			else if(i==2)
				loadButton[i]->setIcon(SaveIcon2);
			else if(i==3)
				loadButton[i]->setIcon(SaveIcon3);
			else if(i==4)
				loadButton[i]->setIcon(SaveIcon4);
			loadButton[i]->setIconSize(QSize(210, 70));
			loadButton[i]->setFlat(true);
			loadButton[i]->show();
	
			if(i==1)
			{
				QObject::connect(loadButton[i], SIGNAL(clicked()),this,SLOT(DataView1()));
			}
			else if(i==2)
			{
				QObject::connect(loadButton[i], SIGNAL(clicked()),this,SLOT(DataView2()));
			}
			else if(i==3)
			{
				QObject::connect(loadButton[i], SIGNAL(clicked()),this,SLOT(DataView3()));
			}
			else if(i==4)
			{
				QObject::connect(loadButton[i], SIGNAL(clicked()),this,SLOT(DataView4()));
			}
		}
		else
		{
			Load = new QLabel(Title);
			Load->setScaledContents(true);
			Load->setGeometry(QRect(200,80+90*i,140,70));
			QPixmap Kimage;
			Kimage.load(QString::fromUtf8("Resources/emptyfile.png"));
			Load->setPixmap(Kimage);
			Load->show();

		}
	}
	QPushButton *backButton;
	backButton = new QPushButton(Title);
	backButton->setGeometry(QRect(50, 515, 210, 70));
	backButton->setIcon(BackIcon);
	backButton->setIconSize(QSize(200, 64));
	backButton->setFlat(true);
	backButton->show();

	QPushButton *showButton;
	showButton = new QPushButton(Title);
	showButton->setGeometry(QRect(345, 515, 210, 70));
	showButton->setIcon(showIcon);
	showButton->setIconSize(QSize(200, 64));
	showButton->setFlat(true);
	showButton->show();

	QPushButton *nextButton;
	nextButton = new QPushButton(Title);
	nextButton->setGeometry(QRect(495, 515, 210, 70));
	nextButton->setIcon(NextIcon);
	nextButton->setIconSize(QSize(200, 64));
	nextButton->setFlat(true);
	nextButton->show();

	QObject::connect(nextButton, SIGNAL(clicked()),this,SLOT(NextClicked()));
	QObject::connect(backButton, SIGNAL(clicked()),this,SLOT(BackClicked()));
	

	Title->show();
}
void LoadScene::BackClicked()
{
	StartScene* startscene = new StartScene(window);
}
void LoadScene::NextClicked()
{
	if(FileCheck>=1 && FileCheck<= 4)
		FieldScene* fieldscene = new FieldScene(window, s[FileCheck].isMan, s[FileCheck].isDayPerson, s[FileCheck]);
	else
		return;
}
void LoadScene::DataView1()
{
	if(s[1].isMan==2)
	{
		QPixmap Iperson;
		Iperson.load(QString::fromUtf8("Resources/Man.png"));
		Person->setPixmap(Iperson);

		Person->show();
	}
	else
	{
		QPixmap Iperson;
		Iperson.load(QString::fromUtf8("Resources/Girl.png"));
		Person->setPixmap(Iperson);

		Person->show();
	}
	if(s[1].isDayPerson==2)
	{
		QPixmap weather;
		weather.load(QString::fromUtf8("Resources/Day.png"));
		Night->setPixmap(weather);

		Night->show();
	}
	else
	{
		QPixmap weather;
		weather.load(QString::fromUtf8("Resources/Night.png"));
		Night->setPixmap(weather);

		Night->show();
	}
	QString SN;
	SN.setNum(s[1].isSemester);
	QByteArray Session;
	Session.append("Resources/Session");
	Session.append(SN);
	Session.append(".png");

	QPixmap SImage;
	SImage.load(QString::fromUtf8(Session));
	Session1->setPixmap(SImage);
	Session1->show();
	FileCheck=1;
}
void LoadScene::DataView2()
{
	if(s[2].isMan==2)
	{
		QPixmap Iperson;
		Iperson.load(QString::fromUtf8("Resources/Man.png"));
		Person->setPixmap(Iperson);

		Person->show();
	}
	else
	{
		QPixmap Iperson;
		Iperson.load(QString::fromUtf8("Resources/Girl.png"));
		Person->setPixmap(Iperson);

		Person->show();
	}
	if(s[2].isDayPerson==2)
	{
		QPixmap weather;
		weather.load(QString::fromUtf8("Resources/Day.png"));
		Night->setPixmap(weather);

		Night->show();
	}
	else
	{
		QPixmap weather;
		weather.load(QString::fromUtf8("Resources/Night.png"));
		Night->setPixmap(weather);

		Night->show();
	}
	QString SN;
	SN.setNum(s[2].isSemester);
	QByteArray Session;
	Session.append("Resources/Session");
	Session.append(SN);
	Session.append(".png");

	QPixmap SImage;
	SImage.load(QString::fromUtf8(Session));
	Session1->setPixmap(SImage);
	Session1->show();
	FileCheck=2;
}
void LoadScene::DataView3(){
	if(s[3].isMan==2)
	{
		QPixmap Iperson;
		Iperson.load(QString::fromUtf8("Resources/Man.png"));
		Person->setPixmap(Iperson);

		Person->show();
	}
	else
	{
		QPixmap Iperson;
		Iperson.load(QString::fromUtf8("Resources/Girl.png"));
		Person->setPixmap(Iperson);

		Person->show();
	}
	if(s[3].isDayPerson==2)
	{
		QPixmap weather;
		weather.load(QString::fromUtf8("Resources/Day.png"));
		Night->setPixmap(weather);

		Night->show();
	}
	else
	{
		QPixmap weather;
		weather.load(QString::fromUtf8("Resources/Night.png"));
		Night->setPixmap(weather);

		Night->show();
	}
	QString SN;
	SN.setNum(s[3].isSemester);
	QByteArray Session;
	Session.append("Resources/Session");
	Session.append(SN);
	Session.append(".png");

	QPixmap SImage;
	SImage.load(QString::fromUtf8(Session));
	Session1->setPixmap(SImage);
	Session1->show();
	FileCheck=3;
}
void LoadScene::DataView4(){
	if(s[4].isMan==2)
	{
		QPixmap Iperson;
		Iperson.load(QString::fromUtf8("Resources/Man.png"));
		Person->setPixmap(Iperson);

		Person->show();
	}
	else
	{
		QPixmap Iperson;
		Iperson.load(QString::fromUtf8("Resources/Girl.png"));
		Person->setPixmap(Iperson);

		Person->show();
	}
	if(s[4].isDayPerson==2)
	{
		QPixmap weather;
		weather.load(QString::fromUtf8("Resources/Day.png"));
		Night->setPixmap(weather);

		Night->show();
	}
	else
	{
		QPixmap weather;
		weather.load(QString::fromUtf8("Resources/Night.png"));
		Night->setPixmap(weather);

		Night->show();
	}
	QString SN;
	SN.setNum(s[4].isSemester);
	QByteArray Session;
	Session.append("Resources/Session");
	Session.append(SN);
	Session.append(".png");

	QPixmap SImage;
	SImage.load(QString::fromUtf8(Session));
	Session1->setPixmap(SImage);
	Session1->show();
	FileCheck=4;
}

/*void LoadScene::MousePressEvent(QMouseEvent *event){
	Cursor = event->pos();
}*/
