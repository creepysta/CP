@echo off
for /L %%i in (1,1,10000000) DO (
		echo %%i
		gen %%i > in
		more in
		sherlock-and-pairs < in > op1
		sherlock-and-pairs_brute < in > op2
		fc /L op1 op2 || goto :eof
		)
