@echo off
Setlocal EnableDelayedExpansion

for /L %%i in (1,1,100000) DO (
	echo %%i
	gen %%i > in
        python relevel\oct-30-2021\a.py < in > out
	python test.py < in > out1
	fc /L out out1 || goto :eof
)
