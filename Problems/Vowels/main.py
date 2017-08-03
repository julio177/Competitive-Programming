s = str(raw_input())
a = 0
e = 0
i = 0
o = 0
u = 0
for x in s:
	if x == 'a' or x == 'A':
		a += 1
	elif x == 'e' or x == 'E':
		e += 1
	elif x == 'i' or x == 'I':
		i += 1
	elif x == 'o' or x == 'O':
		o += 1
	elif x == 'u' or x == 'U':
		u += 1
print a, e, i, o, u