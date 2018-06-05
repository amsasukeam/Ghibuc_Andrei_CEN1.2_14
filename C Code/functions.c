#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
* This vector is a representation of the current node and if this node was allready visited.
*/
int reach[1001];

/**
* This variable will be used to counter how many pieces were used in the sort.
*/
int counter = 0;

/**
* A matrix that retain the orientations between the nodes of the graph.
*/
int orientation[1001][1001];

/**
* Vector that retain if the source node allready appeared in the sort
*/
int adjacency_source[1001];

/**
* Vector that retain if the destination node allready appeared in the sort
*/
int adjacency_destination[1001];

/**
* Function that reads and makes the graph orientated.
*/
void orientations( int orientation [][1001] , int i , int n ){

    int source;
    int destination;

    srand(time(NULL));

    while( i <= n){

         source = rand()%10 + 1;
         destination = rand()%10 + 1;

         while( adjacency_source[source] == 1 ) //Randomly generate source node if it haven't allready occured.
               source = rand()%10 + 1;
        adjacency_source[source] = 1;

         while(adjacency_destination[destination] == 1 )// Randomly generate destination node if it haven't allready occured.
               destination = rand()%10 + 1;
         adjacency_destination[destination] = 1;

         orientation[source][destination] = 1; // Assigning the orietation from the source to node.
         i++;
        }
}

/**
* This function will do the tropological sort of the graph.
*/
void depth_first_search(int source){

     int destination;
     int i;
     reach[source]=1;

     for(i = 1;i <= 10; i++)
         if(orientation[source][i] && !reach[i]){

            printf("\n %d->%d",source,i);// Printing the tropological sort.
            counter++;// Counting the number of pieces used.
            depth_first_search(i);
            }
}
