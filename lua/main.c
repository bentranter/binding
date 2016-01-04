// Regular C libs
#include <stdio.h>

// Lua libs
#include <lua.h>
#include <lauxlib.h>

// Some normal native C function we want to call
void hello(const char *s, int repeat) {
	int i;

	for (i = 0; i < repeat; i++) {
		printf("Hello, %s!\n", s);
	}
}

// Bound function definition. The argument `lua_State *L` is required, since it's
// the reference to Lua's stack. This is the "wrapped" version of our "normal"
// C function.
int say_hello(lua_State *L) {

	// Get arguments by position. The first argument will always be at `1`
	// instead of `0` because you know how computer scientists love to keep
	// things consistent *rolls eyes*
	const char *s = lua_tostring(L, 1);
	int repeat = lua_tointeger(L, 2);

	// Call the C function on the value obtained from within Lua
	hello(s, repeat);

	// If you return a value, you need to call something like (depending on the
	// type of thing being returned):
	//
	//     lua_pushstring(L, "some string");
	//

	// Number of things on the stack to return. In our case, we're not returning
	// anything, so it's okay to return 0
	return 0;
}

// Build a table the basically just maps Lua names to C names
luaL_Reg binding[] = {

	// Desired Lua name, then C function name
	{"say_hello", say_hello},

	// It always has to end with `{NULL, NULL}`
	{NULL, NULL}
};

// Register the library in Lua. They got rid of `luaL_register`, so now you
// have to use lua_newtable(L) like a barbarian (just kidding, I know
// this was changed to prevent devs from registering libraries in the global
// namespace)
LUALIB_API int luaopen_binding (lua_State *L) {
	luaL_newlibtable(L, binding);
	luaL_setfuncs(L, binding, 0);
	return 1;
}
