import re

s = input()
numbers = re.findall(r'[0-9.]+', s)
cents = 0
for i in range(len(numbers)):
    num = numbers[i]
    if len(num) > 2 and num[-3] == '.':
        cents += int(num[-2:])
        numbers[i] = num[:-3]
    numbers[i] = numbers[i].replace('.', '')

res = sum(map(int, numbers))
res += cents // 100
cents %= 100
print(f'{res:,.0f}'.replace(',', '.'), end='')
if cents:
    print(f'.{str(cents).zfill(2)}')
else:
    print()