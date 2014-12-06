#include <QString>

class Semester 
{
public:
	Semester();
	int get_CurrentSemester(){return CurrentSemester;}
	bool get_HaveLover(){return HaveLover;}
	qreal* get_grade(){return gradeNum;}
	QString GetGrade(int i){return Grade[i];};
	void set_CurrentSemester(int C);
	void set_HaveLover();
	void setGrade(QString G);
	void setGradeNum(qreal G);
	void setPastGrade(int k,QString G);
	void setPastGradeNum(int k,qreal G);
private:
	int CurrentSemester;
	bool HaveLover;
	qreal gradeNum[8];
	QString Grade[8];
};
