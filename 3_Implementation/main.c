#include "./inc/poker.h"
#include <stdlib.h>
#include <stdio.h>
#define NUM_CARDS 5

int main(){
	card * card_ptr=(card *)calloc(5,sizeof(card));
	get_Input(card_ptr);
	for(int i=0;i<NUM_CARDS;i++){
		printf("%d%d\n",(card_ptr+i)->rank,(card_ptr+i)->suit);
	}
	free(card_ptr);
}