CFLAGS = #-Wall -Wextra
COPTIONS = -lm

all: Exercise_5-10

test: test.o
	@echo "Linking and producing the test application"
	gcc $(CFLAGS) test.o -o test $(COPTIONS)

test.o: test.c
	@echo "Compilings test file"
	gcc $(CFLAGS) -c test.c $(COPTIONS)

Exercise_5-10: Exercise_5-10.o
	@echo "Linking and producing the Exercise_5-10 application"
	gcc $(CFLAGS) Exercise_5-10.o -o Exercise_5-10 $(COPTIONS)

Exercise_5-10.o: Exercise_5-10.c
	@echo "Compilings Exercise_5-10 file"
	gcc $(CFLAGS) -c Exercise_5-10.c $(COPTIONS)

clean: 
	@echo "Removing everthing but the source files"
	rm Exercise_5-10.o Exercise_5-10 test.o test