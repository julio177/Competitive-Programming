# Dictionary with keys and lists as default value
from collections import defaultdict

def DFS(g, start):
	visited = set()
	stack = [start]
	previous = -1

	while stack:
		vertex = stack.pop()

		# Check if vertex has been visited
		if vertex not in visited:
			visited.add(vertex)

			# Adds connections of vertex to the stack
			stack.extend(set(g[vertex]))

		else:
			print('YES')
			print('%d %d' % (vertex, previous))
			return

		previous = vertex

	print('NO')
	return

def main():
	vals = raw_input()
	vals = vals.split()
	m = int(vals[0])
	n = int(vals[1])
	graph = defaultdict(list)

	for i in range(0, m):
		pair = raw_input()
		pair = pair.split()
		origin = int(pair[0])
		dest = int(pair[1])
		graph[origin].append(dest)

	DFS(graph, 1)

main()