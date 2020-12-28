@echo off
for /L %%i in (1, 1, 10000) DO (
	echo %%i
	gen %%i > in 
	c < in > op
	c_ans < in > op1
	fc /L op op1 || goto :eof
)
