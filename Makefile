binding:
	gcc -Wall -fPIC -c lua/main.c
	gcc -shared -llua -o lua/binding.so lua/main.o

clean:
	rm -f lua/binding.so lua/main.o

lua:
	lua lua/main.lua
