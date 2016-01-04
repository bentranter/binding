binding:
	gcc -Wall -fPIC -c main.c
	gcc -shared -llua -o binding.so main.o

clean:
	rm -f binding.so main.o

lua:
	lua main.lua
