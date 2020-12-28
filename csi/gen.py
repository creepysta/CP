#!/d/Programs/Python/Python37/python
import random
f = open('te', 'w')
for i in range(10000000):
    f.write(str(random.randint(1,1000)) + '\n')
f.write(str(-1))
f.close()
