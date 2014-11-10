class Grade
{
public:
	void set_Assign(Assignment Assignment);
	void set_Test(Test test);
	void calculate_Grade();
	int get_Grade() {return Total_Grade;}
private:
	Assignment* assignment;
	Test* test;
	int TotalGrade;
}
