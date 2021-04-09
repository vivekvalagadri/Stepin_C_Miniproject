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

#endif