OBJS := Hero.o Monster.o main.o JSON.o
FILES := test/units/kakarott.json test/units/kekarott.json test/units/kikarott.json
FLAGS := -std=c++17 -Wall -Wextra -c

run-test: $(OBJS)
	g++ -fPIC -std=c++17 -Wall -Wextra -o run-test $(OBJS)

Hero.o: Hero.cpp Hero.h JSON.h Monster.h
	g++ $(FLAGS) Hero.cpp

main.o: main.cpp Hero.h JSON.h Monster.h
	clang++ -fPIC $(FLAGS) main.cpp

JSON.o: JSON.cpp JSON.h 
	g++ $(FLAGS) JSON.cpp

Monster.o: Monster.cpp Monster.h JSON.h
	g++ $(FLAGS) Monster.cpp

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
	touch fight_sc1.txt
	> fight_sc1.txt

	touch fight_sc2.txt
	> fight_sc2.txt

	./run-test scenario1.json >> fight_sc1.txt
	./run-test scenario2.json >> fight_sc2.txt

fight-diff: fight
	diff fight_sc1.txt test/expected_sc1.txt
	diff fight_sc2.txt test/expected_sc2.txt

programTest:
	cd /usr/src/gtest && cmake CMakeLists.txt && make
	ln -st /usr/lib/ /usr/src/gtest/libgtest.a
	ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a
	cd test && cmake CMakeLists.txt && make && ./runTests
