#include "../inc/poker.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#ifndef NUM_CARDS
#define NUM_CARDS 5
#endif

void get_Input(card* card_ptr){
	printf("Rank goes from 2,3,4....T,J,Q,K,A\n");
	printf("Suits are C D H S\n");
	printf("Example TC for Ten of Clubs\n");
	int r,s,card = 0;
  while (card < NUM_CARDS) {
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
	for(int i=0;i<NUM_CARDS;i++){
		if(s==(card_ptr+i)->suit && r==(card_ptr+i)->rank){
			flag=1;
			break;
		}
	}
	return flag;
}