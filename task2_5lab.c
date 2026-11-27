#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
  srand(time(NULL));

  int arr[SIZE][SIZE];
  int sumOfElOfPerimetr = 0;
  int temp;
  double average;
  int minVal, maxVal;

  printf("Enter range min and max: ");
  if (scanf("%d %d", &minVal, &maxVal) != 2 || minVal > maxVal) {
    printf("Invalid range. Using [-20; 20].\n");
    minVal = -20;
    maxVal = 20;
  }

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      arr[i][j] = rand() % (maxVal - minVal + 1) + minVal;
    }
  }

  printf("\nInitial matrix:\n");
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%5d", arr[i][j]);
    }
    printf("\n");
  }

  // Додаємо рядки повністю
  for (int j = 0; j < SIZE; j++) {
    sumOfElOfPerimetr += arr[0][j];
    sumOfElOfPerimetr += arr[SIZE - 1][j];
  }

  // Додаємо стовпці без кутів, щоб кути не додавались двічі
  for (int i = 1; i < SIZE - 1; i++) {
    sumOfElOfPerimetr += arr[i][0];
    sumOfElOfPerimetr += arr[i][SIZE - 1];
  }

  average = (double)sumOfElOfPerimetr / (4 * SIZE - 4);

  // Обмін місцями головної та побічної діагоналей
  for (int i = 0; i < SIZE; i++) {
    temp = arr[i][i];
    arr[i][i] = arr[i][SIZE - 1 - i];
    arr[i][SIZE - 1 - i] = temp;
  }

  printf("\nMatrix after swapping diagonals:\n");
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%5d", arr[i][j]);
    }
    printf("\n");
  }

  printf("\nAverage of perimeter elements: %.2f\n", average);

  return 0;
}
