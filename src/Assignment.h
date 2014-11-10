class Assignment
{
public:
	bool get_solved() {return solved;}
	void check_Knowledge(); // KnowledgeRequire<Player.knowledge
	int get_TimeRequire() {return TimeRequire;}
	void set_solve() {solved = true;}
private:
	static int Num_Assign;
	bool solved;
	int KnowledgeRequire;
	int TimeRequire;
	//////////////////
}
