#include<stdio.h>

#include<stdlib.h> // For rand()

/*
 * What does a number guessing game do?
 * 1. Generates a random number from a range.
 * 2. Makes the user guess the number.
 * 3. Provides hint about how close the user is.
 * 4. When correct guess, then show celebration.
 * */

/*
 * Questions:
 * 1. How do random number generate in c?
 * */

int main() {

  // this function returns a random number
  int x = rand();

  printf("%d", x);

  return 0;
}
