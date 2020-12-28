#!/d/Programs/Python/Python37/python
def processArray(a):
    srk = [-9999, 0]
    for i in range(len(a)-1):
    #i = 0
    #while i < len(a) - 1:
        if a[i] <= a[i+1]:
            j = i
            c = 1
            while j < len(a) - 1 and a[j] <= a[j+1]:
                j += 1
                c += 1
            diff = a[j] - a[i]
            if diff > srk[0]:
                srk = [diff, c]
            i = j
        #print(srk)
        i += 1
    print(srk[1])
                
if __name__ == "__main__":
    a = []
    while True:
        x = int(input())
        if x < 0:
            break
        a.append(x)
    processArray(a)
