# Author: Aaron He
# Created: Monday, 12 December 2022

# Test case 6
a = [[3208667, 5253445],
[3261218, 4249213],
[1148946, 6539195],
[1734871, 5978638],
[297042, 2664517],
[2036574, 5920950],
[1437396, 8778816],
[1701561, 8246186],
[3818011, 9781191],
[4530835, 9094529],
[8448287, 8684936],
[2365869, 6178888],
[1342150, 3310796],
[5989573, 7777168],
[9953364, 9989510],
[867752, 7356775],
[3168925, 8465566],
[2285248, 5851077],
[6584505, 8615492],
[575358, 1973029],
[50777, 9330837],
[5892473, 9223391],
[3559828, 9814736],
[2462527, 4326115],
[4795974, 8469751],
[605519, 8360624],
[627112, 5890615],
[5986848, 6245214],
[1003506, 8459080],
[75797, 7006745]]
t = 10 ** 6
print(t)
for i in range(t):
	print(*a[i % len(a)])