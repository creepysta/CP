t = eval(input())
for _ in range(t):
	n = eval(input())
	a, b = 0 , 0
	ok = True
	x = input().split(' ')
	x = [int(num) for num in x]
	for i in range(len(x)):
		if x[i]==5:
			a += 1
		elif x[i] == 10:
			if a > 0:
				a -=1
				b += 1
			else:
				ok = False
				break
		else:
			if b > 0:
				b-=1
			elif a >1:
				a-=2
			else:
				ok = False
				break

	if(ok):
		print("YES")
	else:
		print("NO")
