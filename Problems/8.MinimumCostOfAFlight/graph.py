from collections import defaultdict

# Graph is represented using adjacency list. Every
# node of adjacency list contains vertex number of
# the vertex to which edge connects and weight
# (vertex, weight)
class Graph:
	def __init__(self, vertices):
		# No. of vertices
		self.V = vertices
		self.graph = defaultdict(list)

	# Function to add an edge to graph
	def addEdge(self, u, v, w):
		self.graph[u].append((v, w))


	# A recursive function used by shortestPath
	def topologicalSortUtil(self, v, visited, stack):

		# Mark the current node as visited.
		visited[v] = True

		# Recur for all the vertices adjacent to this vertex
		if v in self.graph.keys():
			for node, weight in self.graph[v]:
				if visited[node] == False:
					self.topologicalSortUtil(node, visited, stack)

		# Push current vertex to stack which stores topological sort
		stack.append(v)

	''' The function to find shortest paths from given vertex.
		It uses recursive topologicalSortUtil() to get topological
		sorting of given graph.'''
	def shortestPath(self, s, d):

		# Mark all the vertices as not visited
		visited = [False] * self.V
		stack =[]

		# Call the recursive helper function to store Topological
		# Sort starting from source vertice
		for i in range(self.V):
			if visited[i] == False:
				self.topologicalSortUtil(s, visited, stack)

		# Initialize distances to all vertices as infinite and
		# distance to source as 0
		dist = [float("Inf")] * (self.V)
		dist[s] = 0

		# Process vertices in topological order
		while stack:

			# Get the next vertex from topological order
			i = stack.pop()

			# Update distances of all adjacent vertices
			for node, weight in self.graph[i]:
				if dist[node] > dist[i] + weight:
					dist[node] = dist[i] + weight

		# Print the calculated shortest distances
		print ("%d" %dist[d]) if dist[d] != float("Inf") else "Inf" ,

def main():
	sizes = raw_input()
	sizes = sizes.split()
	M = int(sizes[0])
	N = int(sizes[1])
	matrix = Graph(M)

	for i in range(0, N):
		line = raw_input()
		line = line.split()

		origin = int(line[0]) - 1
		destination = int(line[1]) - 1
		val = int(line[2])
		matrix.addEdge(origin, destination, val)

	pair = raw_input()
	pair = pair.split()
	origin, destination = int(pair[0]) - 1, int(pair[1]) - 1
	matrix.shortestPath(origin, destination)

main()