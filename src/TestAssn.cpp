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

	Solve1= new QPushButton(this);
	Solve1->setGeometry(QRect(540, 10, 80, 30));
	Solve1->setText("Solve");
	Solve1->show();

	Solve2= new QPushButton(this);
	Solve2->setGeometry(QRect(540, 50, 80, 30));
	Solve2->setText("Solve");
	Solve2->show();

	Solve3= new QPushButton(this);
	Solve3->setGeometry(QRect(540, 90, 80, 30));
	Solve3->setText("Solve");
	Solve3->show();

	Solve4= new QPushButton(this);
	Solve4->setGeometry(QRect(540, 130, 80, 30));
	Solve4->setText("Solve");
	Solve4->show();

	Solve5= new QPushButton(this);
	Solve5->setGeometry(QRect(540, 170, 80, 30));
	Solve5->setText("Solve");
	Solve5->show();

	Solve6= new QPushButton(this);
	Solve6->setGeometry(QRect(540, 210, 80, 30));
	Solve6->setText("Solve");
	Solve6->show();
	
	Solve7= new QPushButton(this);
	Solve7->setGeometry(QRect(540, 250, 80, 30));
	Solve7->setText("Solve");
	Solve7->show();

	Solve8= new QPushButton(this);
	Solve8->setGeometry(QRect(540, 290, 80, 30));
	Solve8->setText("Solve");
	Solve8->show();

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
	QObject::connect(Solve1, SIGNAL(clicked()), SLOT(SolveA1()));
	QObject::connect(Solve2, SIGNAL(clicked()), SLOT(SolveA2()));
	QObject::connect(Solve3, SIGNAL(clicked()), SLOT(SolveA3()));
	QObject::connect(Solve4, SIGNAL(clicked()), SLOT(SolveA4()));
	QObject::connect(Solve5, SIGNAL(clicked()), SLOT(SolveA5()));
	QObject::connect(Solve6, SIGNAL(clicked()), SLOT(SolveA6()));
	QObject::connect(Solve7, SIGNAL(clicked()), SLOT(SolveA7()));
	QObject::connect(Solve8, SIGNAL(clicked()), SLOT(SolveA8()));
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
		Assn1->drawText(30, 32+(40*0), "Assn1  KnowRequire: "+Num.setNum(onGoingGame->getAssignment(0)->get_KnowReq())+" submit? "+sol);
		Assn1->end();
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
		Assn2->drawText(30, 32+(40*1), "Assn2  KnowRequire: "+Num.setNum(onGoingGame->getAssignment(1)->get_KnowReq())+" submit? "+sol);
		Assn2->end();
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
		Assn3->drawText(30, 32+(40*2), "Assn3  KnowRequire: "+Num.setNum(onGoingGame->getAssignment(2)->get_KnowReq())+" submit? "+sol);
		Assn3->end();
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
		Assn4->drawText(30, 32+(40*3), "Assn4  KnowRequire: "+Num.setNum(onGoingGame->getAssignment(3)->get_KnowReq())+" submit? "+sol);
		Assn4->end();
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
		Assn5->drawText(30, 32+(40*4), "Assn5  KnowRequire: "+Num.setNum(onGoingGame->getAssignment(4)->get_KnowReq())+" submit? "+sol);
		Assn5->end();
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
		Assn6->drawText(30, 32+(40*5), "Assn6  KnowRequire: "+Num.setNum(onGoingGame->getAssignment(5)->get_KnowReq())+" submit? "+sol);
		Assn6->end();
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
		Assn7->drawText(30, 32+(40*6), "Assn7  KnowRequire: "+Num.setNum(onGoingGame->getAssignment(6)->get_KnowReq())+" submit? "+sol);
		Assn7->end();
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
		Assn8->drawText(30, 32+(40*7), "Assn8  KnowRequire: "+Num.setNum(onGoingGame->getAssignment(7)->get_KnowReq())+" submit? "+sol);
		Assn8->end();
	}

	if(onGoingGame->getTest(0) != NULL){
		Midterm->begin(this);
		Midterm->setFont(*font);
		Midterm->drawText(30, 362, "Midterm   Scroe :"+Num.setNum(onGoingGame->getTest(0)->get_Score()));
		Midterm->end();
	}

	if(onGoingGame->getTest(1) != NULL){
		Final->begin(this);
		Final->setFont(*font);
		Final->drawText(30, 402,   "Final     Scroe :"+Num.setNum(onGoingGame->getTest(1)->get_Score()));
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