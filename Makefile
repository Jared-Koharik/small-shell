.PHONY: all run clean

all: build/main

build/main: src/main.c | build
	gcc src/main.c -o build/main

build:
	mkdir -p build

run:
	./build/main

clean:
	rm -r build