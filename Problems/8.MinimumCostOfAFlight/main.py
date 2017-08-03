def Dijkstra(g, index, destination, length):
	visited = set()

	distances = [0 for i in range(0, length)]
	min = 0
	acum = 0
	distances[index] = -1
	visited.add(index)

	while len(visited) != length and destination not in visited:
		for x in range(0, length):
			if g[index][x] != 0:
				if (g[index][x] + min < distances[x]) or distances[x] == 0:
					distances[x] = g[index][x] + min

		min = 100000
		previous = index
		for j in range(0, length):
			if distances[j] < min and distances[j] > 0:
				min = distances[j]
				index = j

		acum += g[previous][index]
		distances[index] = -1

		visited.add(index)

	print(acum)

def main():
	sizes = raw_input()
	sizes = sizes.split()
	M = int(sizes[0])
	N = int(sizes[1])

	# Creates a list containing M lists, each of M items, all set to 0
	matrix = [[0 for x in range(0, M)] for y in range(0, M)]

	for i in range(0, N):
		line = raw_input()
		line = line.split()

		origin = int(line[0]) - 1
		destination = int(line[1]) - 1
		val = int(line[2])
		matrix[origin][destination] = val

	pair = raw_input()
	pair = pair.split()
	origin, destination = int(pair[0]) - 1, int(pair[1]) - 1

	Dijkstra(matrix, origin, destination, M)

main()
