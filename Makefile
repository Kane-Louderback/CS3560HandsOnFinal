all: build 

build: count

count: 
	g++ -g count.cc
clean: 
	rm *.o