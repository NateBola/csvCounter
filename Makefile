objects = timefunctions.o main.o
headers = timefunctions.h

all: csvCounter clean

.PHONY: install
install:
	cp csvCounter.exe $(DESTDIR)

csvCounter: $(objects)
	@echo "Creating main executable"
	@gcc -o csvCounter.exe $(objects)

main.o: main.c $(headers)
	@echo "Creating the csvCount object file"
	@gcc -c main.c -I.

timefunctions.o: timefunctions.c timefunctions.h
	@echo "Creating the timefunctions object file"
	@gcc -c timefunctions.c -I.

clean:
	@echo "Removing all object files"
	@rm *.o

