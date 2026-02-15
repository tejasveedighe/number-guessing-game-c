#include "clear_screen.h" // for clear_screen()

#include "rng.h" // for get_random_value
#include <stdio.h>

void congratulateUser() {
  printf("\n\n Congratulations User you have won!\n\nThanks for playing\n");
}

int take_user_input_for_game(int min, int max) {
  int input = 0;
getInput:
  scanf("%d", &input);

  if (input < min || input > max) {
    printf("Invalid input, enter a value between %d and %d\n", min, max);
    goto getInput;
  }

  return input;
}

int take_user_input() {
  int max = 0;
getvalue:
  printf("Enter a max value for the number: ");
  scanf("%d", &max);

  // validate the input
  if (max <= 2) {
    printf("Incorrect value for max, Please enter a value greater than 2\n");
    goto getvalue;
  }

  return max;
}

int main() {

#if (defined(_WIN32) || defined(_WIN64))
  puts("Windows");
#elif defined(LINUX) || defined(__linux__)
  puts("Linux");
#endif

  puts("Welcome to the number guessing game user.");
  puts("Press any key to continue.");

  getchar();
  clear_screen();

  int min = 0, max = take_user_input();
  int random_value = get_random_integer(min, max);

  printf("The game is ready to play.\nNow try to enter a number that is "
         "between 0 and %d.\n\nEach time you enter a value the game will hint "
         "you with 'Warmer' or 'Colder' messages.\nWarmer - Getting "
         "closer.\nColder - Getting far.\n",
         max);

  int gameOverClose = 0, input = 0, currDiff = 0, prevDiff = 0;
  while (gameOverClose == 0) {

    input = take_user_input_for_game(min, max);
    currDiff = input - random_value;

    // CASE: GAME WIN
    if (currDiff == 0) {
      congratulateUser();
      gameOverClose = 1;
      break;
    }

    if (currDiff > prevDiff) {
      puts("\nColder");
      prevDiff = currDiff;
      continue;
    }

    if (currDiff < prevDiff) {
      puts("\nWarmer");
      prevDiff = currDiff;
      continue;
    }
  }

  return 0;
}
