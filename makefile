listing.x: listing.c
	mpicc listing.c -o listing.x
	mpirun -np 8 ./listing.x

clean: 
	rm -f *.x 
