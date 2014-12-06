#include "Semester.h"

Semester::Semester(){
	CurrentSemester = 1;

	HaveLover = false;
	for(int i=0; i<8; i++){
		Grade[i] = "";
		gradeNum[i] = 0;
	}
}

void Semester::set_CurrentSemester(int C){
	CurrentSemester = C;
}

void Semester::setGrade(QString G){
	Grade[CurrentSemester] = G;
}

void Semester::setGradeNum(qreal G){
	gradeNum[CurrentSemester] = G;
}