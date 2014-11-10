class Semester 
{
public:
	int get_CurrentSemester(){return CurrentSemester;}
	bool get_HaveLover(){return HaveLover;}
	int grade(){return grade;}
	void set_CurrentSemester();
	void set_HaveLover();
	void set_grade();
private:
	int CurrentSemester;
	bool HaveLover;
	int grade;
}
