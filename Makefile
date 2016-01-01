binding:
	gcc -fPIC -o binding.o -c main.c
	gcc -shared binding.o -o binding.so

clean:
	rm -f $(BIN)
