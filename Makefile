all:
	gcc test.c ok.c fun.c -o spec
	./spec
