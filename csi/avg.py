#!/d/Programs/Python/Python37/python
def processArray(a):
    s = 0
    #for i in range(len(a)):
    i = 0
    while i < len(a):
        s += a[i]
        i += 1
    s = s // len(a)
    print(s)
if __name__ == "__main__":
    a = []
    while True:
        x = int(input())
        if x < 0:
            break
        a.append(x)
    processArray(a)
