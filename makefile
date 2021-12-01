output: main.o tree.o
	g++ main.cpp tree.cpp -o output

tree.o: tree.cpp tree.hpp
	g++ -c tree.cpp

main.o: main.cpp
	g++ -c main.cpp

run:
	./output

remove:
	rm *.o

clean:
	rm *.o output