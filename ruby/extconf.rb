# The lib `mkmf` allows you to generate Makefiles, which is so sweeeeeeeeeeet
# because it's insanely annoying write your own cross platform.
require 'mkmf'

# Give it a name, and that's it! That's all the Ruby you need to write.
create_makefile 'hello'
