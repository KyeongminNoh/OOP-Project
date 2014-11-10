class Test
{
public:
	int get_Score() {return Score;}
	void set_Score(); // KnowledgeRequirment보다 높으면 100점 낮으면 환산
private:
	int KnowledgeRequirment;
	int Score;
}
