
/*
 *  Scales an array
 */
  void
  dscal(int n,double sa,double sx[], int incx){
    int i,j;

    if (incx == 1) {
      #pragma omp for private(i)
      for (i=0; i<n; i++)
        sx[i] *= sa;
    } else {
      j = 0;
      #pragma omp for private(i) 
      for (i=0; i<n; i++) {
        sx[j] *= sa;
        j += incx;
      }
    }
  }
