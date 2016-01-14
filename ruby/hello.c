// Regular C libraries
#include <stdio.h>

// Include the Ruby headers and goodies
#include <ruby.h>

// The functions you define must start with `VALUE`
static VALUE hello(int argc, VALUE *argv, VALUE self) {
	const char *buf;
	int num, i;

	// If the user doesn't pass the correct number of arguments, tell them
	// they've done wrong
	if ((argc < 1) || (argc > 2)) {
		rb_raise(rb_eArgError, "wrong # of arguments (expected 2, got %d)", argc);
		return Qnil;
	}

	// Make sure the arguments are the correct type. In our case, we want the
	// first one to be a string
	if (TYPE(argv[0]) == T_STRING) {
		buf = RSTRING_PTR(argv[0]);
	} else {
		rb_raise(rb_eTypeError, "in method `hello`, argument `1` of type `String`");
		return Qnil;
	}

	if (TYPE(argv[1]) == T_FIXNUM) {
		num = NUM2INT(argv[1]);
	} else {
		rb_raise(rb_eTypeError, "in method `hello`, argument `2` of type `Number`");
	}

	for (i = 0; i < num; i++) {
		printf("Hello, %s!\n", buf);
	}

	return Qnil;
}

void Init_hello(void) {
	rb_define_method(rb_cString, "hello", ((VALUE(*)(ANYARGS)) hello), -1);
}
