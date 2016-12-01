# Compiler flags for Unix
CFLAGS=-fpic -shared
LIB_PATH=/usr/lib/erlang/usr/include/
# Compiler flags for Darwin
#CFLAGS=-fpic -bundle -flat_namespace -undefined suppress
#LIB_PATH=/usr/local/Cellar/erlang/19.1/lib/erlang/usr/include/

all: example.o example_nif.o
	gcc -o example_nif.so $(CFLAGS) example.o example_nif.o

example.o: example.c
	gcc -c example.c

example_nif.o: example.o example_nif.c
	gcc -c example_nif.c -I$(LIB_PATH)

clean:
	rm -rf *.o example_nif.so
