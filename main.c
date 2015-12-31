// Regular C libs
#include <math.h>

// Lua libs
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

// Register function for use in Lua
static int l_sin (lua_State *L) {
  // Get the argument
  double d = lua_tonumber(L, 1);

  // Push the result
  lua_pushnumber(L, sin(d));

  // Number of results
  return 1;
}
