Calling C from Ruby
---

Calling C from Ruby is pretty similar to the other languages in this repo - you write some C, write a function that maps function names, and generate a shared object so link with the Ruby runtime. However, Ruby has a utility to generate Makefiles based on your C code, which makes life about a million times easier, sicne there's no need to write an insane Makefile yourself.

The Ruby code for this is incredibly simple:

```ruby
require 'mkmf'
create_makefile 'your_C_lib_name'
```

This Ruby file must be named `extconf.rb`. To generate the Makefile, run `ruby extconf.rb`. From there, you can just run `make` and it'll generate the shared object. You call also run `make clean` to delete everything.

The C file is a bit different:

```c
#include <ruby.h>

static VALUE hello(int argc, VALUE *argv, VALUE self);
```

You (obviously) need to inclulde the library `<ruby.h>`. Your functions that talk to Ruby need to start with `VALUE`, and have the arguments above in the function definition.
