class Assignment
{
public:
	bool get_solve() {return solve;}
	void check_knowledge(); // req_knowledge<Player.knowledge
	int get_req_time() {return req_time;}
	void set_solve() {solve = true;}
private:
	static int num_assign;
	bool solve;
	int req_knowledge;
	int req_time;
	//////////////////
}