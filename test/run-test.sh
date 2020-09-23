#!/bin/bash

touch result.txt
> result.txt

cd ..

./a.out test/units/kakarott.json test/units/kikarott.json >> test/result.txt
./a.out test/units/kakarott.json test/units/kekarott.json >> test/result.txt
./a.out test/units/kikarott.json test/units/kekarott.json >> test/result.txt
./a.out test/units/kikarott.json test/units/kakarott.json >> test/result.txt
./a.out test/units/kekarott.json test/units/kakarott.json >> test/result.txt
./a.out test/units/kekarott.json test/units/kikarott.json >> test/result.txt

CHECK=$(diff test/result.txt test/expected.txt)

if ["$CHECK" == ""]; then
	echo "No difference between the outputs."
	exit 0
else
	echo "Something is not okay! Outputs have difference."
	exit 1
fi
