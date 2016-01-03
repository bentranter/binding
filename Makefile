binding:
	gcc -Wall -fPIC -c main.c
	gcc -shared -llua -o binding.so main.o

clean:
	rm -f $(BIN)
