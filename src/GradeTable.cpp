#include "GradeTable.h"
#include "LoadScene.h"


GradeTable::GradeTable(LoadScene *S,int *arr, QWidget *parent) : QLabel(parent){

	LS = S;
	resize(600, 400);
	grade = arr;

	grading = new QPainter*[9];
	int i;
	for(i=1 ; i<=8 ; i++)
		grading[i] = new QPainter(this);

	font = new QFont( "Resources/NanumBarunGothic.ttp");
	font->setKerning( true );
	font->setBold( true );
	font->setPixelSize( 25 );

	QIcon BackIcon;
	BackIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/GoBack_inGame.png")), QIcon::Normal, QIcon::Off);

	backButton = new QPushButton(this);
	backButton->setGeometry(QRect(230, 330, 140, 60));
	backButton->setIcon(BackIcon);
	backButton->setIconSize(QSize(125, 50));
	backButton->setFlat(true);
	backButton->show();

	QObject::connect(backButton, SIGNAL(clicked()),this,SLOT(ClickYes()));

	show();

	repaint();

}

void GradeTable::paintEvent(QPaintEvent* ){
	
	for(int i=1 ; i<=8 ; i++)
	{
		grading[i]->begin(this);
		grading[i]->setFont(*font);
		if(grade[i]==0)
			grading[i]->drawText(142+95*((i-1)%4), 150+95*((i-1)/4), "A+");
		else if(grade[i]==-1)
			grading[i]->drawText(142+95*((i-1)%4), 150+95*((i-1)/4), "A");
		else if(grade[i]==-2)
			grading[i]->drawText(142+95*((i-1)%4), 150+95*((i-1)/4), "A-");
		else if(grade[i]==-3)
			grading[i]->drawText(142+95*((i-1)%4), 150+95*((i-1)/4), "B+");
		else if(grade[i]==-4)
			grading[i]->drawText(142+95*((i-1)%4), 150+95*((i-1)/4), "B");
		else if(grade[i]==-5)
			grading[i]->drawText(142+95*((i-1)%4), 150+95*((i-1)/4), "B-");
		else if(grade[i]==-6)
			grading[i]->drawText(142+95*((i-1)%4), 150+95*((i-1)/4), "C+");
		else if(grade[i]==-7)
			grading[i]->drawText(142+95*((i-1)%4), 150+95*((i-1)/4), "C");
		else if(grade[i]==-8)
			grading[i]->drawText(142+95*((i-1)%4), 150+95*((i-1)/4), "C-");
		else if(grade[i]==-9)
			grading[i]->drawText(142+95*((i-1)%4), 150+95*((i-1)/4), "D+");
		else if(grade[i]==-10)
			grading[i]->drawText(142+95*((i-1)%4), 150+95*((i-1)/4), "D");
		else if(grade[i]==-11)
			grading[i]->drawText(142+95*((i-1)%4), 150+95*((i-1)/4), "D-");
		else if(grade[i]<=-12)
			grading[i]->drawText(142+95*((i-1)%4), 150+95*((i-1)/4), "F");
		grading[i]->end();
	}
}

void GradeTable::ClickYes(){
	LS->BackClicked2();
}