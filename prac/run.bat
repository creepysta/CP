@echo off
Setlocal EnableDelayedExpansion

for /L %%i in (1,1,100000) DO (
	echo %%i
	call gen %%i
	gen %%i > in
	totalsetbits1ton < in > out
	totalsetbits1ton < in > out1
	fc /L out out1 || goto :eof
)
