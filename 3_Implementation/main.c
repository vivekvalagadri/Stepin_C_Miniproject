#include "./inc/poker.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	card * card_ptr=(card *)calloc(5,sizeof(card));
	get_Input(card_ptr);
	analyze_print(card_ptr);
	free(card_ptr);
}