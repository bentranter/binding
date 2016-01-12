// Include the header file. Go requires you to structure your code the "normal"
// way, where you have a `.c` file and it's accompanying header file. That's
// alright with me though, because it makes it ludicrously easy to call C
// functions... I mean you can literally just call them from Go.
#include "main.h"

// Function definition. Nothing fancy here at all, IT's JUST REGULAR C!!!
void say_hello(char *s, int repeat) {
	int i;
	for (i = 0; i < repeat; i++) {
		printf("Hello, %s\n!", s);
	}
}
