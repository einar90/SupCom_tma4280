#include "stdlib.h"
#include "stdio.h"

double gamma;
double alpha;
double x[5];
double y[5];
double Ab[5];
double a[5]    =  {2.1, 1.2, 5.2, 0.0, 2.5};
double b[10]   =  {6.3, 0.5, 1.0, 5.2, 4.5};
double A[5][5] = {{5.2, 6.2, 0.0, 1.0, 5.2},
                  {6.7, 2.4, 6.2, 3.8, 9.1},
                  {6.3, 0.5, 1.0, 5.2, 4.5},
                  {6.7, 2.4, 6.2, 3.8, 9.1},
                  {2.1, 1.2, 5.2, 0.0, 2.5}};

void CalcX()
{
  printf("x=  ");
  for (int i = 0; i < 5; ++i)
  {
    x[i] = a[i] + gamma*b[i];
    printf("%f\t", x[i]);
  }
  printf("\n");
}

void CalcAb()
{
  printf("Ab= ");
  for (int i = 0; i < 5; ++i)
  {
    Ab[i] = 0.0;
    for (int j = 0; j < 5; ++j)
    {
      Ab[i] += A[i][j] * b[j];
    }
    printf("%f\t", Ab[i]);
  }
  printf("\n");
}

void CalcY()
{
  printf("Y=  ");
  for (int i = 0; i < 5; ++i)
  {
    y[i] = a[i] + Ab[i];
    printf("%f\t", y[i]);
  }
  printf("\n");
}

void CalcAlpha()
{
  alpha = 0.0;
  for (int i = 0; i < 5; ++i)
  {
    alpha += x[i] * y[i];

  }
}

int main(int argc, char const *argv[])
{
  gamma = atof(argv[1]);
  printf("gamma = %f\n", gamma);
  CalcX();
  CalcAb();
  CalcY();
  CalcAlpha();
  printf("alpha = %f\n", alpha);
  return 0;
}