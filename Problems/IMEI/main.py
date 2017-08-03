n = int(raw_input())
for i in range(0, n):
	num = list(raw_input())
	total = 0
	for j in range(0, len(num)):
		if j % 2 == 0:
			# odd pos rel to 1 and duplicate
			# val = int(num[j]) * 2
			# if val >= 10:
			# 	num[j] = str((val / 10) + (val % 10))
			# else:
			# 	num[j] = str(val)
			total += sum(divmod(int(num[j]) * 2, 10))
		else:
			total += int(num[j])
	rem = total % 10
	if rem > 0:
		print 10 - rem
	else:
		print rem
