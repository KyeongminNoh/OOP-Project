class Player{
public:
	void set_knowledge(int S_know); // knowledge+=S_know	
	void set_finance(int S_finan);
	void set_sociality(int S_social);
	void set_Max_strength(int M_str); // Max_strength=M_str;
	void check_Max_strength(); // max값이 넘으면 strength=Max_strength
	int check_Max_lonely(); // max값 넘으면 오류 return 0;
	void add_friend(); // friend++
	bool get_nocturnal() {return nocturnal;}
	bool get_man() {return man;}
private:
	bool nocturnal;
	bool man;
	int knowledge;
	int strength;
	int lonely;
	int finance;
//	int Max_knowledge;
	int Max_strength;
	int Max_lonely;
//	int Max_finance;
	int Num_friend;
	int sociality;

//	int position; // x,y 따로?
};