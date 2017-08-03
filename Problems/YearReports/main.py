from collections import OrderedDict
years = {}
n = int(raw_input())
for i in range(0, n):
	a, b = map(int, raw_input().split())
	val = years.get(a, 0)
	val += b
	years[a] = val
res = OrderedDict(sorted(years.items()))
for k, v in res.items():
	print k, v

