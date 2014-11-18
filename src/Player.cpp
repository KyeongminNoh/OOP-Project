#include "Player.h"

Player::Player(bool Nocturnal, bool Man){
	if(Man == true)
		Max_Health = 110;
	else
		Max_Health = 100;

	Max_Lonely = 100;
	Num_Friend = 0;
	Knowledge = 1;
	Finance = 3000;
	Sociality = 1;
	Lonely = 0;
	Health = Max_Health;

}

void Player::set_Sociality(qreal S_Social){
	Sociality = Sociality + S_Social;
}

void Player::set_Lonely(qreal S_Lone){
	Lonely = Lonely + S_Lone;
}

void Player::set_Health(qreal S_Hea){
	Health = Health + S_Hea;
}

void Player::set_Knowledge(qreal S_Know){
	Knowledge+=S_Know;
}

void Player::set_Finance(qreal S_Finan){
	Finance += S_Finan;	
};
