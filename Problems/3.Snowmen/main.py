def main():
	num = raw_input()
	num = int(num)
	count = 1
	total = 0
	snowmen = {0: (0, 0, 0)}

	for i in range(0, num):
		op = raw_input()
		op = op.split()

		index = int(op[0])
		value = int(op[1])

		if value != 0:
			acum = snowmen[index][2] + value
			snowmen[count] = (index, value, acum)
			total += acum
			print('acumulado: %d, total: %d' % (acum, total))
		else:
			original_index = index
			if snowmen[index][1] == 0:

				while snowmen[index][1] == 0:
					index = snowmen[index][0]
					if index == 0:
						break

			acum = snowmen[index][2] - snowmen[index][1]
			snowmen[count] = (original_index, value, acum)
			total += acum
			print('acumulado: %d, total: %d' % (acum, total))
			
		acum = 0
		count += 1
		
	print(total)

main()