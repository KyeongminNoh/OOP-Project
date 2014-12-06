#include<QLabel>

class Test
{
public:
	Test(int P_Know, int KnowR);
	int get_Score() {return Score;}
	QString getGrade(){return Grade;}
private:
	int Score;
	QString Grade;
};
