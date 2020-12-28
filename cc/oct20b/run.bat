@echo off
for /L %%i in (1, 1, 10000) DO (
	echo %%i
	gen %%i > in 
	b < in > b.out
	bb < in > bb.out
	fc /L b.out bb.out || goto :eof
)
