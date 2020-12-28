import re
if __name__ == "__main__":
	s = input()
	check = re.search('\w*h\w*e\w*l\w*l\w*o\w*',s)
	if check:
		print("YES")
	else:
		print("NO")