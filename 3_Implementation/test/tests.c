/**
 * @defgroup   Poker tests
 *
 * @brief      This file implements Poker tests.
 *
 * @author     Vivek
 * @date       2021
 */

#include <stdio.h>   
#include "../inc/notfun.h"
#include ".. /unity/unity.h"


void setUp(){}
void tearDown(){}

/*
case '0': exit(EXIT_SUCCESS);
      case '2': rank = 2; break;
      case '3': rank = 3; break;
      case '4': rank = 4; break;
      case '5': rank = 5; break;
      case '6': rank = 6; break;
      case '7': rank = 7; break;
      case '8': rank = 8; break;
      case '9': rank = 9; break;
      case 'T': rank = 10; break;
      case 'J': rank = 11; break;
      case 'Q': rank = 12; break;
      case 'K': rank = 13; break;
      case 'A': rank = 14; break;
      */
void royal_flush_test(void){
	card c1={{1,10},{1,11},{1,12},{1,13},{1,14}};
}
void straight_flush_test(void){
	
}
void four_ofa_kind_test(void){
	
}
void fullhouse_test(void){
	
}
void flush_test(void){
	
}
void straight_test(void){

}
void three_ofa_kind_test(void){
	
}
void twopair_test(void){
	
}
void onepair_test(void){
	
}
void high_card_test(void){
	
}
int main(){
	UNITY_BEGIN();
	//RUN_TEST(zero_test);
	return UNITY_END();
}