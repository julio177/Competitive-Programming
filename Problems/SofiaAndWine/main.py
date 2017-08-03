def main():
	n, a, b, c = map(int, raw_input().split())
	if n % 4 == 0:
		print(0)
		return
	else:
		miss = 4 - n % 4
		if miss == 1:
			print(a)
			return
		elif miss == 2:
			if 2 * a >= b:
				print(2 * a)
			else:
				print(b)
			return
		elif miss == 3:
			x = 3 * a
			y = a + b
			z = c
			if x <= y and x <= z:
				print(x)
				return
			elif y <= x and y <= z:
				print(y)
				return
			else:
				print(z)
				return

main()