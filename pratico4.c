#include <stdio.h>
#include <stdlib.h>

void quickSort ( int *nums, int esq, int dir) {
      if ( esq >= dir ) {
            return;
      }
      int pivot = nums[ ( esq + dir ) / 2 ];
      int i = esq;
      int j = dir;

      while ( i <= j ) {
            while ( nums[i] < pivot ) {
                  i++;
            }
            while ( nums[j] > pivot ) {
                  j--;
            }
      if ( i <= j ) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
      }
      }
    quickSort ( nums, esq, j );
    quickSort ( nums, i, dir );
}

int* maxSubsequence ( int *nums, int numsSize, int k, int *returnSize ) {
      int i, checkSoma = 0, maxIdx = 0;
      int* subseq = ( int* ) malloc ( k * sizeof ( int ) );

      for ( i = 0; i < k; i++ ) {
            checkSoma += nums[i];
      }

      *returnSize = checkSoma;

      for ( i = 1; i <= numsSize - k; i++ ) {
            checkSoma = checkSoma - nums[i-1] + nums[i+k-1];
            if (checkSoma > *returnSize) {
                  *returnSize = checkSoma;
                  maxIdx = i;
            }
      }

      for ( i = 0; i < k; i++ ) {
            subseq[i] = nums[maxIdx + i];
      }
      return subseq;
}

int main() {
      int k, numsSize;

      printf ( "Digite o tamanho do vetor (entre 1 e 1000): " );
      scanf ( "%d", &numsSize );
      int *nums = ( int* ) malloc ( numsSize * sizeof ( int ) );
      printf ( "Digite %d valores para o vetor:\n", numsSize );

      for ( int i = 0; i < numsSize; i++ ) {
            scanf ( "%d", &nums[i] );
            if ( ( nums[i] <= -105 ) || ( nums[i] >= 105 ) ){
                  printf ( "Um dos valores é inválido, reinicie o programa e tente novamente." );
                  exit ( EXIT_FAILURE );
            }
      }
    printf ( "Defina o valor de k: " );
    scanf ( "%d", &k );
    quickSort ( nums, 0, numsSize - 1 );
    int returnSize;
    int* subseq = maxSubsequence ( nums, numsSize, k, &returnSize );
    printf ( "[ " );
    for ( int i = 0; i < k; i++ ) {
        printf ( "%d ", subseq[i] );
    }
    printf("]\n");
    free ( subseq );
    free ( nums );
    return 0;
}