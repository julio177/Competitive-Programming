from __future__ import division

def main():
	nums, goal = map(int, raw_input().split())
	vals = {}

	a = map(int, raw_input().split())

	for i in a:
		x = vals.get(i, 0)
		x += 1
		vals[i] = x

	total = 0
	
	if goal == 0:
		for key, value in vals.iteritems():
			if vals[key] == 2:
				total += 1
			elif vals[key] > 2:
				total += ((vals[key] - 1)*(vals[key]) // 2)
		print(total)
	else:	
		for key in a:
			res = key ^ goal
			total += vals.get(res, 0)
		print(total // 2)

main()
