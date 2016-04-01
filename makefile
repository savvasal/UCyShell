ucysh: echo
	gcc ucysh.c -o ucysh -lreadline

echo: echo.c
	gcc echo.c -o echo

clean:
	-rm -f *.o
	-rm -f ucysh
	-rm -f echo
	-rm -f *~
