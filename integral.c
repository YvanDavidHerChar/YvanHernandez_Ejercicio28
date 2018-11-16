#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "mpi.h"

/*generar un numero aleatorio de 10 dimensiones*/
void aleatorio(double* punto, int dimension)
{
for( int i=0; i<dimension; i++)
 {
  punto[i]=(double)rand() / (double)RAND_MAX ;
 }
}
/*funcion a trabajar*/
double fun(double* punto, int dimension)
{
double resultado=0;
for( int i=0; i<dimension; i++)
{
resultado = punto[i]+resultado;
}
return resultado*resultado;
}
/* Basandonos en el codigo encontrado en http://csg.sph.umich.edu/abecasis/class/2006/615.22.pdf */

double Integrate( int dim, double N )
{
double * point = (double *)malloc(dim*sizeof(double));
double sum = 0.0;
double sumsq = 0.0;
for (int i=0; i <N; i++)
{
 aleatorio(point, dim);
 double fx=fun(point, dim);
 sum += fx;
 sumsq += fx* fx;
}
return sum/N;
}


int main(int argc, char **argv)
{
int N;
int elproceso;
int totalProcesos;
int dim = 10;
double integral;
double my_result =0;

MPI_Init (&argc, &argv);
MPI_Comm_size (MPI_COMM_WORLD, &totalProcesos);
MPI_Comm_rank (MPI_COMM_WORLD, &elproceso);
N = (int)((double)N/(double)totalProcesos);
/*double *results = elproceso == 0 ? malloc( totalProcesos * sizeof( double ) ) : NULL;*/
integral = Integrate(dim,N);
printf("ayombe: %f\n", integral);
/*MPI_Gather( &my_result, 1, MPI_INT, results, 1, MPI_INT, 0, MPI_COMM_WORLD );

for (int i=0; i<totalProcesos;i++)
{
my_result = results[i]+my_result;
}
my_result = my_result/totalProcesos;
printf("TOTAL: %f\n", my_result);
free(results);*/
MPI_Finalize();
return 0;
}

