#include <QLabel>

class Assignment
{
public:
	static int Num_Assign;
	Assignment(int num, int KnowReq);
	bool get_solved() {return solved;}
	bool get_Cannotsolve() {return cannotsolve;}
	//void set_KnowReq(); // KnowledgeRequire<Player.knowledge
	int get_KnowReq() {return KnowledgeRequire;}
	void set_solve() {solved = true;}
	void set_Cannotsolve(){cannotsolve = true;}
private:
	bool cannotsolve;
	bool solved;
	int KnowledgeRequire;
	int number;
	//////////////////
};
