package main

// #include "main.h"
import "C"

func main() {
	C.say_hello(C.CString("World!"), C.int(5))
}
