.PHONY: all, items, items_hero

compiler = gcc
headers = -I headers/

main_file = main.c
source_code = src/*.c

output = -o out/output && ./out/output

headerful_compile_base = $(compiler) $(headers) $(main_file)
headerless_compile_base = $(compiler) $(main_file)

headerful_compile_all = $(headerful_compile_base) $(source_code) -o main && ./main


items:
	$(headerful_compile_base) src/items.c $(output)
items_hero:
	$(headerful_compile_base) src/items.c src/hero.c $(output)
all:
	$(headerful_compile_all)