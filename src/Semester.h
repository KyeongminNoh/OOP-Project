#include <QString>

class Semester 
{
public:
	Semester();
	int get_CurrentSemester(){return CurrentSemester;}
	bool get_HaveLover(){return HaveLover;}
	int get_grade(){return grade;}
	void set_CurrentSemester(int C);
	void set_HaveLover();
	void set_grade();
private:
	int CurrentSemester;
	bool HaveLover;
	int grade;
};
