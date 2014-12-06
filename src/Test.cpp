#include "Test.h"

Test::Test(int P_Know, int KnowR){
	int sub = P_Know - KnowR;
	if(sub>=0){
		Score = 0;
		Grade = "A";
	}
	else if(sub<0&&sub>=-3){
		Score = -1;
		Grade = "B";
	}
	else if(sub<-3&&sub>=-6){
		Score = -2;
		Grade = "C";
	}
	else if(sub<-6&&sub>=-9){
		Score = -3;
		Grade = "D";
	}
	else if(sub<-9&&sub>=-12){
		Score = -4;
		Grade = "F";
	}
	else if(sub<-12&&sub>=-15){
		Score = -5;
	}
	else if(sub<-15){
		Score = -6;
	}

}