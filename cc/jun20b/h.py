def solve():
	n = eval(input())
	l = 1
	h = n
	q = []
	while l <= h:
		m = l + (h-l)//2
		print(m,end='\n')
		c = input()
		if c == 'E':
			return;
		elif c=='G':
			q.append((l, m-1))
			l = m + 1
		else:
			q.append((m+1, h))
			h = m-1
	while q:
		l, h = q.pop(0)
		while l <= h:
			m = l + (h-l)//2
			print(m,end='\n')
			c = input()
			if c == 'E':
				return;
			elif c=='G':
				q.append((l, m-1))
				l = m + 1
			else:
				q.append((m+1, h))
				h = m-1

if __name__ == "__main__":
	solve()
