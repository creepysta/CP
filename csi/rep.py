#!/d/Programs/Python/Python37/python
def processArray(a):
    #for i in range(len(a)):
    i = 0
    while i < len(a):
        if a[i] != '' and a[i] % 2 != 0:
            j = i + 1
            c = 1
            while j < len(a) and not a[j] % 2 == 0:
                j += 1
                c += 1
            if c > 1:
                for x in range(i, j):
                    a[x] = ''
                a[i] = c
            i = j
            #print(c)
        i += 1
        #print(a)
    for i in a:
        if i != '':
            print(i)


if __name__ == "__main__":
    a = []
    while True:
        x = int(input())
        if x < 0:
            break
        a.append(x)
    processArray(a)
