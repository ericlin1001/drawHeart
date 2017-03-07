all:compile save

compile:main.cpp
	g++ -o main main.cpp

run:main
	cat input.txt|./main

save:main
	./main 
