#ifndef COMMON_H_
#define COMMON_H_

#include "openmpi-x86_64/mpi.h"
extern MPI_Comm WorldComm;
extern MPI_Comm SelfComm;


//! \brief A structure describing a vector
typedef struct {
  double* data;   //!< The vector data
  int len;        //!< The local length of the vector
  int glob_len;   //!< The global length of the vector
  int stride;     //!< The distance in memory between vector elements
  MPI_Comm* comm; //!< The MPI communicator the vector is split across
  int comm_size;  //!< The size of the MPI communicator the vector is split across
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


//! \brief Create a parallel vector
//! \param globLen The global vector length
//! \param comm The communicator to split the vector across
//! \param allocdata If 0, no data is allocated to vector
//! \return The new vector
Vector createVectorMPI(int globLen, MPI_Comm* comm, int allocdata);


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


//! \brief Create a parallel matrix (Fortran format)
//! \param n1 The local number of rows. -1 to split
//! \param n2 The local number of columns. -1 to split
//! \param N1 The global number of rows
//! \param N2 The global number of columns
//! \param comm The communicator to split the vector across
//! \return The new matrix
Matrix createMatrixMPI(int n1, int n2, int N1, int N2, MPI_Comm* comm);


//! \brief Free up memory allocated to a matrix
//! \param A The matrix to free
void freeMatrix(Matrix A);
