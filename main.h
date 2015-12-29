// This code is for Lua 5.2.X. For 5.0, the single call to
//
//    luaL_openlibs(L)
//
// should be
//
//    luaopen_base(L);
//    luaopen_table(L);
//    luaopen_io(L);
//    luaopen_string(L);
//    luaopen_math(L);
//

// Regular C libs
#include <stdio.h>
#include <string.h>

// Lua libs
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

// Elixir libs


int main(void) {
	char buf[256];
	int err;

	lua_State *L = lua_open();
	luaL_openlibs(L);
}
