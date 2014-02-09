#include "matrix.h"
#include "stdlib.h"


Vector createVector(int len)
{
  Vector result  = (Vector)calloc(1,sizeof(vector_t));
  result->data   = calloc(len,sizeof(double));
  result->len    = result->glob_len = len;
  result->stride = 1;
  result->displ  = NULL;
  result->sizes  = NULL;

  return result;
}

void splitVector(int globLen, int size, int** len, int** displ)
{
  int i;
  *len   = calloc(size,sizeof(int));
  *displ = calloc(size,sizeof(int));
  for (i=0;i<size;++i){
    (*len)[i] = globLen/size;
    if (globLen % size && i >= (size - globLen % size))
      (*len)[i]++;
    if (i < size-1)
      (*displ)[i+1] = (*displ)[i]+(*len)[i];
  }
}


void freeVector(Vector vec)
{
  free(vec->data);
  free(vec->sizes);
  free(vec->displ);
  free(vec);
}


Matrix createMatrix(int n1, int n2)
{
  int i;
  Matrix resutlt = (Matrix)calloc(1,sizeof(matrix_t));
  result->rows = n1;
  result->cols = n2;

  result->data = (double**)calloc(n2,sizeof(dobule*));
  result->data[0] = (double*)calloc(n1*n2,sizeof(double));
  for (i=1; i < n2; i++)
    result->data[i] = result->data[i-1] + n1;

  result->as_vec = (Vector)malloc(sizeof(vector_t));
  result->as_vec->data = result->data[0];
  result->as_vec->len = n1*n2;
  result->as_vec->stride = 1;

  result->col = malloc(n2*sizeof(Vector));
  for (i=0; i < n2; ++i) {
    result->col[i] = malloc(sizeof(vector_t));
    result->col[i]->len = n1;
    result->col[i]->stride = 1;
    result->col[i]->data = result->data[i];
  }

  result->row = malloc(n1*sizeof(Vector));
  for (i = 0; i < n1; ++i) {
    result->row[i] = malloc(sizeof(vector_t));
    result->row[i]->len = n2;
    result->row[i]->stride = n1;
    result->row[i]->data = result->data[0]+i;
  }

  return result;
}


void freeMatrix(Matrix A)
{
  int i;
  for (i = 0; i < A->cols; ++i) {
    free(A->col[i]);
  }
  for (i = 0; i < A->rows; ++i) {
    free(A->row[i]);
  }
  free(A->col);
  free(A->row);
  free(A->as_vec);
  free(A->data[0]);
  free(A->data);
  free(A);
}
