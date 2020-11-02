#!/bin/bash

touch fight.txt
> fight.txt

./a.out scenario1.json >> fight.txt
echo "" >> fight.txt
./a.out scenario2.json >> fight.txt

CHECK=$(diff fight.txt test/expected.txt)

if [ "$CHECK" == "" ]; then
	echo "No difference between the outputs."
	exit 0
else
	echo "Something is not okay! Outputs have difference."
	exit 1
fi
