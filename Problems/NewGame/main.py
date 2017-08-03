# rock 2
# scissors 1
# paper 0
# player 0 bianka, 1 will
def getChoice(s, player):
	w = 0
	b = 0
	for i in s:
		if i == 'W': w += 1
		elif i == 'B': b += 1

	if b == 3:
		return 2
	elif w == 3:
		return 1
	else:
		# Bianka
		if player == 0:
			if b == 2 or w == 2:
				return 0
		# Williams
		else:
			if b == 2:
				return 2
			if w == 2:
				return 1

def main():
	b, w = raw_input().split()
	choice_bianka = ''
	choice_will = ''

	bb = getChoice(b, 0)
	wb = getChoice(w, 1)
	if bb == 0 and wb == 1:
		print('Williams won with Scissors')
		print('Bianka lost with Paper')
	elif bb == 0 and wb == 2:
		print('Bianka won with Paper')
		print('Williams lost with Rock')
	elif bb == 1 and wb == 0:
		print('Bianka won with Scissors')
		print('Williams lost with Paper')
	elif bb == 1 and wb == 2:
		print('Williams won with Rock')
		print('Bianka lost with Scissors')
	elif bb == 2 and wb == 1:
		print('Bianka won with Rock')
		print('Williams lost with Scissors')
	elif bb == 2 and wb == 0:
		print('Williams won with Paper')
		print('Bianka lost with Rock')

main()