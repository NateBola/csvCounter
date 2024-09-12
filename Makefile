objects = timefunctions.o main.o
headers = timefunctions.h
# Set Production to 1 to create a directory on linux systems
# When testing on windows set to zero, the log will place in the same
# 	directory as the code
Production = 0

all: csvCounter clean directory

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

.PHONY: directory
directory:
	ifeq ($(Production),0)
		@echo "Not Creating Directory"
	else
		@echo "Creating Directory"
		#@mkdir /home/ubuntu/log

clean:
	@echo "Removing all object files"
	@rm *.o

