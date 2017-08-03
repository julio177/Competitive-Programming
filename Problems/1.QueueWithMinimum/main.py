def minimun_queue():
	# Lee cantidad de operaciones
	operations_quantity = raw_input()

	# Transforma a int
	operations_quantity = int(operations_quantity)

	# Listas a usar
	numbers = []
	numbers_sorted = []
	erased_numbers = []

	# Ciclo para las operaciones
	for i in range (0, operations_quantity):
		# Lee operacion en turno
		operation = raw_input()

		if operation == '-':
			erased = numbers.pop(0)

			if erased == numbers_sorted[0]:
				numbers_sorted = numbers_sorted[1:]

				if len(numbers_sorted) != 0 and len(erased_numbers) != 0:
					if numbers_sorted[0] == erased_numbers[0]:
						while numbers_sorted[0] == erased_numbers[0]:
							numbers_sorted = numbers_sorted[1:]
							erased_numbers = erased_numbers[1:]

			else:
				erased_numbers.append(erased)
				erased_numbers.sort()

		elif operation == '?':
			print(numbers_sorted[0])

		else:
			operation = operation.split()

			if operation[0] == '+':
				item = int(operation[1])
				numbers.append(item)
				numbers_sorted.append(item)
				numbers_sorted.sort()

minimun_queue()

