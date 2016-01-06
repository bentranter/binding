// Regular C libs
#include <stdio.h>

// Elixir libs -- clang doesn't know where the hell this is
#include "erl_nif.h"

// Needs to figure out what ERL_NIF_TERM means
static ERL_NIF_TERM hello(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[]) {

	// We need some variables
	const char *s;
	int i, num;

	// Grab the arguments from Elixir
	enif_get_string(env, argv[0], s, 1024, ERL_NIF_LATIN1);
	enif_get_int(env, argv[1], &num);

	for (i = 0; i < num; i++) {
		printf("Hello, %s!\n", s);
	}

	return 0;
}

static ErlNifFuncs funcs[] = {
	{"hello", 2, hello}
};

ERL_NIF_INIT(Elixir.Hello, funcs, &hello)
