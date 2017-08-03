def main():
	values = raw_input()
	i = 1
	
	try:
		while values:
			nums = map(int, values.split())
			a = nums[0]
			b = nums[1]
			c = nums[2]

			if a + b == c:
				res = str(a) + '+' + str(b) + '=' + str(c)
			elif a == b + c:
				res = str(a) + '=' + str(b) + '+' + str(c)
			elif a - b == c:
				res = str(a) + '-' + str(b) + '=' + str(c)
			elif a == b - c:
				res = str(a) + '=' + str(b) + '-' + str(c)
			elif a * b == c:
				res = str(a) + '*' + str(b) + '=' + str(c)
			elif a == b * c:
				res = str(a) + '=' + str(b) + '*' + str(c)
			elif a // b == c:
				res = str(a) + '/' + str(b) + '=' + str(c)
			elif a == b // c:
				res = str(a) + '=' + str(b) + '/' + str(c)
			res = 'Case ' + str(i) + ': ' + res
			print(res)
			i += 1
			values = raw_input()
	except EOFError:
		exit
	
main()