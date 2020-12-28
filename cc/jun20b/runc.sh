for((i=1;;i++))
do
	echo $i
	python gen.py $i
	diff <(g++ -o a c.cpp && ./a < inc1) <(g++ -o brutec brutec.cpp && ./brutec < inc1) || break
done
