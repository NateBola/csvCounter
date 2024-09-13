objects = main.o
headers = timefunctions.h
# Production must be set to 1 for first time running on linux systems
# Or a segmentation fault will occour
Production = 0

all: csvCounter clean directory

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

.PHONY: directory
directory:
ifeq ($(Production), 0)
	@echo "Not Creating Directory"
else
	@echo "Creating Directory"
	@mkdir /home/ubuntu/log
endif

clean:
	@echo "Removing all object files"
	@rm *.o

