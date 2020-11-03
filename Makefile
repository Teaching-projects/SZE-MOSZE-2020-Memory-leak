OBJS := Hero.o Monster.o main.o JSON.o
FILES := test/units/kakarott.json test/units/kekarott.json test/units/kikarott.json
FLAGS := -std=c++17 -Wall -Wextra -c

run-test: $(OBJS)
	g++ -std=c++17 -Wall -Wextra -o run-test $(OBJS)

Hero.o: Hero.cpp Hero.h JSON.h Monster.h
	g++ $(FLAGS) Hero.cpp

main.o: main.cpp Hero.h JSON.h Monster.h
	g++ $(FLAGS) main.cpp

JSON.o: JSON.cpp JSON.h 
	g++ $(FLAGS) JSON.cpp

clean:
	rm -rf *.o run-test ./DOCS

doc:
	doxygen doxconf

cppcheck:
	cppcheck *.cpp --enable=warning --error-exitcode=1
	cppcheck *.cpp --enable=warning,style,performance --output-file=test/styleperform.txt

memoryleak-check:
	valgrind --leak-check=full --error-exitcode=1 ./run-test scenario1.json

fight:
	touch fight.txt
	> fight.txt

	./run-test scenario1.json >> fight.txt
	echo "" >> fight.txt
	./run-test scenario2.json >> fight.txt

fight-diff: fight
	diff fight.txt test/expected.txt

programTest:
	cd /usr/src/gtest && sudo cmake CMakeLists.txt && sudo make
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest.a
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a
	cd test && cmake CMakeLists.txt && make && ./runTests
