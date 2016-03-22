default: ucysh

program.o: ucysh.c
	gcc -c ucysh.c -o ucysh.o

ucysh: ucysh.o
	gcc ucysh.o -o ucysh -lreadline

clean:
	-rm -f ucysh.o
	-rm -f ucysh
	-rm -f *~
