#PBS -l nodes=4:ppn=1,mem=1gb,walltime=00:05:00
#PBS -M yd.hernandez10@uniandes.edu.co
#PBS -m abe
#PBS -N ejercicio28


module load mpich/3.2.1
cd /hpcfs/home/fisi4028/yd.hernandez10 # este es el directorio desde donde se ejecuto qsub

make clean
make

