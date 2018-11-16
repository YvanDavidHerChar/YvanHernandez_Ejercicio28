listing.x: listing.c
	mpicc listing.c -o listing.x
	mpirun -np 8 ./listing.x

Integral.x: integral.c
	mpicc integral.c -o -lm Integral.x
	mpirun -np 4 ./Integral.x 2000


clean: 
	rm -f *.x 
