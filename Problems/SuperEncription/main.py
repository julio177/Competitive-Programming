from __future__ import division
def main():
	s = str(raw_input())
	res = ''
	for i in range(0, len(s) // 2):
		res = s[i] + res
	i = len(s) - 1
	if len(s) % 2 != 0:
		res += s[len(s) // 2]
		while i > len(s) // 2:
			res += s[i]
			i -= 1
	else:
		while i >= len(s) // 2:
			res += s[i]
			i -= 1
	print(res)
main()