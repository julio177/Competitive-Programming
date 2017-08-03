a = map(int, raw_input().split(':'))
b = map(int, raw_input().split(':'))
mins_a = a[0] * 60 + a[1]
mins_b = b[0] * 60 + b[1]
total_hours = (mins_a - mins_b) / 60
if total_hours < 0:
	total_hours += 24
total_mins = abs((mins_a - mins_b) % 60)
if total_hours >= 10:
	if total_mins >= 10:
		print(str(total_hours) + ':' + str(total_mins))
	else:
		print(str(total_hours) + ':0' + str(total_mins))
else:
	if total_mins >= 10:
		print('0' + str(total_hours) + ':' + str(total_mins))
	else:
		print('0' + str(total_hours) + ':0' + str(total_mins))
