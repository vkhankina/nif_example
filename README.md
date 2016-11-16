# NIF Example
=============

NIF example illustrates how to make a tine C module example.c available from Erlang.

To run the project:
```
  $ make -f Makefile
  $ erl
```

In Erlang shell:
```
  1> c(example).
  2> example:sum(3,7).
  10
  3> example:twice(2).
  4
```