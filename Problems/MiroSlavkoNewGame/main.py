def main():
	tests = int(raw_input())
	maxA = 1
	maxB = 1
	minA = 1000
	minB = 1000
	for i in range(0, tests):
		nums = map(int, raw_input().split())
		a = nums[0]
		b = nums[1]
		if i == 0:
			maxA = a
			maxB = b
			minA = a
			minB = b
			print (a + b)
		else:
			if a > maxA:
				maxA = a
			if a < minA:
				minA = a
			if b > maxB:
				maxB = b
			if b < minB:
				minB = b
			if minA + maxB >= maxA + minB:
				print(minA + maxB)
			else:
				print(maxA + minB)

main()