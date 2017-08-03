from collections import defaultdict

def bipartite(matrix, size, src):
	colors = {}
	for i in matrix.keys():
		colors[i] = -1

	colors[src] = 1

	queue = [src]

	while queue:

		node = queue.pop(0)
		
		for v in matrix[node]:
			if colors[v] == -1:
				colors[v] = 1 - colors[node]
				queue.append(v)
			elif colors[v] == colors[node]:
				return False

	return True

def main():
	sizes = raw_input()
	sizes = sizes.split()
	M = int(sizes[0])
	N = int(sizes[1])
	matrix = defaultdict(list)

	for i in range(1, M + 1):
		matrix[i] = []

	for i in range(N):
		line = raw_input()
		line = line.split()

		origin = int(line[0])
		destination = int(line[1])
		matrix[origin].append(destination)

	if bipartite(matrix, M, 1):
		print('YES')
	else:
		print('NO')

main()