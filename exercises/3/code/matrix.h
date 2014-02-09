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
