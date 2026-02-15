#include <stdlib.h>
#include <time.h>

int get_random_integer(int min, int max) {
  srand(time(NULL));

  int x = min + rand() % (max - min + 1);
  return x;
}
