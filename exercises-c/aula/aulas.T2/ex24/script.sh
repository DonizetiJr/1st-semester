#!/bin/bash

for i in `seq 3 25`
do
	echo -n "$i "
	TIME=`./tsp2 $i 1> /dev/null`
	echo $TIME
done
