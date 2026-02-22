#include <stdio.h>

// #define dev

void clear_screen() {
  // clear the entire display
  puts("\033[2J");

  // set the cursor back to the first position of the window
  puts("\033[1;1H");
}

#ifdef dev
int main() {
  clear_screen();
  return 0;
}
#endif /* ifdef dev */
