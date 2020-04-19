#include <omp.h>
#include <stdio.h>
#define N 1000000000

int main(void) {
	double pi = 0.0f; long i;
	double ti, tf;
	int qt;
	int total = omp_get_max_threads();

	for( int p = 1; p <= total; p++ ) {
		for( int run = 1; run <= 4; run++ ) {
		ti = omp_get_wtime();
		omp_set_num_threads(p);
		#pragma omp parallel reduction(+: pi)
		{
			qt = omp_get_num_threads();
			#pragma omp for
			for (i=0; i<N; i++){
				double t=(double) ((i+0.5)/N);
				pi += 4.0/(1.0+t*t);
			}
		}
		tf = omp_get_wtime();
		printf("pi=%f\ntempo: %fs\nthreads: %d\n",pi/N, tf-ti, qt);
		pi = 0.0f;
		}
	}

	return 0;
}

