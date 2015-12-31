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

// Lua libs
#include <lua.h>
#include <lauxlib.h>

// Elixir libs


lua_State *L;

static int draw_rectangle(lua_State *L) {
	float x = lua_tonumber(L, 1);
	float y = lua_tonumber(L, 2);
}

int main(int argc, char *argv[]) {
	L = lua_open();

	lua_close(L);
	return 0;
}
