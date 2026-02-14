#include<stdio.h>
#include<stdlib.h> // For rand() and system("")
#include<time.h> // for time()

/*
 * What does a number guessing game do?
 * 1. Generates a random number from a range.
 * 2. Makes the user guess the number.
 * 3. Provides hint about how close the user is.
 * 4. When correct guess, then show celebration.
 * */

/*
 * Questions:
 * 1. How do random number generate in c? Ans - rand()
 * 2. How do i set a limit to the rand() function?
 * 3. Why do i need to seed the rand() and how?
 * Ans - because it will seed once during compile and then always return the same value, time(NULL)
 * 4. Why did scanf work with &input and not just input?
 * */

void clrscr();

void clrscr() {
  system("clear");
}

int main() {
  // clear the terminal
  clrscr();

  // seeding the rand method
  srand(time(NULL));

  int minValue = 1, maxValue = 10;

  // this function returns a random number
  int x = minValue + rand() % (maxValue - minValue + 1);

  while(true) {

    printf("\nGuess the number, Enter a number: ");

    int input = 0;
    scanf("%d", &input);

    if(input > x) {
      printf("\nSmaller");
    }
    else if(input < x) {
      printf("\nLarger");
    }else if(input == x) {
      printf("\nYou guessed correctly!!!");
      break;
    }
    int temp = getchar();
    clrscr();
  }

  printf("\nGood Bye");

  return 0;
}
