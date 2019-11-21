main: main.o build_in.o parser.o user_type.o
	g++ main.o build_in.o parser.o user_type.o -o main -lgtest -lpthread
main.o: main.cpp parser.h user_type.h
	g++ -c main.cpp -o main.o
parser.o: parser.h parser.cpp
	g++ -c parser.cpp -o parser.o
build_in.o: build_in.h build_in.cpp
	g++ -c build_in.cpp -o build_in.o
user_type.o: user_type.h user_type.cpp
	g++ -c user_type.cpp -o user_type.o
.PHONY:clean
clean:
	rm -f *.o main
