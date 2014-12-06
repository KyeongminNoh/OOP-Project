#include "FieldScene.h"
#include "StartScene.h"

FieldScene::FieldScene(GameWindow* win, int isMan, int isDayPerson, struct data S){
	window = win;

	_bgm = new QMediaPlayer;
	Playlist = new QMediaPlaylist();

	Playlist->addMedia(QUrl::fromLocalFile("Resources/Graduate.mp3"));	
	Playlist->setPlaybackMode(QMediaPlaylist::Loop);

	_bgm->setPlaylist(Playlist);
	Playlist->setCurrentIndex(0);

	_bgm->play();

	Page = new QWidget(window);
	Page->resize(800,600);

	Title = new QLabel();
	Title->setScaledContents(true);
	Title->setGeometry(QRect(0,0,800,600));
    QPixmap image;
    image.load(QString::fromUtf8("Resources/White.png"));
    Title->setPixmap(image);

	window->setCentralWidget(Title);

	maP = new Map(isMan-1,this,S.isSemester,Title);
//	maP->get_nowSemester()->set_CurrentSemester(isSemester);
	maP->setGeometry(QRect(140,0, 660, 450));
	maP->show();

	SideBar = new QLabel(Title);
	SideBar->setScaledContents(true);
	SideBar->setGeometry(QRect(0,0,140,460));
	QPixmap SideBarImage;
	SideBarImage.load(QString::fromUtf8("Resources/SideBar.png"));
	SideBar->setPixmap(SideBarImage);

	MenuBar = new BuildWhat(maP, SideBar);

	MenuBar->setGeometry(QRect(0,0,140, 460));
	MenuBar->show();

	Footer = new QLabel(Title);
	Footer->setScaledContents(true);
	Footer->setGeometry(QRect(0,450,800,150));
	QPixmap footerImage;
	footerImage.load(QString::fromUtf8("Resources/footer_new.png"));
	Footer->setPixmap(footerImage);

	QIcon TAImage;
	TAImage.addPixmap(QPixmap(QString::fromUtf8("Resources/TestAssnButton.png")), QIcon::Normal, QIcon::Off);

	QPushButton *TAButton;
	TAButton = new QPushButton(Footer);
    TAButton->setGeometry(QRect(10, 15, 120, 65));
	TAButton->setIcon(TAImage);
	TAButton->setIconSize(QSize(110, 55));
	TAButton->setFlat(true);
	TAButton->show();

	QIcon FriendImage;
	FriendImage.addPixmap(QPixmap(QString::fromUtf8("Resources/FriendButton.png")), QIcon::Normal, QIcon::Off);

	QPushButton *FriendButton;
	FriendButton = new QPushButton(Footer);
    FriendButton->setGeometry(QRect(10, 75, 120, 65));
	FriendButton->setIcon(FriendImage);
	FriendButton->setIconSize(QSize(110, 55));
	FriendButton->setFlat(true);
	FriendButton->show();

	onGoingGame = new ManageGame(isMan, isDayPerson, maP , MenuBar, S ,Footer);

	onGoingGame->setGeometry(QRect(150,0,800,150));
	onGoingGame->show();
	
	QObject::connect(MenuBar->gym, SIGNAL(clicked()),  MenuBar, SLOT(setGymIcon()));
	

	
	QObject::connect(MenuBar->lib, SIGNAL(clicked()), MenuBar, SLOT(setLibIcon()));
	

	
	QObject::connect(MenuBar->lab, SIGNAL(clicked()), MenuBar, SLOT(setLabIcon()));
	

	
	QObject::connect(MenuBar->stu, SIGNAL(clicked()), MenuBar, SLOT(setStuIcon()));
	

	
	QObject::connect(MenuBar->logH, SIGNAL(clicked()), MenuBar, SLOT(setLogIcon()));
	


	QObject::connect(MenuBar->mar, SIGNAL(clicked()), MenuBar, SLOT(setMarIcon()));

	
	QObject::connect(TAButton, SIGNAL(clicked()), maP, SLOT(setTA()));

	QObject::connect(FriendButton, SIGNAL(clicked()), maP, SLOT(setFList()));
	
	//QObject::connect(MenuBar->mar, SIGNAL(clicked()), maP, SLOT(setMarAlert()));

}

void FieldScene::ReturnStart(){
	_bgm->stop();
	StartScene* startscene = new StartScene(window);
	delete this;
}

void FieldScene::ExitGame(){
	window->close();
}
