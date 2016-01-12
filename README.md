Binding
===

A how-to for calling C functions from every language.

Usage
---

Each language has their own folder, and in that folder is an example of how to call a C function from another language, as well as a README explaining how it works. The code is very basic, but provides a working example that (I hope!) serves a starting point for anyone wanting to call some C code from a different language.

Languages
---

- Lua
- Elixir
- Go

*Upcoming languages*:

- **Ruby**
- JavaScript (Node.js)
- Swift
- Erlang
- Python
- OCaml

Suggestions
---

If you want to suggest a language, please open an issue, or better yet, submit a PR!

Note About Windows
---

I have used `.so` files in most examples. Although you should be able to change the Makefiles to produce `.dll` files on Windows, I haven't tried it myself, so I can't guarantee that it'll work. I promise to either try to fix this one day, or ask a friend who develops on Windows to help me, heh.
