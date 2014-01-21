#include "stdio.h"
#include "stdlib.h"

double y[3];
double x[3] = {1.0, 1.0, 1.0};
double A[][3] = { {0.3, 0.4, 0.3},
                  {0.7, 0.1, 0.2},
                  {0.5, 0.5, 0.0}};

void MultiplyMatrices(double A[][3], double x[3], double y[3])
{
  int i,j; // Loop counters
  for (int i = 0; i < 3; ++i)
  {
    y[i] = 0.0; // Initializing to 0.0
    for (int j = 0; j < 3; ++j)
    {
      y[i] += x[j] * A[i][j];
    }
  }
  printf("y = [ %f, %f, %f ]\n", y[0], y[1], y[2]);
}

int main(int argc, char const *argv[])
{
  MultiplyMatrices(A, x, y);
  return 0;
}