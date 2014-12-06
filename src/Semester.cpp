#include "Semester.h"

Semester::Semester(){
	CurrentSemester = 1;

	HaveLover = false;
	for(int i=0; i<8; i++){
		Grade[i] = "";
		gradeNum[i] = -1;
	}
}

void Semester::set_CurrentSemester(int C){
	CurrentSemester = C;
}

void Semester::setGrade(QString G){
	Grade[CurrentSemester-1] = G;
}

void Semester::setGradeNum(qreal G){
	gradeNum[CurrentSemester-1] = G;
}