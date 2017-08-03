from collections import defaultdict

bells, budget = map(int, raw_input().split())
bellsvalues = map(int, raw_input().split())
values = defaultdict(int)
for i in bellsvalues:
	values[i] += 1
dp = [0] * 50001
acum = 0
for i in range(1, len(dp)):
	dp[i] = acum + values[i]
	acum += values[i]
sells = int(raw_input())
sellers = map(int, raw_input().split())
for i in sellers:
	if budget / i > 50000:
		print 0
	else:
		print bells - dp[budget / i]

