#include "../inc/poker.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void get_Input(card* card_ptr){
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
void count_ranks(card *card_pointer, int ranks_in_hand[][2]){
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
/////////////////////////////////
int is_RoyalFlush(card *card_pointer){
  if(is_StraightFlush(card_pointer) && card_pointer->rank==10)
    return 1;
  return 0;
}
int is_StraightFlush(card *card_pointer){
  if(is_Straight(card_pointer)&&is_Flush(card_pointer))
    return 1;
  return 0;
}
int is_Four_of_a_Kind(card *card_pointer){
  int ranks_in_hand[NUM_OF_CARDS][2];
  int hash_pair;
  count_ranks(card_pointer, ranks_in_hand);
  for (hash_pair = 0; hash_pair < NUM_OF_CARDS && ranks_in_hand[hash_pair][KEY] != 0; hash_pair++){
    if (ranks_in_hand[hash_pair][VALUE] == 4) 
      return 1;
  }
  return 0;
}
int is_FullHouse(card *card_pointer){
  if(is_Three_of_a_Kind(card_pointer) && Pairs(card_pointer)==1)
    return 1;
  return 0;
}
int is_Flush(card *card_pointer){
  /* check for flush: all of same suit */
  for (int index = 1; index < NUM_OF_CARDS; index++)
    if ((card_pointer)->suit != (card_pointer+index)->suit)
      return 0;
  return 1;
}
int is_Straight(card* card_pointer){
  void swap(int* xp, int* yp){
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
int is_Three_of_a_Kind(card *card_pointer){
  int ranks_in_hand[NUM_OF_CARDS][2];
  int hash_pair;
  count_ranks(card_pointer, ranks_in_hand);
  for (hash_pair = 0; hash_pair < NUM_OF_CARDS && ranks_in_hand[hash_pair][KEY] != 0; hash_pair++){
    if (ranks_in_hand[hash_pair][VALUE] == 3) 
      return 1;
  }
  return 0;
}
int Pairs(card *card_pointer){
  int ranks_in_hand[NUM_OF_CARDS][2];
  int hash_pair;
  int count=0;
  count_ranks(card_pointer, ranks_in_hand);
  for (hash_pair = 0; hash_pair < NUM_OF_CARDS && ranks_in_hand[hash_pair][KEY] != 0; hash_pair++){
    if (ranks_in_hand[hash_pair][VALUE] == 2) 
      count++;
  }
  return count;
}
void analyze_print(card *card_pointer){
  if (is_RoyalFlush(card_pointer))       
    printf("Royal flush!");
  else if (is_StraightFlush(card_pointer)) 
    printf("Straight flush!");
  else if (is_Four_of_a_Kind(card_pointer))         
    printf("Four of a kind!");
  else if (is_FullHouse(card_pointer))
    printf("Full house!");
  else if (is_Flush(card_pointer))
    printf("Flush!");
  else if (is_Straight(card_pointer))     
    printf("Straight!");
  else if (is_Three_of_a_Kind(card_pointer))
    printf("Three of a kind!");
  else if (Pairs(card_pointer) == 2)   
    printf("Two Pair!");
  else if (Pairs(card_pointer) == 1)   
    printf("One Pair!");
  else   
    printf("High card!");
  printf("\n");
}