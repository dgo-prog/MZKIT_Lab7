#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Кількість елементів масиву
#define SIZE 10

int main() {
  srand(time(NULL));

  int min = 1;
  int max = 10;
  float Q;
  int counter = 0;
  // Число, для виведення середнього арифметичного чисел, значення яких буде
  // меньше за це число
  float A;
  float average = 0;
  float sum = 0.0f;

  // Виділяємо пам'ять під массив
  float *ptrarr = (float *)malloc(SIZE * sizeof(float));

  if (ptrarr == NULL) {
    printf("Memory allocation error!\n");
    return 1;
  }

  printf("Enter the value of a: ");
  scanf("%f", &A);

  for (int i = 0; i < SIZE; i++) {
    int scalled_min = min * 100;
    int scalled_max = max * 100;
    ptrarr[i] =
        (rand() % (scalled_max - scalled_min + 1) + scalled_min) / 100.0f;
  }

  for (int i = 0; i < SIZE; i++) {
    printf("%.2f ", ptrarr[i]);
  }

  printf("\n\narray address - %p\n\n", ptrarr);

  for (int i = 0; i < SIZE; i++) {
    printf("ptrarr[%d] = %3.2f, %p\n", i, ptrarr[i], &ptrarr[i]);
  }

  for (int i = 0; i < SIZE; i++) {
    Q = ptrarr[i];

    if (Q < A) {
      sum += ptrarr[i];
      counter++;
    }
  }

  printf("\nsum = %f\n\n", sum);

  if (counter > 0) {
    average = sum / counter;
  } else {
    printf("There are no elements here that are greater then A.\n");
  }

  printf("Average = %f", average);

  free(ptrarr);

  return 0;
}
