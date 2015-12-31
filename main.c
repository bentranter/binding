// Regular C libs
#include <stdio.h>

// Lua libs
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

// Elixir libs


lua_State *L;

static int say_hello(lua_State *L) {
  const char *s = lua_tostring(L, 1);
  printf("Hello, %s!\n", s);
  return 0;
}

int main(int argc, char *argv[]) {
  L = lua_open();
  luaL_openlibs(L);

  lua_register(L, "say_hello", say_hello);

  lua_close(L);
  return 1;
}
