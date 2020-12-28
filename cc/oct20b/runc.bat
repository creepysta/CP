@echo off
for /L %%i in (1, 1, 100000) DO (
		echo %%i
		genc %%i > in
		c < in > c.out
		cc < in > cc.out
		fc /L c.out cc.out || goto :eof
		)
