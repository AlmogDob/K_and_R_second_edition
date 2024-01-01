CFLAGS = -Wall -Wextra
COPTIONS =
DUNPING = ***

all: Exercise_7-6

Exercise_7-6: Exercise_7-6.o
	@echo "$(DUNPING)Linking and producing the Exercise_7-6 appliExercise_7-6ion$(DUNPING)"
	gcc $(CFLAGS) Exercise_7-6.o -o Exercise_7-6 $(COPTIONS)

Exercise_7-6.o: Exercise_7-6.c
	@echo "$(DUNPING)Compilings Exercise_7-6.c file$(DUNPING)"
	gcc $(CFLAGS) -c Exercise_7-6.c $(COPTIONS)

clean: 
	@echo "$(DUNPING)Removing everthing but the source files$(DUNPING)"
	rm Exercise_7-6.o Exercise_7-6