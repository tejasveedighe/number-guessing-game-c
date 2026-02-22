#include "clear_screen.h" // for clear_screen()

#include "rng.h" // for get_random_value
#include <stdio.h>

int ask_to_continue_game() {
  puts("Do you want to play again? (y/n)");
  char input[5];
  scanf("%s", input);
  int yesFlag = 0;
  for (int i = 0; i < 5; i++) {
    if (input[i] == 'y') {
      yesFlag = 1;
      break;
    }
  }
  return yesFlag;
}

void congratulate_user() {
  puts("\n\n Congratulations User you have won!\n\nThanks for playing\n");
}

int take_user_input_for_game(int min, int max) {
  int input = 0;
getInput:
  printf("Input: ");
  scanf("%d", &input);

  if (input < min || input > max) {
    printf("Invalid input, enter a value between %d and %d\n", min, max);
    goto getInput;
  }

  return input;
}

int take_max_input() {
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

void show_welcome_message() {
#if (defined(_WIN32) || defined(_WIN64))
  puts("Windows OS detected!");
#elif defined(LINUX) || defined(__linux__)
  puts("Linux OS detected!");
#endif

  puts("Welcome to the number guessing game user.");
  puts("Press any key to continue.");

  getchar();
  clear_screen();
}

int main() {
  show_welcome_message();
  int gameOverClose = 0, input = 0, currDiff = 0, prevDiff = 0, min, max,
      random_value, get_max_from_user = 1;
  while (gameOverClose == 0) {
    // only run when the game is not running.
    if (get_max_from_user == 1) {
      min = 0, max = take_max_input();
      random_value = get_random_integer(min, max);

      printf(
          "The game is ready to play.\nNow try to enter a number that is "
          "between 0 and %d.\n\nEach time you enter a value the game will hint "
          "you with 'Warmer' or 'Colder' messages.\nWarmer - Getting "
          "closer.\nColder - Getting far.\n",
          max);

      get_max_from_user = 0;
    }

    input = take_user_input_for_game(min, max);
    currDiff = input - random_value;

    // CASE: GAME WIN
    if (currDiff == 0) {
      congratulate_user();
      int flag = ask_to_continue_game();
      if (flag == 1) {
        get_max_from_user = 1;
        continue;
      } else {
        gameOverClose = 1;
        break;
      }
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
