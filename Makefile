OBJS := Hero.o main.o jsonParser.o

run-test: $(OBJS)
	g++ -Wall -o run-test $(OBJS)

Hero.o: Hero.cpp
	g++ -Wall -c Hero.cpp

main.o: main.cpp
	g++ -Wall -c main.cpp

jsonParser.o: jsonParser.cpp
	g++ -Wall -c jsonParser.cpp

clean:
	rm -rf *.o run-test ./DOCS

doc:
	doxygen doxconf

cppcheck:
	cppcheck *.cpp --enable=warning --error-exitcode=1
	cppcheck *.cpp --enable=warning,style,performance --output-file=test/styleperform.txt

memoryleak:
	valgrind --leak-check=full --error-exitcode=1 ./run-test test/units/kakarott.json test/units/kikarott.json

fight:
	touch result.txt
	> result.txt
	./run-test test/units/kakarott.json test/units/kikarott.json >> result.txt
	./run-test test/units/kakarott.json test/units/kekarott.json >> result.txt
	./run-test test/units/kikarott.json test/units/kekarott.json >> result.txt
	./run-test test/units/kikarott.json test/units/kakarott.json >> result.txt
	./run-test test/units/kekarott.json test/units/kakarott.json >> result.txt
	./run-test test/units/kekarott.json test/units/kikarott.json >> result.txt

parserTest:
	cd /usr/src/gtest && sudo cmake CMakeLists.txt && sudo make
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest.a
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a
	cd test && cmake CMakeLists.txt && make && ./runTests
