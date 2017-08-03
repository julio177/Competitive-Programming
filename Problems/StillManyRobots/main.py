cases = int(raw_input())
for i in range(0, cases):
	total_qty = 0
	total_mins = 0
	num = int(raw_input())
	qty = 1
	prev_qty = 1
	while num > 1:
		print('qty = ' + str(qty))
		print('num = ' + str(num))
		total_mins += qty * (num**3)
		print('total_mins = ' + str(total_mins))
		total_qty += qty
		qty = prev_qty * num
		prev_qty = qty
		num -= 1
	total_qty += qty
	print(total_qty, total_mins)
