//Krystal Raynes
//Copied dgemm function form book, pg 226 
#include <stdio.h>
#include <stdlib.h>

void dgemm( int length, double *X, double *Y, double *Result ) {
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            //double cij = Result[i+j*length];
            for (int k = 0; k < length; k++)
            {
                *(Result + i*length + j) 
                 +=*(Result + i*length + j) + *(X+ i+ k) * *(Y + k +j);
            }
            //Result[i+j*length] = cij;
        }
    }
}

//  The benchmark
int main( void ) {
  const int N = 1024; // The benchmark runs on a fixed size of work
  printf( "Running IAXPY operation of size %d x 1\n", N );
  double *X = (double *) malloc( N * N * sizeof(double) );      // First vector
  double *Y = (double *) malloc( N * N * sizeof(double) );      // Second vector
  double *Result = (double *) malloc( N * N * sizeof(double) ); // Result vector

   // Carry out the operation
   dgemm( N, X, Y, Result );

   // Free up the memory
   
   free( X );
   free( Y );
   free( Result );

   return 0;
}
