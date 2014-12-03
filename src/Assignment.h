#include <QLabel>

class Assignment
{
public:
	static int Num_Assign;
	Assignment(int num, int KnowReq);
	bool get_solved() {return solved;}
	//void set_KnowReq(); // KnowledgeRequire<Player.knowledge
	int get_KnowReq() {return KnowledgeRequire;}
	void set_solve() {solved = true;}
private:
	
	bool solved;
	int KnowledgeRequire;
	int number;
	//////////////////
};
