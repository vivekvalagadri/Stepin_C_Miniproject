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
Legend:
Input:		2 3 4 5 6 7 8 9 T  J  Q  K  A
Rank_Value: 2 3 4 5 6 7 8 9 10 11 12 13 14

Input:		C D H S 
Suit_Value: 1 2 3 4
*/
void setUp(){}
void tearDown(){}
void royal_flush_test(void){
	//royalflush with suit as clubs
	card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}};
	TEST_ASSERT_EQUAL(1,is_RoyalFlush(c1));
	//Not a royal flush due to not the same suits
	card c3[5]={{2,14},{1,10},{3,11},{2,13},{4,12}};
	TEST_ASSERT_EQUAL(0,is_RoyalFlush(c3));
}
void straight_flush_test(void){
	//starihtflush with suit as clubs
	card c1[5]={{1,3},{1,4},{1,5},{1,6},{1,7}};
	TEST_ASSERT_EQUAL(1,is_StraightFlush(c1));
	//Not a straightflush due to not the same suits
	card c3[5]={{2,9},{1,10},{3,11},{2,8},{4,12}};
	TEST_ASSERT_EQUAL(0,is_StraightFlush(c3));	
}
void four_ofa_kind_test(void){
	//four of a kind with different suit 
	card c1[5]={{1,3},{2,3},{3,3},{4,3},{1,7}};
	TEST_ASSERT_EQUAL(1,is_Four_of_a_Kind(c1));
	//not a four of a kind
	card c2[5]={{1,3},{2,2},{3,4},{4,3},{1,7}};
	TEST_ASSERT_EQUAL(0,is_Four_of_a_Kind(c2));
}
void fullhouse_test(void){
	//full house 
	card c1[5]={{1,3},{2,3},{3,4},{4,4},{1,4}};
	TEST_ASSERT_EQUAL(1,is_FullHouse(c1));
	//not full house 
	card c2[5]={{1,3},{2,3},{3,4},{4,4},{1,1}};
	TEST_ASSERT_EQUAL(0,is_FullHouse(c2));
}
void flush_test(void){
	//flush
	card c1[5]={{1,10},{1,11},{1,12},{1,13},{1,14}};
	TEST_ASSERT_EQUAL(1,is_Flush(c1));
	//Not a flush
	card c3[5]={{2,14},{1,10},{3,11},{2,13},{4,12}};
	TEST_ASSERT_EQUAL(0,is_Flush(c3));
}
void straight_test(void){
	//straight
	card c1[5]={{1,10},{2,11},{3,12},{4,13},{1,14}};
	TEST_ASSERT_EQUAL(1,is_Straight(c1));
	//Not a straight
	card c3[5]={{2,2},{1,7},{3,11},{2,13},{4,12}};
	TEST_ASSERT_EQUAL(0,is_Straight(c3));
}
void three_ofa_kind_test(void){	
	//three of a kind with different suit 
	card c1[5]={{1,3},{2,3},{3,3},{4,4},{1,7}};
	TEST_ASSERT_EQUAL(1,is_Three_of_a_Kind(c1));
	//not a three of a kind
	card c2[5]={{1,3},{2,2},{3,4},{4,3},{1,7}};
	TEST_ASSERT_EQUAL(0,is_Three_of_a_Kind(c2));
}
void twopair_test(void){
	//twopair
	card c1[5]={{1,3},{2,3},{3,4},{4,4},{1,7}};
	TEST_ASSERT_EQUAL(2,Pairs(c1));
	//not a twopair
	card c2[5]={{1,3},{2,9},{3,6},{4,4},{1,7}};
	TEST_ASSERT_EQUAL(0,Pairs(c2));
}
void onepair_test(void){
	//onepair
	card c1[5]={{1,3},{2,5},{3,4},{4,4},{1,7}};
	TEST_ASSERT_EQUAL(1,Pairs(c1));
	//not a pair
	card c2[5]={{1,3},{2,9},{3,6},{4,4},{1,7}};
	TEST_ASSERT_EQUAL(0,Pairs(c2));
	
}
int main(){
	UNITY_BEGIN();
	RUN_TEST(royal_flush_test,1);
	RUN_TEST(straight_flush_test,2);
	RUN_TEST(four_ofa_kind_test,3);
	RUN_TEST(fullhouse_test,4);
	RUN_TEST(flush_test,5);
	RUN_TEST(straight_test,6);
	RUN_TEST(three_ofa_kind_test,7);
	RUN_TEST(twopair_test,8);
	RUN_TEST(onepair_test,9);
	return UNITY_END();
}