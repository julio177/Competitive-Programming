def balanced_stack(s):
	stack = []
	for i in s:
		if i == ')' or i == ']':
			if len(stack) == 0:
				print('NO')
				return

			if i == ')' and stack[len(stack) - 1] != '(':
				print('NO')
				return

			if i == ']' and stack[len(stack) - 1] != '[':
				print('NO')
				return
			else:
				stack.pop()

		if i == '(' or  i == '[':
			stack.append(i)

	if len(stack) != 0:
		print('NO')
		return
		
	print('YES')
	return

my_string = raw_input()
balanced_stack(my_string)