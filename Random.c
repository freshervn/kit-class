#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> // srand
void printRandoms(int lower, int upper, int count) 
{ 
    int i; 
    for (i = 0; i < count; i++) { 
        int num = (rand() % 
           (upper - lower + 1)) + lower; 
        printf("%d ", num); 
    } 
} 
  
// Driver code 
int main() 
{ 
    int lower = 2, upper = 7, count = 5; 
  
    // Use current time as  
    // seed for random generator 
    srand(time(0)); 
  
    printRandoms(lower, upper, count); 
  
    return 0; 
} 