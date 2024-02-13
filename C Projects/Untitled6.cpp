
#include <stdio.h>
#include <stdlib.h>

int rand_int(int a, int b) {

return rand() % ((b - a + 1) + a);
}

int main() {

int tosses = 0, min = 0, heads = 0, tails = 0; 
const int HEAD = 0;
const int TAILS = 1;
/*users input for number of tosses*/
printf("Enter number of coin tosses: ");
scanf("%i", &min);

while (tosses < min) {
    tosses++;
    if (rand_int(HEADS, TAILS) == HEADS)
        heads++;
    else
        tails++;
}

//prints results of tosses
printf("Number of heads: %i\n", heads);
printf("Number of tails: %i\n", tails);

return 0;}
