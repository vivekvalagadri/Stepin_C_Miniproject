/**
 * @defgroup   POKER poker
 * @file
 * @brief      This file implements poker hands.
 *
 * @author     Vivek
 * @date       8-04-2021
 */

#ifndef __POKER_H__
#define __POKER_H__ 
/**
 * Card Structure
 */
#define NUM_OF_CARDS 5
#define KEY 0
#define VALUE 1
typedef struct card{
	int suit;
	int rank;
}card;
/**
 * @brief      Gets the input.
 *
 * @param      card_pointer  The card pointer
 */
void get_Input(card *card_pointer);
/**
 * @brief      Determines whether the specified card pointer is royal flush.
 *
 * @param      card_pointer  The card pointer
 *
 * @return     True if the specified card pointer is royal flush, False otherwise.
 */
int is_RoyalFlush(card *card_pointer);
/**
 * @brief      Determines whether the specified card pointer is straight flush.
 *
 * @param      card_pointer  The card pointer
 *
 * @return     True if the specified card pointer is straight flush, False otherwise.
 */
int is_StraightFlush(card *card_pointer);
/**
 * @brief      Determines whether the specified card pointer is four of a kind.
 *
 * @param      card_pointer  The card pointer
 *
 * @return     True if the specified card pointer is four of a kind, False otherwise.
 */
int is_Four_of_a_Kind(card *card_pointer);
/**
 * @brief      Determines whether the specified card pointer is full house.
 *
 * @param      card_pointer  The card pointer
 *
 * @return     True if the specified card pointer is full house, False otherwise.
 */
int is_FullHouse(card *card_pointer);
/**
 * @brief      Determines whether the specified card pointer is flush.
 *
 * @param      card_pointer  The card pointer
 *
 * @return     True if the specified card pointer is flush, False otherwise.
 */
int is_Flush(card *card_pointer);
/**
 * @brief      Determines whether the specified card pointer is straight.
 *
 * @param      card_pointer  The card pointer
 *
 * @return     True if the specified card pointer is straight, False otherwise.
 */
int is_Straight(card* card_pointer);
/**
 * @brief      Determines whether the specified card pointer is three of a kind.
 *
 * @param      card_pointer  The card pointer
 *
 * @return     True if the specified card pointer is three of a kind, False otherwise.
 */
int is_Three_of_a_Kind(card *card_pointer);
/**
 * @brief      Determines the number of pairs in the hand
 *
 * @param      card_pointer  The card pointer
 *
 * @return     the number of pairs in the hand
 */
int Pairs(card *card_pointer);
/**
 * @brief      Analyzes and Prints the best hand
 *
 * @param      card_pointer  The card pointer
 */
void analyze_print(card *card_pointer);
#endif