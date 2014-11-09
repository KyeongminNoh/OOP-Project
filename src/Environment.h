class Environment // game ÁøÇà¿¡¼­ ¹Ù²Þ
{
public:
	bool get_night() { return night; }
	void set_night() {night = 1;}
	void reset_night() { night = 0;}
private:
	bool night;
	int weather; // 0: ¸¼À½, 1: ºñ, 2: ´«, 3: Èå¸²
}