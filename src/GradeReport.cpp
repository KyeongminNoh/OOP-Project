#include "GradeReport.h"
#include "FieldScene.h"


GradeReport::GradeReport(ManageGame *Game, Semester* S, FieldScene *F, QWidget *parent) : QLabel(parent){
	field = F;
	semester = S;
	resize(660, 450);

	Grade = new QPainter*[8];
	for(int i = 0; i<8; i++){
		Grade[i] = new QPainter(this);
	}
	Total = new QPainter(this);

	font = new QFont( "Resources/NanumBarunGothic.ttp");
	font->setKerning( true );
	font->setBold( true );
	font->setPixelSize( 25 );

	font2 = new QFont( "Resources/NanumBarunGothic.ttp");
	font2->setKerning( true );
	font2->setBold( true );
	font2->setPixelSize( 30 );


	GoMain = new QPushButton(this);
	GoMain->setGeometry(QRect(170, 380, 140, 63));
	QIcon GoMainIcon;
    GoMainIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/GoToMain.png")), QIcon::Normal, QIcon::Off);
	GoMain->setIcon(GoMainIcon);
	GoMain->setIconSize(QSize(130, 59));
	GoMain->setFlat(true);
	GoMain->show();

	ExitGame = new QPushButton(this);
	ExitGame->setGeometry(QRect(350, 380, 140, 63));
	QIcon ExitGameIcon;
    ExitGameIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/ExitGame.png")), QIcon::Normal, QIcon::Off);
	ExitGame->setIcon(ExitGameIcon);
	ExitGame->setIconSize(QSize(130, 59));
	ExitGame->setFlat(true);
	ExitGame->show();

	show();

	repaint();
	QObject::connect(GoMain, SIGNAL(clicked()), SLOT(ClickYes()));
	QObject::connect(ExitGame, SIGNAL(clicked()), SLOT(ClickNo()));
	
	
	
	
	
	
	
}


void GradeReport::paintEvent(QPaintEvent*){
	QString g;
	g.append(semester->GetGrade(0));
	Grade[0]->begin(this);
	Grade[0]->setFont(*font);
	Grade[0]->drawText(155, 160, g);
	Grade[0]->end();

	g.clear();
	g.append(semester->GetGrade(1));
	Grade[1]->begin(this);
	Grade[1]->setFont(*font);
	Grade[1]->drawText(260, 160, g);
	Grade[1]->end();

	g.clear();
	g.append(semester->GetGrade(2));
	Grade[2]->begin(this);
	Grade[2]->setFont(*font);
	Grade[2]->drawText(365, 160, g);
	Grade[2]->end();

	g.clear();
	g.append(semester->GetGrade(3));
	Grade[3]->begin(this);
	Grade[3]->setFont(*font);
	Grade[3]->drawText(470, 160, g);
	Grade[3]->end();

	g.clear();
	g.append(semester->GetGrade(4));
	Grade[4]->begin(this);
	Grade[4]->setFont(*font);
	Grade[4]->drawText(155, 265, g);
	Grade[4]->end();

	g.clear();
	g.append(semester->GetGrade(5));
	Grade[5]->begin(this);
	Grade[5]->setFont(*font);
	Grade[5]->drawText(260, 265, g);
	Grade[5]->end();

	g.clear();
	g.append(semester->GetGrade(6));
	Grade[6]->begin(this);
	Grade[6]->setFont(*font);
	Grade[6]->drawText(365, 265, g);
	Grade[6]->end();

	g.clear();
	g.append(semester->GetGrade(7));
	Grade[7]->begin(this);
	Grade[7]->setFont(*font);
	Grade[7]->drawText(470, 265, g);
	Grade[7]->end();
	
	qreal *arr = semester->get_grade();
	int t;
	qreal sum;
	sum =0;
	t =0;
	for(int i = 0; i<8; i++ ){
		if(arr[i]!= -1){
			sum += arr[i];
			t++;
		}
	}
	sum = sum/t;
	g.clear();

	Total->begin(this);
	Total->setFont(*font2);
	Total->drawText(330, 350, g.setNum(sum));
	Total->end();

}

void GradeReport::ClickNo(){
	field->ExitGame();
	//delete this;
}

void GradeReport::ClickYes(){
	field->ReturnStart();
	//delete this;
}
