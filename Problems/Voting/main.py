def min(a, b):
	if a <= b:
		return a
	return b

def main():
	quantity = int(raw_input())
	string = str(raw_input())
	employees = ['Z'] * quantity

	for i in range(0, quantity):
		employees[i] = string[i]

	ptr_d = 0
	ptr_r = 0
	k = 0

	while len(employees) != 1:
		if employees[k] == 'D':
			ptr_d = k

			while employees[k] != 'R' and k < len(employees):
				k += 1
			if k < len(employees):
				ptr_r = k
				employees[k] = 'Z'

		if employees[k] == 'R':
			ptr_r = k

			while employees[k] != 'D':
				k += 1
			if k < len(employees):
				ptr_d = k
				employees[k] = 'Z'

		if employees[k] == 'Z':
			employees.pop(k)
			k -= 1

		print(employees)
		print(k)
		k = min(ptr_r, ptr_d)

	print(employees)

main()