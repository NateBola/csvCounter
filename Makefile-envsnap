all: env
	
.PHONY: install
install:
	cp env $(DESTDIR) 

env: env.o
	gcc -o env env.o

env.o: env.c
	gcc -c env.c 
