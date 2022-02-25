#include <stdio.h>
/*
 *  Scale forces, update velocities and compute K.E.
 */
  double
  mkekin(int npart, double f[], double vh[], double hsq2, double hsq){
    int i;
    double ekin; 
    extern double sum;
    sum=0.0;
  
#pragma omp for private(i) reduction(+:sum) schedule(runtime) 
    for (i=0; i<3*npart; i++) {
      f[i]*=hsq2;
      vh[i]+=f[i];
      sum+=vh[i]*vh[i];
    }
    ekin=sum/hsq;

    return(ekin);
  }
