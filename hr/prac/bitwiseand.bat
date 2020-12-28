@echo off
for /L %%i in (1,1,100000) DO (
		echo %%i
		bitwiseand_gen %%i > in
		REM bitwiseand < in > b.out
		bitwiseand_brute < in > b.out
		bitwiseand_works < in > bw.out
		fc /L b.out bw.out || goto :eof
		)

