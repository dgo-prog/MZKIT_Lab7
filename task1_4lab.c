#include <stdio.h>

int main() {
  int n, i;
  double x, y, term = 1.0, S = 1.0;

  printf("Enter number of members\n");
  scanf("%d", &n);
  printf("Enter value of x\n");
  scanf("%lf", &x);

  for (i = 1; i <= n; i++) {
    term *= x * x / i;
    y = (2 * i + 1) * term;
    S += y;

    printf("%d) y=%.8f  S=%.8f\n", i, y, S);
  }

  printf("This is the sum of %d members S=%.8f\n", n, S);
}
// Видалений рядок "return 0;"
