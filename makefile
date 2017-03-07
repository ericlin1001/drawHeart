all:compile save

compile:main.cpp
	g++ -o main main.cpp


save:main
	./main 


.PHONY: clean
clean:
	rm main
