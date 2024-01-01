CFLAGS = -Wall -Wextra

all: app

app: kind_of_grep.o
	@echo "Linking and producing the kind_of_grep application"
	gcc $(CFLAGS) kind_of_grep.o -o app

kind_of_grep.o: kind_of_grep.c
	@echo "Compilings kind_of_grep file"
	gcc $(CFLAGS) -c kind_of_grep.c

clean: 
	@echo "Removing everthing but the source files"
	rm kind_of_grep.o app