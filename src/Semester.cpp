#include "Semester.h"

Semester::Semester(){
	CurrentSemester = 1;
	grade = 0;
	HaveLover = false;
}

void Semester::set_CurrentSemester(int C){
	CurrentSemester = C;
}