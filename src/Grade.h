class Grade
{
public:
	void set_Assign(Assignment Assignment);
	void set_Test(Test test);
	void calculate_Grade();
	int get_grade() {return total_grade;}
private:
	Assignment* ass;
	Test* test;
	int total_grade;
}