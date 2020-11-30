OBJS := Hero.o Monster.o main.o JSON.o Map.o Game.o
FLAGS := -std=c++17 -Wall -Wextra -c

run-test: $(OBJS)
	g++ -fPIC -std=c++17 -Wall -Wextra -o run-test $(OBJS)

Hero.o: Hero.cpp Hero.h JSON.h Monster.h
	g++ $(FLAGS) Hero.cpp

main.o: main.cpp Hero.h JSON.h Monster.h Map.h Game.h
	clang++ -fPIC $(FLAGS) main.cpp

JSON.o: JSON.cpp JSON.h 
	g++ $(FLAGS) JSON.cpp

Monster.o: Monster.cpp Monster.h JSON.h
	g++ $(FLAGS) Monster.cpp

Map.o: Map.cpp Map.h
	g++ $(FLAGS) Map.cpp

Game.o: Game.cpp Game.h Map.h Hero.h Monster.h
	g++ $(FLAGS) Game.cpp

clean:
	rm -rf *.o run-test ./DOCS fight_sc1.txt fight_sc2.txt a.out 

doc:
	doxygen doxconf

cppcheck:
	cppcheck *.cpp --enable=warning --error-exitcode=1
	cppcheck *.cpp --enable=warning,style,performance --output-file=test/styleperform.txt

memoryleak-check:
	valgrind --leak-check=full --error-exitcode=1 cat test/input_sc1.txt | ./run-test scenario1.json

fight:
	touch fight_sc1.txt
	> fight_sc1.txt
	
	touch fight_sc2.txt
	> fight_sc2.txt

	cat test/input_sc1.txt | ./run-test scenario1.json | tail -1 >> fight_sc1.txt
	cat test/input_sc2.txt | ./run-test scenario2.json | tail -1 >> fight_sc2.txt

fight-diff: fight
	diff fight_sc1.txt test/expected_sc1.txt
	diff fight_sc2.txt test/expected_sc2.txt

programTest:
	cd /usr/src/gtest && cmake CMakeLists.txt && make
	ln -st /usr/lib/ /usr/src/gtest/libgtest.a
	ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a
	cd test && cmake CMakeLists.txt && make && ./runTests
