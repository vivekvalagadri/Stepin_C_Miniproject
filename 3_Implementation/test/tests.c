/**
 * @defgroup   Poker tests
 *
 * @brief      This file implements Poker tests.
 *
 * @author     Vivek
 * @date       2021
 */

#include <stdio.h>   
#include "../inc/poker.h"
#include "../unity/unity.h"

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

      case 'C': s = 1; break;
      case 'D': s = 2; break;
      case 'H': s = 3; break;
      case 'S': s = 4; break;
      */
void setUp(){}
void tearDown(){}
void royal_flush_test(void){
	//royalflush with suit as clubs
	card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}};
	TEST_ASSERT_EQUAL(1,is_RoyalFlush(c1));
	//royalflush with suit as diamonds
	card c2[5]={{2,14},{2,10},{2,11},{2,13},{2,12}};
	TEST_ASSERT_EQUAL(1,is_RoyalFlush(c2));
	//Not a royal flush due to not the same suits
	card c3[5]={{2,14},{1,10},{3,11},{2,13},{4,12}};
	TEST_ASSERT_EQUAL(0,is_RoyalFlush(c3));

}
void straight_flush_test(void){
	//starihtflush with suit as clubs
	card c1[5]={{1,3},{1,4},{1,5},{1,6},{1,7}};
	TEST_ASSERT_EQUAL(1,is_StraightFlush(c1));
	//royalflush with suit as hearts
	card c2[5]={{3,4},{3,8},{3,5},{3,7},{3,6}};
	TEST_ASSERT_EQUAL(1,is_StraightFlush(c2));
	//Not a straightflush due to not the same suits
	card c3[5]={{2,9},{1,10},{3,11},{2,8},{4,12}};
	TEST_ASSERT_EQUAL(0,is_StraightFlush(c3));
	
}
void four_ofa_kind_test(void){
	//starihtflush with suit as clubs
	card c1[5]={{1,3},{2,3},{3,3},{4,3},{1,7}};
	TEST_ASSERT_EQUAL(1,is_StraightFlush(c1));

	
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
	RUN_TEST(royal_flush_test);
	RUN_TEST(straight_flush_test);
	return UNITY_END();
}