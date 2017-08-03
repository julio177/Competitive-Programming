s = raw_input()
nums = []
for i in s:
	if i != '+':
		nums.append(int(i))
nums.sort()
res = ''
for i in nums:
	res += str(i) + '+'
res = res[:-1]
print(res)