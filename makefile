all: run

build:
	gcc src/main.c src/grid.c src/cells.c src/toolbar.c -O2 -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o out/astrosand

run: build
	./out/astrosand