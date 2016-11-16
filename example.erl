-module(example).
-export([
  sum/2,
  twice/1
]).
-on_load(init/0).

init() ->
  ok = erlang:load_nif("./example_nif", 0).

sum(_X, _Y) ->
  exit(nif_library_not_loaded).

twice(_X) ->
  exit(nif_library_not_loaded).
