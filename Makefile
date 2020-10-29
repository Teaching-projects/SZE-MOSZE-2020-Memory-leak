OBJS := Hero.o main.o jsonParser.o
FILES := test/units/kakarott.json test/units/kekarott.json test/units/kikarott.json

run-test: $(OBJS)
	g++ -Wall -o run-test $(OBJS)

Hero.o: Hero.cpp Hero.h
	g++ -Wall -c Hero.cpp

main.o: main.cpp
	g++ -Wall -c main.cpp

jsonParser.o: jsonParser.cpp jsonParser.h
	g++ -Wall -c jsonParser.cpp

clean:
	rm -rf *.o run-test ./DOCS

doc:
	doxygen doxconf

cppcheck:
	cppcheck *.cpp --enable=warning --error-exitcode=1
	cppcheck *.cpp --enable=warning,style,performance --output-file=test/styleperform.txt

memoryleak-check:
	valgrind --leak-check=full --error-exitcode=1 ./run-test test/units/kakarott.json test/units/kikarott.json

fight:
	touch test/result.txt
	> test/result.txt

	for f1 in $(FILES); do \
		for f2 in $(FILES); do \
			if [ $$f1 != $$f2 ]; then \
				./run-test $$f1 $$f2 >> test/result.txt; \
			fi; \
		done; \
	done

fight-diff: fight
	diff test/result.txt test/expected.txt

parserTest:
	cd /usr/src/gtest && sudo cmake CMakeLists.txt && sudo make
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest.a
	sudo ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a
	cd test && cmake CMakeLists.txt && make && ./runTests
