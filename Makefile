output: main.o linked-list.o
	g++ main.o linked-list.o -o output

main.o: main.cpp
	g++ -c main.cpp

linked-list.o: linked-list.cpp linked-list.h Header.h
	g++ -c linked-list.cpp

clean:
	rm *.o output
