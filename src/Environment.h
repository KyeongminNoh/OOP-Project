class Environment // game ���࿡�� �ٲ�
{
public:
	bool get_night() { return night; }
	void set_night() {night = 1;}
	void reset_night() { night = 0;}
private:
	bool night;
	int weather; // 0: ����, 1: ��, 2: ��, 3: �帲
}