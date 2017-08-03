def main():
	cups = raw_input()
	cups = int(cups)

	values = raw_input()
	values = values.split()

	biggest = 0
	actual = 0
	unempty = False # Turn true when finding unempty

	for i in range(0, cups):
		val = int(values[i])
		if val != 0 and not unempty:
			unempty = True
			actual += 1

		elif val != 0 and unempty:

			actual = 0
			unempty = False

		if val == 0:
			actual += 1

		if actual > biggest:
			biggest = actual

	print(biggest)

main()