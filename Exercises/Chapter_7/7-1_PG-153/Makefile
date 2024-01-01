CFLAGS = -Wall -Wextra
COPTIONS =
DUNPING = ***

all: converter

converter: converter.o
	@echo "$(DUNPING)Linking and producing the converter application$(DUNPING)"
	gcc $(CFLAGS) converter.o -o converter $(COPTIONS)

converter.o: converter.c
	@echo "$(DUNPING)Compilings converter.c file$(DUNPING)"
	gcc $(CFLAGS) -c converter.c $(COPTIONS)

clean: 
	@echo "$(DUNPING)Removing everthing but the source files$(DUNPING)"
	rm converter.o converter