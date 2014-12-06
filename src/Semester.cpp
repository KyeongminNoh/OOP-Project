#include "Semester.h"

Semester::Semester(){
	CurrentSemester = 1;
	grade = 0;
	HaveLover = false;
	for(int i=0; i<8; i++){
		Grade[i] = "";
	}
}

void Semester::set_CurrentSemester(int C){
	CurrentSemester = C;
}

void Semester::setGrade(QString G){
	Grade[CurrentSemester] = G;
}