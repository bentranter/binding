Calling C Functions From Go
---

Oh goodness... If you thought calling C from Lua was easy, you're going to absolutely **love** doing it from Go!

**Step 1**: Create a `.c` file and a header `.h` file. Make a function, any function. Let's do our classic "Hello, world!" example:

*This is your `main.h` file:*

```c
#include <stdio.h>

void say_hello(char *s, int repeat);
```

*This is your `main.c` file:*

```c
void say_hello(char *s, int repeat) {
	int i;
	for (i = 0; i < repeat; i++) {
		printf("Hello, %s\n!", s);
	}
}
```

**Step 2**: Create a `main.go` file, and *include the header file you just created*, like so:

```go
package main

// #include "main.h"
import "C"

func main() {
	C.say_hello(C.CString("World!"), C.int(5))
}
```

Note that although `#include "main.h"` is commented out, because we've included `C`, Go will actually see that comment and realize it needs to find that header file. It's worth noting that comment must be in that exact spot in your code, that is, right before you `import "C"`.

So, after that... you just... ???? ... call your C code? That's messed up, programming is never this easy. In all seriousness though, that's it: it's incredibly easy to call Go from C. You can clone this repo and run `go build` in this directory, and the example will work. It gets a *tiny* bit more complicated when you want to use more complicated data types like structs or pointers, but it's still wayyyy easier than other languages. You can read the documentation for the `C` package [right here](https://golang.org/cmd/cgo/).

Happy binding!
