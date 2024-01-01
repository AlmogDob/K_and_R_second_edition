CFLAGS = -Wall -Wextra
COPTIONS =
DUNPING = *** 

all: modified_sort

modified_sort: modified_sort.o
	@echo "$(DUNPING)Linking and producing the modified_sort application$(DUNPING)"
	gcc $(CFLAGS) modified_sort.o -o modified_sort $(COPTIONS)

modified_sort.o: modified_sort.c
	@echo "$(DUNPING)Compilings modified_sort.c file$(DUNPING)"
	gcc $(CFLAGS) -c modified_sort.c $(COPTIONS)

clean: 
	@echo "$(DUNPING)Removing everthing but the source files$(DUNPING)"
	rm modified_sort.o modified_sort