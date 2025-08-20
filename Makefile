all:
	g++ -Iinclude ./src/main.cpp ./src/SinglyLinkedList.cpp -o ./build/minitext
	./build/minitext

clean:
	rm ./build/*

debug:
	g++ -Iinclude ./src/main.cpp ./src/SinglyLinkedList.cpp -g -o ./build/minitext_debug
	./build/minitext_debug

valgrind:
	g++ -Iinclude ./src/main.cpp ./src/SinglyLinkedList.cpp -g -o ./build/minitext_debug
	valgrind ./build/minitext_debug
