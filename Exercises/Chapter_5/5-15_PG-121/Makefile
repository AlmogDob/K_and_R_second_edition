CFLAGS = -Wall -Wextra
COPTIONS =
DUNPING = *** 

all: Exercise_5-15

Exercise_5-15: Exercise_5-15.o
	@echo "$(DUNPING)Linking and producing the Exercise_5-15 application$(DUNPING)"
	gcc $(CFLAGS) Exercise_5-15.o -o Exercise_5-15 $(COPTIONS)

Exercise_5-15.o: Exercise_5-15.c
	@echo "$(DUNPING)Compilings Exercise_5-15.c file$(DUNPING)"
	gcc $(CFLAGS) -c Exercise_5-15.c $(COPTIONS)

clean: 
	@echo "$(DUNPING)Removing everthing but the source files$(DUNPING)"
	rm Exercise_5-15.o Exercise_5-15 test.o test


test: test.o
	@echo "$(DUNPING)Linking and producing the test application$(DUNPING)"
	gcc $(CFLAGS) test.o -o test $(COPTIONS)

test.o: test.c
	@echo "$(DUNPING)Compilings test.c file$(DUNPING)"
	gcc $(CFLAGS) -c test.c $(COPTIONS)


