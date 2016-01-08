ERLANG_PATH = $(shell erl -eval 'io:format("~s", [lists:concat([code:root_dir(), "/erts-", erlang:system_info(version), "/include"])])' -s init stop -noshell)

binding:
	gcc -fPIC -I$(ERLANG_PATH) -dynamiclib -undefined dynamic_lookup -o binding.so main.c

clean:
	rm -f binding.so Elixir.Hello.beam

.PHONY: all clean
