#!/d/Programs/Python/Python37/python

def validDate(mno):
    # TODO : 1 + for leap year Feb
    s = {1:31, 2:28, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}
    return s.get(mno, False)

f = open('input.txt', 'r')
s, t = f.read().split(' ')
valid = False
leap = False

d, m, r = s.split('/')
d = int(d, 10)
m = int(m, 10)
r = int(r, 10)

x, y, z = t.split('/')
x = int(x, 10)
y = int(y, 10)
z = int(z, 10)

if (d >= 30 and m >= 12 and r >= 2019) and (x >= 30 and y >= 12 and z >= 2019):
    if r == x:
        if m == y:
            if d <= x:
                valid = True
            else:
                valid = False
        elif m < y:
            valid = True
        else:
            valid = False
    elif r < x:
        valid = True
    else:
        valid = False

if m == 2:
    if (r % 4 == 0 || r % 400 == 0) and r % 100 != 0:
        leap = True
        if d <= 29:
            valid = True
        else:
            valid = False
    else:
        leap = False
        if d <= 28:
            valid = True
        else:
            valid = False
if y == 2:
    if (z % 4 == 0 || z % 400 == 0) and z % 100 != 0:
        leap = True
        if x <= 29:
            valid = True
        else:
            valid = False
    else:
        leap = False
        if x <= 28:
            valid = True
        else:
            valid = False

daysOfLeave = 1
count = 1
if valid:
    if m < y:
        while day <= validDate(m):
            daysOfLeave += 1
    days = 1
    for i in range(r, z+1):
        if m < 12 :

            if i == z and j == y:
                while days < x + 1:
                    count += 1
                    if count % 5 != 0:
                        daysOfLeave -= 2
                    daysOfLeave += 1
            else:
                while days <= validDate(j):
                    daysOfLeave += 1







# if (r % 4 == 0 || r % 400 == 0) and r % 100 != 0 :
#   return true
# else:
#   return false
