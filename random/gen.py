j=0
print("0 " + str(j))
for i in range(1,21):
    j = j ^ i
    print(str(i) + ' ' + str(j))
