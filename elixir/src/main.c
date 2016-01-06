// Regular C libs
#include <stdio.h>

// Elixir libs -- clang doesn't know where the hell this is
#include "erl_nif.h"

// Needs to figure out what ERL_NIF_TERM means
static ERL_NIF_TERM hello(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[]) {

}

static ErlNifFuncs funcs[] = {
	{"hello", 2, hello}
};

ERL_NIF_INIT(Elixir.Hello, funcs, &hello)
