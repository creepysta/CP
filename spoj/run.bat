@echo off
Setlocal EnableDelayedExpansion

g++ DIEHARD.cpp -o DIEHARD
g++ test.cpp -o test
g++ gen.cpp -o gen
for /L %%i in (1,1,100000) DO (
	echo %%i
	call gen %%i
	gen %%i > in
	DIEHARD < in > out
	test < in > out1
	fc /L out out1 || goto :eof
)
