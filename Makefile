binding:
	gcc -Wall -fPIC -c ./lua/main.c
	gcc -shared -llua -o binding.so main.o

clean:
	rm -f binding.so main.o

lua:
	lua lua/main.lua

.PHONY: lua clean
