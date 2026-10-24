main: main.o classes.o
	g++ -std=c++11 main.o classes.o -o main

classes.o: classes.cpp
	g++ -std=c++11 -c classes.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm main.o classes.o main
