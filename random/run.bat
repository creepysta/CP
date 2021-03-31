@echo off
for /L %%i in (1,1,28) DO (
	REM python -c "import random; random.seed(%%i);print(random.randint(1,20));" > in 
	echo %%i > in
	abhi_aeiou < in > o1
	abhi_aeiou_brute < in > o2
	fc /L o1 o2 || goto :eof
)

