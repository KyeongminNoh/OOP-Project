#include <QtGlobal>

class Player{

public:
	Player(bool Nocturnal, bool Man);
	void set_Lonely(qreal S_Lone);
	void set_Lonely();
	void set_Health(qreal S_Hea);
	void set_Knowledge(qreal S_Know); // Knowledge+=S_Know	
	void set_Finance(qreal S_Finan);
	void set_Sociality(qreal S_social);
	void set_Max_Health(qreal M_Hea); // Max_strength=M_str;

	void check_Max_Health(); // max값이 넘으면 strength=Max_strength
	qreal check_Max_Lonely(); // max값 넘으면 오류 return 0;

	void add_Friend(); // Friend++
	
	qreal get_Sociality(){return Sociality;}
	qreal get_Finance(){return Finance;}
	qreal get_Knowledge(){return Knowledge;}
	qreal get_Health(){return Health;}
	qreal get_Lonely(){return Lonely;}
	qreal get_Max_Health(){return Max_Health;}
	qreal get_Max_Lonely(){return Max_Lonely;}
	bool get_Nocturnal() {return isNocturnal;}
	bool get_Man() {return isMan;}
private:
	bool isNocturnal;
	bool isMan;
	qreal Knowledge;
	qreal Health;
	qreal Lonely;
	qreal Finance;
	qreal Max_Health;
	qreal Max_Lonely;
	qreal Num_Friend;
	qreal Sociality;

};
