n = int(raw_input())
anagrams = {}
for i in range(0, n):
	s = raw_input()
	letters = list(s)
	letters = sorted(letters)
	key = ''
	for i in letters:
		key += i
	cant = anagrams.get(key, 0)
	print cant
	cant += 1
	anagrams[key] = cant
