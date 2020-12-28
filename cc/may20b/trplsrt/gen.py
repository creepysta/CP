from itertools import permutations
from random import randint
from math import factorial

def fact(f):
    if f:
        return f * fact(f-1)
    else:
        return 1 
	
def smallr(r, m):
	nums = [str(i+1) for i in range(r)]
	perms = permutations(nums)
	
	f = open('in'+str(r), 'w')
	lr = fact(r)
	f.write(str(lr) + '\n')
	
	for _ in range(lr):
		f.write(f'{r} {m}\n')
		f.write(' '.join(list(next(perms))))
		f.write('\n')
	
	
	
def bigr(r, m, lr):
	nums = [str(i+1) for i in range(r)]
	perms = permutations(nums)
	
	f = open('in4', 'w')
	f.write(str(lr) + '\n')
	
	skip = 10
	flr = factorial(skip)
	
	for _ in range(lr):
		perm = None
		c = randint(1,flr);
		for __ in range(c):
			perm = next(perms)
		
		if perm:
		    f.write(f'{r} {m}\n')
		    f.write(' '.join(list(perm)))
		    f.write('\n')
	
	
smallr(4, 2)
# bigr(400, 400, 1000)
