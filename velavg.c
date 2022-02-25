#include <math.h>

/*
 *  Compute average velocity
 */
  double
  velavg(int npart, double vh[], double vaver, double h){
    int i;
    double vaverh=vaver*h;
    double vel=0.0;
    double sq;
    extern double count, tmp_vel;

    tmp_vel=0.0;
    count=0.0;
#pragma omp for private(i) reduction(+:tmp_vel) reduction(+:count)
    for (i=0; i<npart*3; i+=3){
      sq=sqrt(vh[i]*vh[i]+vh[i+1]*vh[i+1]+vh[i+2]*vh[i+2]);
      if (sq>vaverh) count++;
      tmp_vel+=sq;
    }
    vel=tmp_vel/h;
    return(vel);
  }
