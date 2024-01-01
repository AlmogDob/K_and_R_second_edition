CFLAGS = -Wall -Wextra

all: app

app: versions_of_echo.o
	@echo "Linking and producing the versions_of_echo application"
	gcc $(CFLAGS) versions_of_echo.o -o app

versions_of_echo.o: versions_of_echo.c
	@echo "Compilings versions_of_echo file"
	gcc $(CFLAGS) -c versions_of_echo.c

clean: 
	@echo "Removing everthing but the source files"
	rm versions_of_echo.o app