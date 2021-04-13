#include "../inc/poker.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void get_Input(card* card_ptr){
	printf("Rank goes from 2,3,4....T,J,Q,K,A\n");
	printf("Suits are C D H S\n");
	printf("Example TC for Ten of Clubs\n");
	int r,s,card = 0;
  while (card < NUM_OF_CARDS) {
    int bad_card = 0;
    char ch;
    printf("Enter a card: ");

    switch (toupper(getchar())) {
      case '0': exit(EXIT_SUCCESS);
      case '2': r = 2; break;
      case '3': r = 3; break;
      case '4': r = 4; break;
      case '5': r = 5; break;
      case '6': r = 6; break;
      case '7': r = 7; break;
      case '8': r = 8; break;
      case '9': r = 9; break;
      case 'T':r = 10; break;
      case 'J': r = 11; break;
      case 'Q': r = 12; break;
      case 'K': r = 13; break;
      case 'A': r = 14; break;
      default: bad_card = 1;
    }

    switch (toupper(getchar())) {
      case 'C': s = 1; break;
      case 'D': s = 2; break;
      case 'H': s = 3; break;
      case 'S': s = 4; break;
      default:  bad_card = 1;
    }

    while ((ch = getchar()) != '\n')
      if (ch != ' ') bad_card = 1;

    if (bad_card)
      printf("Bad card; ignored.\n");
    else if (is_Duplicate(card_ptr, r, s))
      printf("Duplicate card; ignored.\n");
    else {
      (card_ptr+card)->rank= r;
      (card_ptr+card)->suit= s;
      card++;
    }
  }  /* end hand */
}

int is_Duplicate(card * card_ptr,int r,int s){
	int flag=0;
	for(int i=0;i<NUM_OF_CARDS;i++){
		if(s==(card_ptr+i)->suit && r==(card_ptr+i)->rank){
			flag=1;
			break;
		}
	}
	return flag;
}

void type_of_hand(card *card_pointer, int* royal_flush, int* straight, int* flush, int* four, int* three, int* pairs){
  int index, min_rank, max_rank, hash_pair;
  int ranks_in_hand[NUM_OF_CARDS][2];

  *flush = is_flush(card_pointer);

  /* find the smallest and largest ranks */
  max_rank = min_rank = card_pointer->rank;
  for (index = 1; index < NUM_OF_CARDS; index++) {
    if ((card_pointer+index)->rank < min_rank)
      min_rank = (card_pointer+index)->rank;
    if ((card_pointer+index)->rank > max_rank)
      max_rank = (card_pointer+index)->rank;
  }

  /* difference will be 4 (for a 5 card hand) if they're all consecutive */
  *straight =  is_straight(card_pointer);

  /* if we're consecutive starting at 10, then max must be the Ace */
  *royal_flush = *flush && *straight && min_rank == 10;

  *four  = 0;
  *three = 0;
  *pairs = 0;

  count_ranks(card_pointer, ranks_in_hand);
  /* a hand can have from 1 to 5 ranks */

  /* [> check for 4-of-a-kind, 3-of-a-kind, and pairs <] */
  for (hash_pair = 0; hash_pair < NUM_OF_CARDS && ranks_in_hand[hash_pair][KEY] != 0; hash_pair++) {
    if (ranks_in_hand[hash_pair][VALUE] == 4) *four = 1;
    if (ranks_in_hand[hash_pair][VALUE] == 3) *three = 1;
    /* if (ranks_in_hand[hash_pair][VALUE] == 2) *pairs++; */
    /* above line with '*pairs++' fails to increment the value */
    if (ranks_in_hand[hash_pair][VALUE] == 2) (*pairs)++;
  }
}

int is_flush(card *card_pointer)
{
  /* check for flush: all of same suit */
  for (int index = 1; index < NUM_OF_CARDS; index++)
    if ((card_pointer)->suit != (card_pointer+index)->suit)
      return 0;
  return 1;
}
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void sort_hand(card *card_pointer){
  int i, j;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < NUM_OF_CARDS-1; i++) {
 
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (j = i + 1; j < NUM_OF_CARDS; j++)
            if (((card_pointer+j)->rank)< ((card_pointer+min_idx)->rank))
                min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        swap(&((card_pointer+min_idx)->rank), &((card_pointer+i)->rank));
    }
}
int is_straight(card* card_pointer){
  sort_hand(card_pointer);
  if((card_pointer->rank)==2 && (card_pointer+4)->rank==14){
    for(int i=0;i<3;i++){
      if(((card_pointer+i+1)->rank)-((card_pointer+i)->rank)!=1)
        return 0;
    return 1;
    }
  }
  else{
    for(int i=0;i<4;i++){
      if(((card_pointer+i+1)->rank)-((card_pointer+i)->rank)!=1)
        return 0;
    return 1;
    }
  }
}
void count_ranks(card *card_pointer, int ranks_in_hand[][2])
{
  int index, hash_pair;

  for (hash_pair = 0; hash_pair < NUM_OF_CARDS; hash_pair++)
    ranks_in_hand[hash_pair][KEY] = ranks_in_hand[hash_pair][VALUE] = 0;

  /*
   * start with rank of first card in the hand
   * as our first hash key
   */
  ranks_in_hand[0][KEY] = card_pointer->rank;
  ranks_in_hand[0][VALUE] = 1;

  for (index = 1; index < NUM_OF_CARDS; index++)  {
    hash_pair = 0;
    /* find the current hand's rank or the next empty element
     * which will be our next hash key
     */
    while (ranks_in_hand[hash_pair][KEY] != (card_pointer+index)->rank && ranks_in_hand[hash_pair][KEY] != 0)
      hash_pair++;
    /*
     * new hash key: the current hand's rank was not found in the hash
     */
    if (ranks_in_hand[hash_pair][KEY] == 0)
      ranks_in_hand[hash_pair][KEY] = (card_pointer+index)->rank;

    ranks_in_hand[hash_pair][VALUE]++;
  }
}
void print_result(int royal_flush, int straight, int flush, int four, int three, int pairs){
  if (royal_flush)       printf("Royal flush");
  else if (straight && flush) printf("Straight flush");
  else if (four)         printf("Four of a kind");
  else if (three &&
           pairs == 1)   printf("Full house");
  else if (flush)        printf("Flush");
  else if (straight)     printf("Straight");
  else if (three)        printf("Three of a kind");
  else if (pairs == 2)   printf("Two Pair");
  else if (pairs == 1)   printf("One Pair");
  else                   printf("High card");
  printf("\n\n");
}