#!/bin/bash

#SBATCH -t 00:30:00
##SBATCH --nodes=1
##SBATCH --ntasks=8
##SBATCH --ntasks-per-node=8
#SBATCH --partition=caslake
#SBATCH --job-name=MyJob
#SBATCH --output=MyJob-%j.out
#SBATCH --error=MyJob-%j.err
#SBATCH --account=rcc-staff

ulimit -l unlimited
OMP_NUM_THREADS=8
export OMP_NUM_THREADS
./hello
