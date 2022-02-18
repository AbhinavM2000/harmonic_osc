#include<stdio.h>

#include<math.h>

#include<stdlib.h>

#define a 10
void main() {
  FILE * f = fopen("file.txt", "w");
  float c, gamma, m, w0, w1, k, t, bb;
  c = 0;
  gamma = 0;
  m = 0;
  w1 = 0;
  k = 0;
  t = 0;
  bb = 0;

  printf("\nEnter the mass: ");
  scanf("%f", & m);

  printf("\nEnter the spring constant: ");
  scanf("%f", & k);

  printf("\nEnter the damping coefficient: ");
  scanf("%f", & gamma);

  c = gamma * 2 * m;

  w0 = sqrt(k / m);

  printf("\nw0= %f ", w0);

  if ((c * c - 4 * m * k) > 0)
    printf("\noverdamped\n");

  if ((c * c - 4 * m * k) == 0) {
    printf("\ncritically damped\n");
    printf("\n");
  }

  if ((c * c - 4 * m * k) < 0) {
    printf("\nunderdamped\n");

    w1 = sqrt(w0 * w0 - gamma * gamma);
    printf("w1=%f", w1);
    while (t < 10) {

      bb = pow(2.71828, -1 * gamma * t) * a * cos(w1 * t);

      fprintf(f, "%f %f\n", t, bb);

      t += 0.01;

    }
  }
  fclose(f);

}
