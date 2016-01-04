Calling C Functions From Lua
---

You can easily call a C function from within Lua. In your C file, you'll need to include:

```C
// Lua libs
#include <lua.h>
#include <lauxlib.h>
```

Once you've got those, you'll need to write a function with `lua_State *L` as the only argument. The return type must be `int`:

```C
int hello(lua_State *L);
```

`L` is simply a reference to Lua's stack. The `int` we return is how many values on the stack we're returning to Lua-land. To access the arguments provided to our Lua function, we can do:

```C
// Get the first argument (yes the first arg is at 1, not 0) and cast it to a string
const char *some_string = lua_tostring(L, 1);

// Get the second argument, and cast it to an integer
int some_number = lua_tointeger(L, 2);
```

There are other types you can cast to, like double, boolean, etc. It's easy to find out about them in the Lua docs.

Once you've written one (or more) functions, you'll need to make a table that basically just maps C functions to Lua functions:

```C
// You *must* have `luaL_Reg` here
luaL_Reg binding[] = {

  // Lua name, then C function name
  {"hello", hello},

  // It always has to end with either `{NULL, NULL}` or `{0, 0}`
  {NULL, NULL}
};
```

The last thing you need to do before compiling is to write a function to register your C functions in Lua. There are some caveats:

- The argument is always `lua_State *L`
- The `LUALIB_API` is required
- The function name `luaopen_binding` is **extremely** important. The Lua interpreter will look for this *function specifically*. The word `binding` can be anything you want, as long as it matches the name of the array you created in `LuaL_Reg`. This will be the name your library that you can call from Lua's `require` system.

In Lua 5.2, you need to use the `luaL_newlibtable` and `luaL_setfuncs` functions, **instead of** `lua_register` (this is a new thing in Lua 5.2):

```C
LUALIB_API int luaopen_binding (lua_State *L) {
  luaL_newlibtable(L, binding);
  luaL_setfuncs(L, binding, 0);
  return 1;
}
```

To compile your code into a (shared object) file (`.so` on Unix, `.dll` on Windows... if you're reading this on Windows, replace `.so` with `.dll` everywhere and it should work) for use by the Lua interpreter, you'll need to first compile your code with a few flags that you might've never seen before:

```bash
gcc -Wall -fPIC -c your_c_file_name.c
```

> Note: Although I use GCC in this example, this works with Clang as well

The `-Wall` flag tells GCC to produce position independent code. Basically, when you're writing code that's going to be dynamically linked (like we've just done), you need to avoid limiting the value of the size of the global offset table. The `-c` option is used to create a `.o` file, which we need to then create a `.so` file.

The next thing you'll need to do is create the shared object `.so` file. To do this, run:

```bash
gcc -shared -llua -o binding.so your_c_file_name.o
```

The `-shared` flag tells GCC to make a `.so` file, and the `-llua` flag tells GCC we're using Lua, and to go find the file that helps us with that.

Once you've done that, the Lua code is beautifully simple:

```lua
local binding = require "binding"

binding.hello(--[[ Some arguments ]])
```

Please check the source code for an example implementation, I hope you'll find it pretty straightforward. If you find a bug or have a question, please open an issue.
