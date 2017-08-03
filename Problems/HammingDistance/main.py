def main():
	n = int(raw_input())
	for i in range(0, n):
		vals = raw_input().split();
		s = list(str(vals[0]))
		d = int(vals[1])
		# Given a bit-string S and an integer D, find the smallest bit-string T
		# Such that length(T) = length(S) and their Hamming(different chars) is exactly D
		if d == 0:
			print('Case #' + str(i + 1) + ': ' + s)
		else:
			flags = [1] * len(s)
			print(flags)
			for pos in range(0, len(s)):
				print(pos)
				if d == 0:
					break
				if s[pos] == '1' and d > 0:
					s[pos] = '0'
					d -= 1
					flags[pos] = 0
			if d > 0:
				pos = len(s) - 1
				while d > 0:
					if flags[pos]:
						s[pos] = '1'
						flags[pos] = 0
						d -= 1
					pos -= 1
			for j in s:
				print j,

main()