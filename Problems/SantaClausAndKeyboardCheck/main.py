def main():
	s = raw_input()
	t = raw_input()

	if s == t:
		print(0)
		return

	alphabet = 'abcdefghijklmnopqrstuvwxyz'
	pairs = {i: -1 for i in alphabet}
	added = {i: False for i in alphabet}

	for i in range(0, len(t)):
		if pairs[t[i]] == -1 and not added[s[i]]:
			pairs[t[i]] = s[i]
			pairs[s[i]] = t[i]
			added[s[i]] = True
		elif pairs[t[i]] != s[i] and pairs[s[i]] != t[i]:
			print(-1)
			return
	res = ''
	for i in range(0, len(t)):
		res += pairs[t[i]]

	if s != res:
		print(-1)
	else:
		qty = 0
		valid_pairs = []
		added = {i: False for i in alphabet}
		x = 0
		for (key, value) in pairs.iteritems():
			if value != -1 and key != value and not added[key]:
				valid_pairs.append((key, value))
				qty += 1
				added[key] = True
				added[value] = True
			x += 1
		print(qty)
		for i in valid_pairs:
			print("%s %s" % (i[0], i[1]))
	return

main()