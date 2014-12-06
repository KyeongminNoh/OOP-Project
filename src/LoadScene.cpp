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
   0 0 0 0 0 0 0 0		---> 다 레벨 0 건물
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


	QIcon NextIcon;
	NextIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/GoStart.png")), QIcon::Normal, QIcon::Off);
	QIcon OKIcon;
	OKIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/OK.png")), QIcon::Normal, QIcon::Off);

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
			fscanf(fp[i],"%d %d",&isMan[i],&isDayPerson[i]);
//			for(j=1 ; j<=8 ; j++)
//				fscanf(fp[i],"%d ",&BuildingLevel[i][j]);
			for(j=1 ; j<=5 ; j++)
				fscanf(fp[i],"%d ",&Friend_num[i][j]);
			fscanf(fp[i],"%d",&Max_Heal[i]);
			for(j=1 ; j<=8 ; j++)
			{
				fscanf(fp[i],"%d ",&grade[i][j]);
				if(grade[i][j]==1 && check==0)
				{
					isSemester[i]=j;
					check=1;
				}
			}
			loadButton[i] = new QPushButton(Title);
			loadButton[i]->setGeometry(QRect(195, 80+90*i, 210, 70));
			loadButton[i]->setIcon(OKIcon);
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
			Load->setGeometry(QRect(195,80+90*i,210,70));
			QPixmap Kimage;
			Kimage.load(QString::fromUtf8("Resources/No.png"));
			Load->setPixmap(Kimage);
			Load->show();

		}
	}

	QPushButton *nextButton;
	nextButton = new QPushButton(Title);
	nextButton->setGeometry(QRect(295, 515, 210, 70));
	nextButton->setIcon(NextIcon);
	nextButton->setIconSize(QSize(200, 64));
	nextButton->setFlat(true);
	nextButton->show();

	QObject::connect(nextButton, SIGNAL(clicked()),this,SLOT(NextClicked()));

	

	Title->show();
}
void LoadScene::NextClicked()
{
	FieldScene* fieldscene = new FieldScene(window, isMan[FileCheck], isDayPerson[FileCheck], isSemester[FileCheck]);
}
void LoadScene::DataView1()
{
	if(isMan[1]==2)
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
	if(isDayPerson[1]==2)
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
	SN.setNum(isSemester[1]);
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
	if(isMan[2]==2)
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
	if(isDayPerson[2]==2)
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
	SN.setNum(isSemester[2]);
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
	if(isMan[3]==2)
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
	if(isDayPerson[3]==2)
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
	SN.setNum(isSemester[3]);
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
	if(isMan[4]==2)
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
	if(isDayPerson[4]==2)
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
	SN.setNum(isSemester[4]);
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
