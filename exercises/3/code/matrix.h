#ifndef COMMON_H_
#define COMMON_H_

#include "openmpi-x86_64/mpi.h"
extern MPI_Comm WorldComm;
extern MPI_Comm SelfComm;


//! \brief A structure describing a vector
typedef struct {
  double* data;   //!< The vector data
  int len;        //!< The local length of the vector
  int stride;     //!< The distance in memory between vector elements
  int* displ;     //!< Displacements for parallell vectors
  int* sizes;     //!< The size of each process for parallell vectors
} vector_t;


//! \brief Convenience typedef
typedef vector_t* Vector;


//! \brief A structure describing a vector
typedef struct {
  double** data;  //!< The matrix data
  Vector as_vec;  //!< The matrix viewed as one long vector
  Vector* col;    //!< The columns of the matrix as vectors
  Vector* row;    //!< The rows of the matrix as vectors
  int rows;       //!< Local number of rows in matrix
  int cols;       //!< Local number of columns in matrix
  int glob_rows;  //!< Global number of rows in matrix
  int glob_cols;  //!< Global number of columns in matrix
} matrix_t;


//! \brief Convenience typedef
typedef matrix_t* Matrix;


//! \brief Create a vector
//! \param len the length of the vector
//! \return The new vector
Vector createVector(int len);


//! \brief Free up memory allocated to a vector
//! \param vec The vector to free
void freeVector(Vector vec);


//! \brief Calculate a parallel splitting of a vector
//! \param globLen The global length of the vector
//! \param size The number of processes to divide vector across
//! \param[out] len The length on each of the processes
//! \param[out] The displacement for each of the processes
void splitVector(int globLen, int size, int** len, int** displ);


//! \brief Create a matrix (Fortran format)
//! \param n1 The number of rows
//! \param n2 The number of columns
//! \return The new matrix
Matrix createMatrix(int n1, int n2);


//! \brief Free up memory allocated to a matrix
//! \param A The matrix to free
void freeMatrix(Matrix A);
