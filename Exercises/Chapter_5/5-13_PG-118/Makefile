CFLAGS =
COPTIONS =
DUNPING = *** 

all: Exercise_5-13

Exercise_5-13: Exercise_5-13.o
	@echo "$(DUNPING)Linking and producing the Exercise_5-13 application$(DUNPING)"
	gcc $(CFLAGS) Exercise_5-13.o -o Exercise_5-13 $(COPTIONS)

Exercise_5-13.o: Exercise_5-13.c
	@echo "$(DUNPING)Compilings Exercise_5-13.c file$(DUNPING)"
	gcc $(CFLAGS) -c Exercise_5-13.c $(COPTIONS)

clean: 
	@echo "$(DUNPING)Removing everthing but the source files$(DUNPING)"
	rm Exercise_5-13.o Exercise_5-13