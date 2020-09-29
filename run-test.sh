#!/bin/bash

touch result.txt 
> result.txt

./a.out test/units/kakarott.json test/units/kikarott.json >> result.txt
./a.out test/units/kakarott.json test/units/kekarott.json >> result.txt
./a.out test/units/kikarott.json test/units/kekarott.json >> result.txt
./a.out test/units/kikarott.json test/units/kakarott.json >> result.txt
./a.out test/units/kekarott.json test/units/kakarott.json >> result.txt
./a.out test/units/kekarott.json test/units/kikarott.json >> result.txt

CHECK=$(diff result.txt test/expected.txt)

if [ "$CHECK" == "" ]; then
	echo "No difference between the outputs."
	exit 0
else
	echo "Something is not okay! Outputs have difference."
	exit 1
fi
