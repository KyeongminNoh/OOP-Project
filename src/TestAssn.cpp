#include "TestAssn.h"
#include "ManageGame.h"
#include "Assignment.h"
#include "Test.h"
#include "Map.h"

TestAssn::TestAssn(ManageGame *Game, QWidget *parent) : QLabel(parent){


	onGoingGame = Game;
	resize(660, 450);


	Assn1 = new QPainter(this);
	Assn2 = new QPainter(this);
	Assn3 = new QPainter(this);
	Assn4 = new QPainter(this);
	Assn5 = new QPainter(this);
	Assn6 = new QPainter(this);
	Assn7 = new QPainter(this);
	Assn8 = new QPainter(this);

	Midterm = new QPainter(this);
	Final = new QPainter(this);

	font = new QFont( "Resources/NanumBarunGothic.ttp");
	font->setKerning( true );
	font->setBold( true );
	font->setPixelSize( 20 );

	testfont = new QFont( "Resources/NanumBarunGothic.ttp");
	testfont->setKerning( true );
	testfont->setBold( true );
	testfont->setPixelSize( 30 );

	SolveIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/solve.png")), QIcon::Normal, QIcon::Off);

	Solve1= new QPushButton(this);
	Solve1->hide();
	Solve2= new QPushButton(this);
	Solve2->hide();
	Solve3= new QPushButton(this);
	Solve3->hide();
	Solve4= new QPushButton(this);
	Solve4->hide();
	Solve5= new QPushButton(this);
	Solve5->hide();
	Solve6= new QPushButton(this);		
	Solve6->hide();
	Solve7= new QPushButton(this);	
	Solve7->hide();
	Solve8= new QPushButton(this);
	Solve8->hide();
	

	Back = new QPushButton(this);
	Back->setGeometry(QRect(510, 380, 140, 63));
	QIcon BackIcon;
    BackIcon.addPixmap(QPixmap(QString::fromUtf8("Resources/GoBack_InGame.png")), QIcon::Normal, QIcon::Off);
	Back->setIcon(BackIcon);
	Back->setIconSize(QSize(130, 59));
	Back->setFlat(true);
	Back->show();


//	Screen->show();
	show();

	repaint();
	QObject::connect(Back, SIGNAL(clicked()), onGoingGame,SLOT(CloseTA()));
	
	
	
	
	
	
	
	
}


void TestAssn::paintEvent(QPaintEvent*){
	
	QString Num;
	QString sol;
	
	if(onGoingGame->getAssn(0) == 2){
		Assn1->begin(this);
		Assn1->setFont(*font);
		sol.clear();
		if(onGoingGame->getAssignment(0)->get_solved()){
			sol.append("O");
		}else{
			sol.append("X");
		}
		Assn1->drawText(50, 90, "     1                  "+Num.setNum(onGoingGame->getAssignment(0)->get_KnowReq())+"                  "+sol);
		Assn1->end();
		Solve1->setGeometry(QRect(400, 62, 95, 40));
		Solve1->setIcon(SolveIcon);
		Solve1->setIconSize(QSize(90, 36));
		Solve1->setFlat(true);
		Solve1->show();
		QObject::connect(Solve1, SIGNAL(clicked()), SLOT(SolveA1()));
	}

	if(onGoingGame->getAssn(1) == 2){
		Assn2->begin(this);
		Assn2->setFont(*font);
		sol.clear();
		if(onGoingGame->getAssignment(1)->get_solved()){
			sol.append("O");
		}else{
			sol.append("X");
		}
		Assn2->drawText(50, 90+(40*1), "     2                  "+Num.setNum(onGoingGame->getAssignment(1)->get_KnowReq())+"                  "+sol);
		Assn2->end();
		Solve2->setGeometry(QRect(400, 102, 95, 40));
		Solve2->setIcon(SolveIcon);
		Solve2->setIconSize(QSize(90, 36));
		Solve2->setFlat(true);
		Solve2->show();
		QObject::connect(Solve2, SIGNAL(clicked()), SLOT(SolveA2()));
	}

	if(onGoingGame->getAssn(2) == 2){
		Assn3->begin(this);
		Assn3->setFont(*font);
		sol.clear();
		if(onGoingGame->getAssignment(2)->get_solved()){
			sol.append("O");
		}else{
			sol.append("X");
		}
		Assn3->drawText(50, 90+(40*2), "     3                  "+Num.setNum(onGoingGame->getAssignment(2)->get_KnowReq())+"                  "+sol);
		Assn3->end();
		Solve3->setGeometry(QRect(400, 142, 95, 40));
		Solve3->setIcon(SolveIcon);
		Solve3->setIconSize(QSize(90, 36));
		Solve3->setFlat(true);
		Solve3->show();
		QObject::connect(Solve3, SIGNAL(clicked()), SLOT(SolveA3()));
	}

	if(onGoingGame->getAssn(3) == 2){
		Assn4->begin(this);
		Assn4->setFont(*font);
		sol.clear();
		if(onGoingGame->getAssignment(3)->get_solved()){
			sol.append("O");
		}else{
			sol.append("X");
		}
		Assn4->drawText(50, 90+(40*3), "     4                  "+Num.setNum(onGoingGame->getAssignment(3)->get_KnowReq())+"                  "+sol);
		Assn4->end();
		Solve4->setGeometry(QRect(400, 182, 95, 40));
		Solve4->setIcon(SolveIcon);
		Solve4->setIconSize(QSize(90, 36));
		Solve4->setFlat(true);
		Solve4->show();
		QObject::connect(Solve4, SIGNAL(clicked()), SLOT(SolveA4()));
	}

	if(onGoingGame->getAssn(4) == 2){
		Assn5->begin(this);
		Assn5->setFont(*font);
		sol.clear();
		if(onGoingGame->getAssignment(4)->get_solved()){
			sol.append("O");
		}else{
			sol.append("X");
		}
		Assn5->drawText(50, 90+(40*4), "     5                  "+Num.setNum(onGoingGame->getAssignment(4)->get_KnowReq())+"                  "+sol);
		Assn5->end();
		Solve5->setGeometry(QRect(400, 222, 95, 40));
		Solve5->setIcon(SolveIcon);
		Solve5->setIconSize(QSize(90, 36));
		Solve5->setFlat(true);
		Solve5->show();
		QObject::connect(Solve5, SIGNAL(clicked()), SLOT(SolveA5()));
	}

	if(onGoingGame->getAssn(5) == 2){
		Assn6->begin(this);
		Assn6->setFont(*font);
		sol.clear();
		if(onGoingGame->getAssignment(5)->get_solved()){
			sol.append("O");
		}else{
			sol.append("X");
		}
		Assn6->drawText(50, 90+(40*5), "     6                  "+Num.setNum(onGoingGame->getAssignment(5)->get_KnowReq())+"                  "+sol);
		Assn6->end();
		Solve6->setGeometry(QRect(400, 262, 95, 40));
		Solve6->setIcon(SolveIcon);
		Solve6->setIconSize(QSize(90, 36));
		Solve6->setFlat(true);
		Solve6->show();
		QObject::connect(Solve6, SIGNAL(clicked()), SLOT(SolveA6()));
	}

	if(onGoingGame->getAssn(6) == 2){
		Assn7->begin(this);
		Assn7->setFont(*font);
		sol.clear();
		if(onGoingGame->getAssignment(6)->get_solved()){
			sol.append("O");
		}else{
			sol.append("X");
		}
		Assn7->drawText(50, 90+(40*6), "     7                  "+Num.setNum(onGoingGame->getAssignment(6)->get_KnowReq())+"                  "+sol);
		Assn7->end();
		Solve7->setGeometry(QRect(400, 302, 95, 40));
		Solve7->setIcon(SolveIcon);
		Solve7->setIconSize(QSize(90, 36));
		Solve7->setFlat(true);
		Solve7->show();
		QObject::connect(Solve7, SIGNAL(clicked()), SLOT(SolveA7()));
	}

	if(onGoingGame->getAssn(7) == 2){
		Assn8->begin(this);
		Assn8->setFont(*font);
		sol.clear();
		if(onGoingGame->getAssignment(7)->get_solved()){
			sol.append("O");
		}else{
			sol.append("X");
		}
		Assn8->drawText(50, 90+(40*7), "     8                  "+Num.setNum(onGoingGame->getAssignment(7)->get_KnowReq())+"                  "+sol);
		Assn8->end();
		Solve8->setGeometry(QRect(400, 342, 95, 40));
		Solve8->setIcon(SolveIcon);
		Solve8->setIconSize(QSize(90, 36));
		Solve8->setFlat(true);
		Solve8->show();
		QObject::connect(Solve8, SIGNAL(clicked()), SLOT(SolveA8()));
	}

	if(onGoingGame->getTest(0) != NULL){
		Midterm->begin(this);
		Midterm->setFont(*testfont);
		Midterm->drawText(560, 90, ""+Num.setNum(onGoingGame->getTest(0)->get_Score()));
		Midterm->end();
	}

	if(onGoingGame->getTest(1) != NULL){
		Final->begin(this);
		Final->setFont(*testfont);
		Final->drawText(560, 230,   ""+Num.setNum(onGoingGame->getTest(1)->get_Score()));
		Final->end();
	}
}

void TestAssn::SolveA1(){
	onGoingGame->SolveAssn(0);
}

void TestAssn::SolveA2(){
	onGoingGame->SolveAssn(1);
}

void TestAssn::SolveA3(){
	onGoingGame->SolveAssn(2);
}

void TestAssn::SolveA4(){
	onGoingGame->SolveAssn(3);
}

void TestAssn::SolveA5(){
	onGoingGame->SolveAssn(4);
}

void TestAssn::SolveA6(){
	onGoingGame->SolveAssn(5);
}

void TestAssn::SolveA7(){
	onGoingGame->SolveAssn(6);
}

void TestAssn::SolveA8(){
	onGoingGame->SolveAssn(7);
}