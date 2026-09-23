.PHONY: all run clean

all: build/main

build/main: object/main.o object/input.o object/msg.o | object build
	gcc object/main.o object/input.o object/msg.o -o build/main -Iinclude

object/main.o: src/main.c | src object
	gcc -c src/main.c -o object/main.o -Iinclude

object/input.o: src/input.c | src object
	gcc -c src/input.c -o object/input.o -Iinclude

object/msg.o: src/msg.c | src object
	gcc -c src/msg.c -o object/msg.o -Iinclude

build:
	mkdir -p build

object:
	mkdir -p object

run:
	./build/main

clean:
	rm -r build object