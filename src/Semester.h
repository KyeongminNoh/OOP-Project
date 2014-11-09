class Semester 
{
public:
	int get_current_semester(){return current_semester;}
	bool get_have_lover(){return have_lover;}
	int grade(){return grade;}
	void set_current_semester();
	void set_have_lover();
	void set_grade();
private:
	int current_semester;
	bool have_lover;
	int grade;
}