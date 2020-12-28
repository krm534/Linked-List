output: main.o linked-list.o test.o
	g++ main.o linked-list.o test.o -o output

main.o: ./Main/main.cpp
	g++ -c ./Main/main.cpp

linked-list.o: ./Linked-List/linked-list.cpp ./Linked-List/linked-list.h ./Main/Header.h
	g++ -c ./Linked-List/linked-list.cpp

test.o: ./Tests/test.cpp ./Tests/test.h ./Linked-List/linked-list.h ./Main/Header.h 
	g++ -c ./Tests/test.cpp

clean:
	rm *.o output
