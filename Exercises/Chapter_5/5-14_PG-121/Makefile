CFLAGS = -Wall -Wextra
COPTIONS =
DUNPING = *** 

all: Exercise_5-14

Exercise_5-14: Exercise_5-14.o
	@echo "$(DUNPING)Linking and producing the Exercise_5-14 application$(DUNPING)"
	gcc $(CFLAGS) Exercise_5-14.o -o Exercise_5-14 $(COPTIONS)

Exercise_5-14.o: Exercise_5-14.c
	@echo "$(DUNPING)Compilings Exercise_5-14.c file$(DUNPING)"
	gcc $(CFLAGS) -c Exercise_5-14.c $(COPTIONS)

clean: 
	@echo "$(DUNPING)Removing everthing but the source files$(DUNPING)"
	rm Exercise_5-14.o Exercise_5-14