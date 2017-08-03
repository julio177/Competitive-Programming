def main():
	a = int(raw_input())
	b = int(raw_input())
	c = int(raw_input())
	
	total = a + b + c
	if a <= 0 or b <= 0 or c <= 0:
		print("Error")
	elif total != 180:
		print("Error")
	else:
		if a == b and b == c:
			print("Equilateral")
		elif a == b and b != c  or a == c and a != b or b == c and c != a:
			print("Isosceles")
		else:
			print("Scalene")
main()