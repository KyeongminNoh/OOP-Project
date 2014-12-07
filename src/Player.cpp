#include "Player.h"

Player::Player( bool Man, bool unNocturnal){
	if(Man == true){
		Max_Health = 100;
		isMan = true;
	}
	else{
		Max_Health = 90;
		isMan = false;
	}

	if(unNocturnal == false){
		isNocturnal = true;
	}else{
		isNocturnal = false;
	}

	Max_Lonely = 100;
	Num_Friend = 0;
	Knowledge = 0;
	Finance = 100;
	Sociality = 0;
	Lonely = 0;
	Health = Max_Health;

}

void Player::set_nocturnal(int S_Noc){
	isNocturnal = S_Noc;
}
void Player::set_Sociality(qreal S_Social){
	Sociality = Sociality + S_Social;
}

void Player::set_Lonely(qreal S_Lone){
	
	Lonely = Lonely + S_Lone;
	if(Lonely<0){
		Lonely = 0;
	}
}
void Player::set_Lonely(){
	Lonely = 50;
}

void Player::set_Health(qreal S_Hea){
	Health = Health + S_Hea;
	if(Health >= Max_Health)
		Health = Max_Health;
}

void Player::set_Knowledge(qreal S_Know){
	Knowledge+=S_Know;
}

void Player::set_Finance(qreal S_Finan){
	Finance += S_Finan;
};

void Player::set_Max_Health(qreal M_Hea){
	Max_Health += M_Hea;
}

void Player::add_Friend(){
	if(isMan){
		Sociality += 1;
	}
	else{
		Sociality += 1.5;
	}
}
