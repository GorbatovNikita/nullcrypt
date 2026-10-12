items:
	gcc -I headers/ main.c src/items.c -o items && ./items && rm items

all:
	gcc -I headers/ main.c src/*.c -o main && ./main