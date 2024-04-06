
.PHONY: all build clean test

all: build

build:
	@gcc -o watcher main.c fswait.c -framework CoreServices

clean:
	@rm -f watcher

test: build
	@echo "starting test..."
	@./watcher

	