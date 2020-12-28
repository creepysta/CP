for((i=1;;i++))
do
	echo $i
	python gen.py $i >ind1
	#diff <(g++ -o a d.cpp && ./a < ind1) <(g++ -o brute brute.cpp && ./brute < ind1) || break
	diff <(./a < ind1) <(./brute < ind1) || break
done
