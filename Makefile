BIN=binding
LIBS=-llua -llualib

binding: main.c Makefile
	clear
	$(CC) main.c $(LIBS) -o $(BIN)

clean:
	rm -f $(BIN)
