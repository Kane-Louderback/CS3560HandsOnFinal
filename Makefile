all:	build	archive	doc

build:	count

doc: 
	doxygen

cppcheck: 
	cppcheck
	
count:	count.o

count.o:	count.cc
	g++	-c	count.cc

archive:	count.cc
	tar	cvzf	cs3650Final.tar.gz	count.cc	Makefile

clean: 
	-rm	*.o	*.tar