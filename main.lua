-- Require the C code to be used inside Lua
local binding = require "binding"

-- Will print, "Hello, world!"
binding.say_hello("world")
