@echo off
for /L %%i in (1,1,100000) DO (
	echo %%i
	lis_gen %%i > in
	REM lis_fast < in
	lis_fast < in > op1
	lis < in > op2
	fc /L op1 op2 || goto :eof
)
