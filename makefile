ucysh: echo pwd cd history kill
	gcc ucysh.c -o ucysh -lreadline

echo: echo.c
	gcc echo.c -o echo

pwd: pwd.c
	gcc pwd.c -o pwd

cd: cd.c
	gcc cd.c -o cd

history: history.c
	gcc history.c -o history

kill: kill.c
	gcc kill.c -o kill

clean:
	-rm -f *.o
	-rm -f ucysh
	-rm -f echo
	-rm -f pwd
	-rm -f cd
	-rm -f history
	-rm -f kill
	-rm -f *~
