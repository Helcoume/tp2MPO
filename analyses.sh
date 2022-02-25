#!/bin/bash

if [ $# -lt 4 ] 
then
	echo "error: $# args given but expecting 4"
        echo "usage: ./bench.sh START LAST STEP NTEST"
	echo " - START : minimum number of threads to test"
 	echo " - LAST  : maximum number of threads to test"
	echo " - STEP  : increment over iteration from START to LAST"	
	echo " - NTEST : number of execution to lunch on each test"
	exit 1
fi

echo -n "Threads    "
b="-----------"
for ((i = 1 ; i <= $4; i++))
do
	a+=("Iter n°$i    ")
	b+="-------------"
done
echo "${a[*]}"
echo "$b"

for ((i = $1; i <= $2; i+=$3))
do

	export OMP_NUM_THREADS=$i

	a=()
	echo -n "   $i       "
	for ((j = 1; j <= $4; j++)) 
	do
		t=$(./md | tail -n 1 | sed -e 's/^.*=  //')
		a+=("$t    ")
	done
	echo "${a[*]}"

done
	


