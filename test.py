T = eval(input())

for t in range(T):
  n = input()
  k = eval(input())
  ans = int(n) % k
  for i in range(0, len(n)):
    l = n[:i]
    r = n[i+1:]
    if(len(l) and len(r)):
      ans = max(ans, int(l) % k, int(r) % k)
  print(ans)
