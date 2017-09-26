# http://codeforces.com/problemset/problem/455/C
class Edge(object):
    def __init__(self):
        self.x = 0
        self.y = 0
        self.next = 0

class Node:
    def __init__(self, pos=0, step=0):
        self.pos = pos
        self.step = step

MAXN = 300010
f = [0 for i in range(0, MAXN)]
dis = [0 for i in range(0, MAXN)]
head = [0 for i in range(0, MAXN)]
e = 0
vis = [False for i in range(0, MAXN)]
vs = [False for i in range(0, MAXN)]
maximum = 0
maxd = 0
father = 0
graph = [Edge() for i in range(0, 2 * MAXN)]

def add(u, v):
    global e
    graph[e].y = v
    graph[e].next = head[u]
    head[u] = e
    e += 1

def find(x):
    if x == f[x]:
        return x
    tmp = find(f[x])
    f[x] = tmp
    return f[x]

def dfs(u, pre, step):
    global maxd, maximum

    f[u] = father
    if step > maxd:
        maxd = step
        maximum = u
    i = head[u]
    while i != -1:
        v = graph[i].y
        i = graph[i].next
        if v == pre:
            continue
        dfs(v, u, step + 1)

def main():
    global e, maxd, father
    N, M, Q = map(int, input().split())
    for i in range(1, N + 1):
        f[i] = i
    e = 0
    for i in range(0, M):
        u, v = map(int, input())
        add(u, v)
        add(v, u)
    for i in range(1, N + 1):
        if f[i] == i:
            father = i
            maxd = -1
            dfs(i, -1, 0)
            maxd = -1
            dfs(maximum, -1, 0)
            dis[i] = maxd
    while Q > 0:
        line = str(input())
        if line[0] == 1:
            x = int(line[2])
            gg = find(x)
            print(dis[gg])
        else:
            x = int(line[2])
            y = int(line[4])
            x = find(x)
            y = find(y)
            if x == y:
                continue
            else:
                f[x] = y
                dis[y] = max(max(dis[x], dis[y]), (dis[x] + 1) / 2 + (dis[y] + 1) / 2 + 1)
        Q -= 1

main()