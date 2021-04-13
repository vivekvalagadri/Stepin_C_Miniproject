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
 * @brief      Determines if duplicate cards are present.
 *
 * @param      card_pointer  The card pointer
 * @param[in]  rank          The rank
 * @param[in]  suit          The suit
 *
 * @return     True if duplicate, False otherwise.
 */
int is_Duplicate(card *card_pointer,int rank ,int suit);
/**
 * @brief      returns the type of hand 
 *
 * @param      card_pointer  The card pointer
 * @param      royal_flush   The royal flush
 * @param      straight      The straight
 * @param      flush         The flush
 * @param      four          Four
 * @param      three         Three
 * @param      pairs         The pairs
 */
void type_of_hand(card *card_pointer, int* royal_flush, int* straight, int* flush, int* four, int* three, int* pairs);
/**
 * @brief      Determines whether the specified card pointer is flush.
 *
 * @param      card_pointer  The card pointer
 *
 * @return     True if the specified card pointer is flush, False otherwise.
 */
int is_flush(card *card_pointer);
/**
 * @brief      Determines whether the specified card pointer is straight.
 *
 * @param      card_pointer  The card pointer
 *
 * @return     True if the specified card pointer is straight, False otherwise.
 */
int is_straight(card *card_pointer);
/**
 * @brief      Counts the number of ranks.
 *
 * @param      card_pointer   The card pointer
 * @param      ranks_in_hand  The ranks in hand
 */
void count_ranks(card *card_pointer, int ranks_in_hand[][2]);
/**
 * @brief      Prints a result.
 *
 * @param[in]  royal_flush  The royal flush
 * @param[in]  straight     The straight
 * @param[in]  flush        The flush
 * @param[in]  four         Four of a kind
 * @param[in]  three        Three of a Kind
 * @param[in]  pairs        Counts number of pairs pairs
 */
void print_result(int royal_flush, int straight, int flush, int four, int three, int pairs);
#endif