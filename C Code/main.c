#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

/**
* Matrix that was used allready in the function orientations and explained.
*/
int orientation[1001][1001];

/**
*Variable that was used for counting the number of used pieces.
*/
int counter;

/**
* Main function of my project
*/
int main()
{
    int source;
    int destination;

    printf("The tropological sort is : ");

    orientations(orientation, 1, 10);
    depth_first_search(rand()%10+1);

    printf("\n The number of pieces used : %d ", counter);

    return 0;
}
