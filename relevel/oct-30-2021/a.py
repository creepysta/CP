
def modpow(a, b):
  res = 1
  while True:
    if not b:
      break
    if b & 1:
      res *= a
    a *= a
    b >>= 1;
  return res

INF = 1e12+5

tt = eval(input())
for t in range(tt):
  n = input()
  k = eval(input())
  sz = len(n)
  ans = int(n) % k
  n = eval(n)
  if sz <= 2:
    a = n % 10
    b = (n//10) % 10
    ans = max(a%k, b %k)
    print(ans)
    continue
  for i in range(2, sz+1):
    l = n // modpow(10, i)
    r = n % modpow(10, i-1)
    got = l * modpow(10, i-1) + r;
    now = got % k
    ans = max(ans, now)
  print(ans)

