# http://codeforces.com/problemset/problem/749/B
class Cord(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def print(self):
        print('{0} {1}'.format(self.x, self.y))
    
    def __str__(self):
        return '{0} {1}'.format(self.x, self.y)

def get_point(a, b , c):
    x = a.x - b.x + c.x
    y = c.y - b.y + a.y
    return Cord(x,y)

def main():
    cords = [Cord(0, 0) for i in range(0,3)]
    res = [0 for i in range(0, 6)]
    for i in range(0, 3):
        x, y = map(int, input().split())
        cords[i].x = x
        cords[i].y = y
    res[0] = get_point(cords[0], cords[1], cords[2])
    res[1] = get_point(cords[0], cords[2], cords[1])
    res[2] = get_point(cords[1], cords[2], cords[0])
    res[3] = get_point(cords[1], cords[0], cords[2])
    res[4] = get_point(cords[2], cords[1], cords[0])
    res[5] = get_point(cords[2], cords[0], cords[1])
    
    final = []
    for i in res:
        if len(final) == 0:
            final.append(i)
        else:
            flag = False
            for j in final:
                if i.x == j.x and i.y == j.y:
                    flag = True
                    break
            if not flag:
                final.append(i)
    print(len(final))
    for i in final:
        i.print()
main()