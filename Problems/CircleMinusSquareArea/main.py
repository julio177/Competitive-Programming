from math import acos
pi = acos(0) * 2.0
n = int(raw_input())
for i in range(0, n):
	radius = int(raw_input())
	circle = pi * radius * radius
	square = (2 * radius)**2 / 2
	print "{0:0.2f}".format(circle - square)