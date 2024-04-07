
.PHONY: all build clean test

all: build

build:
	@mkdir -p build
	@gcc -g -o build/watcher main.c fswait.c -framework CoreServices

cmake:
	@mkdir -p build && cd build && cmake .. && cmake --build .

clean:
	@rm -rf build

test: build
	@echo "starting test..."
	@./build/watcher

	