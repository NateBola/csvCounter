objects = main.o
headers = timefunctions.h
# Production must be set to 1 for first time running on linux systems
# Or a segmentation fault will occour
Production = 0

all: csvCounter

.PHONY: install
install:
	cp csvCounter.exe $(DESTDIR)

csvCounter: $(objects)
	@echo "Creating main executable"
	@gcc -o csvCounter.exe $(objects)

main.o: main.c
	@echo "Creating the csvCount object file"
	@gcc -c main.c -I.

timefunctions.o: timefunctions.c timefunctions.h
	@echo "Creating the timefunctions object file"
	@gcc -c timefunctions.c -I.

