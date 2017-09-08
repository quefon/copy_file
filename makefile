all: acp
.PHONY: all

acp: copy_hw5.c
	gcc -o acp copy_hw5.c