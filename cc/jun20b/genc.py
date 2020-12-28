import random
import sys
random.seed(a=sys.argv[1])
cream = [5, 10 ,15]
f = open('inc1', 'w')
f.write('1\n')
n = random.randint(3,10)
f.write(str(n) + '\n')
for i in range(n):
	f.write(str(cream[random.randint(0, len(cream)-1)]) + ' ')
f.write('\n')
