//Krystal Raynes
//
#include <stdio.h>
#include <stdlib.h>

float fdot( int length, float *X, float *Y)
{
    float result;
    for (int i = 0; i < length; i++)
    {
        result = X[i] * Y[i];
    }
    return result;
}

//  The benchmark
int main( void ) {
  const int N = 200000000; // The benchmark runs on a fixed size of work
  
  printf( "Running FDOT operation of size %d x 1\n", N );
  float *X = (float *) malloc( N * sizeof(float) );      // First vector
  float *Y = (float *) malloc( N * sizeof(float) );      // Second vector
  

   // Carry out the operation
   fdot( N, X, Y );

   // Free up the memory
   free( X );
   free( Y );
   //free( Result );

   return 0;
}
