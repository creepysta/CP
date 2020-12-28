import re
s = input()
print(len(set(filter(lambda a: a != '', re.sub('[{}, ]',' ', s).split(' ')))))