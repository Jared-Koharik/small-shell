CF := -Wall -Wextra -pedantic
OBJ := object/main.o object/input.o object/msg.o object/command.o

.PHONY: all run clean

all: build/main

build/main: $(OBJ) | object build
	gcc $(OBJ) -o build/main -Iinclude

object/%.o: src/%.c | src object
	gcc $(CF) -MMD -MP -c $< -o $@ -Iinclude

-include $(OBJ:.o=.d)

build:
	mkdir -p build

object:
	mkdir -p object

run:
	./build/main

clean:
	rm -r build object