@echo off
for /L %%i in (1,1,100000) DO (
		echo %%i
		gen %%i > in
		java anirban < in > aout
		fourfunctions < in > myout
		fc /L aout myout || goto :eof
		)
