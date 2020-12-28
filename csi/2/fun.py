#!/d/Programs/Python/Python37/python
from datetime import date,timedelta

f = open("input.txt", 'r')
s, t = f.read().split(' ')
f.close()
d, m, r = s.split('/')
d = int(d, 10)
m = int(m, 10)
r = int(r, 10)

x, y, z = t.split('/')
x = int(x, 10)
y = int(y, 10)
z = int(z, 10)

valid = False

fromDate = date(r, m, d)
toDate = date(z, y, x)

if fromDate <= toDate and fromDate >= date(2019, 12, 30):
    valid = True

f = open('output.txt', 'w')
if valid:
    numDays = (fromDate + timedelta(x+1) for x in range((toDate-fromDate).days + 1))
    f = open('output.txt', 'w')
    f.write(str(sum(1 for i in numDays if i.weekday() < 5)))
else:
    f.write('invalid')

f.close()

