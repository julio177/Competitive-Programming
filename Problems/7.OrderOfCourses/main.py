from collections import deque
from collections import defaultdict

def kahn_topsort(graph):
	degree = {}

	for i in graph.keys():
		degree[i] = 0

	# determine degree of connections
	for i in graph.keys():
		for v in graph[i]:
			degree[v] += 1

	Q = deque()

	# Get nodes with zero degree
	for i in degree:
		if degree[i] == 0:
			Q.appendleft(i)

	nodes = []

	while Q:
		node = Q.pop()
		nodes.append(node)

		for v in graph[node]:
			degree[v] -= 1
			if degree[v] == 0:
				Q.appendleft(v)

	if len(nodes) == len(graph):
		return nodes
	# if there is a cycle
	# then return an empty list
	else:
		return []

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

	results = kahn_topsort(matrix)

	for i in results:
		print(i) ,
	
main()