Calling C Functions From Elixir
---

> I guess you could say it's... *pretty NIFty* \*whole audience cringes\*.

**What the heck is a nif?** A `NIF` is a Native Implemented Function. It was introduced in Erlang/OTP a while ago as a simpler and more efficient way of calling C code (the previous way was using ports, which you can also do in Elixir, but we won't be covering). NIF's are fantastic for things that Elixir (and Erlang) can't do so well, like crypto.

You can write some NIFs an then export them as a library. To anyone who uses your library, it will look like a typical Elixir module, that is, the user won't notice that your library is written in C using NIFs.

Before trying to figure out how to call a function from C in Elixir, it's probably a good idea to try to understand how to call a function from Erlang in Elixir, since we're really just going to be using *Erlang's* NIF functionality.

**Warning**: If your C code crashes, it'll take the entire Erlang VM down!

Usage within IEx
---
The easiest way to try our your NIF is with IEx. To do this start IEx:

```sh
$ iex
```

Once IEx has started, you need to import your NIF. After that, you can call a function:

```sh
iex(1)> c "main.ex"
[Hello]
iex(2)> Hello.hello('world', 1)
Hello, world!
[0]
```
