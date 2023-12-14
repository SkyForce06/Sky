CC = gcc
CFLAGS = -Wall --pedantic
EXECUTABLE = bin/gauss

all: $(EXECUTABLE)

$(EXECUTABLE): src/*.c
	$(CC) $(CFLAGS) $^ -o $@

test: all
	bin/gauss dane/A dane/b
	bin/gauss dane/C dane/d  
	bin/gauss dane/E dane/f 
