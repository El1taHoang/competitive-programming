n = int(input())
dp = {}
dp[0] = 1
def solve(n):
	res = 0
	if dp.get(n):
		res = dp[n]
	else:
		res = solve(n//2) + solve(n//3)
	dp[n] = res
	return res
print(solve(n))
