def get_min_of_3(a, b, c):
	if a <= b and a <= c:
		return 2
	if b <= a and b <= c:
		return 5
	return 6

def get_min(a, b):
	if a <= b:
		return 2
	return 3

def main():
	numbers = map(int, raw_input().split())
	values = [2, 3, 5, 6]
	availables = {values[i]: numbers[i] for i in range(0,4)}
	total = 0

	first_min = get_min_of_3(availables[2], availables[5], availables[6])
	val = availables[first_min]
	total += 256 * val

	availables[2] -= val
	availables[5] -= val
	availables[6] -= val

	second_min = get_min(availables[2], availables[3])
	val = availables[second_min]
	total += 32 * val

	print(total)
	return

main()