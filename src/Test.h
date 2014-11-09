class Test
{
public:
	int get_score() {return score;}
	void set_score(); // req_knowledge보다 높으면 100점 낮으면 환산
private:
	int req_knowledge;
	int score;
}