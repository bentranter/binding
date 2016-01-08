// Regular C libs
#include <stdio.h>

// Elixir libs
#include "erl_nif.h"

#define MAXLEN 1024

// Needs to figure out what ERL_NIF_TERM means
static ERL_NIF_TERM hello(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[]) {

	// We need some variables
	char buf[MAXLEN];
	int i, num;

	// Grab the arguments from Elixir
	enif_get_string(env, argv[0], buf, MAXLEN, ERL_NIF_LATIN1);
	enif_get_int(env, argv[1], &num);

	for (i = 0; i < num; i++) {
		printf("Hello, %s!\n", buf);
	}

	// Fancy version of return 0
	return enif_make_int(env, 0);
}

// Map Elixir functions to C functions
static ErlNifFunc funcs[] = {

	// Function name in Elixir, number of arguments, C function
	{"hello", 2, hello}
};

ERL_NIF_INIT(Elixir.Hello, funcs, NULL, NULL, NULL, NULL)
