ucysh: echo pwd
	gcc ucysh.c -o ucysh -lreadline

echo: echo.c
	gcc echo.c -o echo

pwd: pwd.c
	gcc pwd.c -o pwd

clean:
	-rm -f *.o
	-rm -f ucysh
	-rm -f echo
	-rm -f pwd
	-rm -f *~
