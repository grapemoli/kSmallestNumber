k: main.o node.o tree.o
	g++ -g node.o tree.o main.o -o k

main.o: main.cpp
	g++ -c -g main.cpp

node.o: node.cpp
	g++ -c -g node.cpp

tree.o: tree.cpp node.cpp
	g++ -c -g tree.cpp

run: k
	./k

clean:
	rm k
	rm *.o

debug: k
	gdb k

valgrind:
	valgrind --leak-check=full ./k
