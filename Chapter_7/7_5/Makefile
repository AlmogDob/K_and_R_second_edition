CFLAGS = -Wall -Wextra
COPTIONS =
DUNPING = ***

all: cat

cat: cat.o
	@echo "$(DUNPING)Linking and producing the cat application$(DUNPING)"
	gcc $(CFLAGS) cat.o -o cat $(COPTIONS)

cat.o: cat.c
	@echo "$(DUNPING)Compilings cat.c file$(DUNPING)"
	gcc $(CFLAGS) -c cat.c $(COPTIONS)

clean: 
	@echo "$(DUNPING)Removing everthing but the source files$(DUNPING)"
	rm cat.o cat