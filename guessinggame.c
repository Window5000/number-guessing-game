#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void game() {
  int difficulty;
  int num = rand() % 101;

  printf("Please select a difficulty level:\n"
         "0. Infinite\n"
         "1. Easy (10 chances)\n"
         "2. Medium (5 chances)\n"
         "3. Hard (3 chances)\n"
         "\nSelect a difficulty: ");
  scanf("%d", &difficulty);

  if (difficulty < 0 || difficulty > 3)
    difficulty = 0;

  switch (difficulty) {
  case 1:
    difficulty = 10;
    break;
  case 2:
    difficulty = 5;
    break;
  case 3:
    difficulty = 3;
  }

  for (int i = 1; difficulty == 0 || i <= difficulty; i++) {
    int input;
    printf("\nSelect a number: ");
    scanf("%d", &input);
    if (input == num) {
      printf("You win! In %d tries\n\n", i);
      break;
    } else if (input > num) {
      printf("Too big! %d tries remaining\n\n", difficulty - i);
    } else {
      printf("Too small! %d tries remaining\n\n", difficulty - i);
    }
  }
}

int main(void) {
  printf("\e[1;1H\e[2J");
  srand(time(NULL));
  printf("Welcome to Guessinator 2077\n\n"
         "The computer will now pick a number between 0 and 100 (inclusive),\n"
         "your job will be to guess the correct number in order to save the\n"
         "world!\n\n");

  while (1) {
    game();
    printf("Do you want to play again? [y/n]: ");
    char again[2];
    scanf("%1s", again);
    if (strcmp(again, "n") == 0)
      break;
  }

  return EXIT_SUCCESS;
}
