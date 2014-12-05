#include "LoadScene.h"
//#include "FieldScene.h"
#include "SelectScene.h"
#include <QMouseEvent>
#include <QTimer>
#include "StartScene.h"

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

	Head = new QLabel(Title);
	Head->setScaledContents(true);
	Head->setGeometry(QRect(270,45,250,80));
    QPixmap Himage;
    Himage.load(QString::fromUtf8("Resources/LoadData.png"));
    Head->setPixmap(Himage);
	Head->show();

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
	SelectScene* selectscene = new SelectScene(window, 0, 0);
}
/*void LoadScene::MousePressEvent(QMouseEvent *event){
	Cursor = event->pos();
}*/
