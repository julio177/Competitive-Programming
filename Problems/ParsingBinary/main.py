def to_dec_str(n):
	total = 0
	base = 1
	while n:
		num = n % 10
		total += num * base
		base *= 2
		n = int(n / 10)
	return str(total)


s = raw_input()
acum = ''
reading = False
total = 0
for i in s:
	if not reading:
		if i == '1' or i == '0':
			reading = True
		else:
			acum += i
	if reading:
		if i != '1' or i != '0':
			reading = False
			acum += to_dec_str(total)
			total = 0
		else:
			print(total)
			total *= 10
			total += int(i)
print(acum)