import numpy as np
import sys


ans = 0
grid = list()

def valid(y, x, n):
  for i in range(9):
    if grid[i][x] == n:
        return False
  for i in range(9):
    if grid[y][i] == n:
        return False
  x, y = (x//3)*3, (y//3)*3
  for i in range(3):
    for j in range(3):
      if grid[i+y][j+x] == n:
        return False
  return True

def solve(idx):
  global ans, grid
  for i in range(9):
    for j in range(9):
      if grid[i][j] == 0:
        for n in range(1, 10):
          if valid(i, j, n):
            grid[i][j] = n
            solve(idx)
            grid[i][j] = 0
        return
  print(idx, int("".join([str(x) for x in np.array(grid)[0, 0:3]])))
  print(np.matrix(grid))
  ans += int("".join([str(x) for x in np.array(grid)[0, 0:3]]))

for idx, line in enumerate(sys.stdin.readlines()):
  if idx % 10 == 0:
    if idx > 0:
      solve(idx//10)
    grid = []
    continue
  grid.append([int(x) for x in line if x != '\n'])



print(ans)

