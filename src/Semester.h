#include <QString>

class Semester 
{
public:
	Semester();
	int get_CurrentSemester(){return CurrentSemester;}
	bool get_HaveLover(){return HaveLover;}
	qreal* get_grade(){return gradeNum;}

	void set_CurrentSemester(int C);
	void set_HaveLover();
	void setGrade(QString G);
	void setGradeNum(qreal G);
private:
	int CurrentSemester;
	bool HaveLover;
	qreal gradeNum[8];
	QString Grade[8];
};
