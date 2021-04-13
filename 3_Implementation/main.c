#include "./inc/poker.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	int royal_flush, straight, flush, four, three,pairs;
	card * card_ptr=(card *)calloc(5,sizeof(card));
	get_Input(card_ptr);
	type_of_hand(card_ptr, &royal_flush, &straight, &flush, &four, &three, &pairs);
	print_result(royal_flush,straight,flush,four,three,pairs);
	free(card_ptr);
}