# Author: Aaron He
# Created: Monday, 12 December 2022

import random
random.seed(0)
a = 'abcdefghijklmnopqrstuvwxyz'
mx = 2 * 10 ** 5
t = 1
print(t)
b = ''
for _ in range(mx//702):
	r = [i for i in range(26)]
	random.shuffle(r)
	b += a[r[0]] + a[r[0]]
	for i in range(25):
		for j in range(i + 1, 26):
			b += a[r[i]] + a[r[j]]
			if i == 0:
				b += a[r[j]] + a[r[j]]
	n = min(len(b), mx//t)

print(n)
s = ''
print(b[:n])

