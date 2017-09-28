# http://codeforces.com/problemset/problem/733/C
def main():
    n = int(input())
    a = list(map(int, input().split()))
    f = int(input())
    b = list(map(int, input().split()))
    p1 = len(a) - 1
    p2 = len(b) - 1
    acum = 0
    instructions = []
    while p2 >= 0 and p1 >= 0:
        if a[p1] == b[p2]:
            p1 -= 1
            p2 -= 1
            continue
        # check p1 val
        if p1 == 0 and len(a) > 1:
            # only right
            if a[p1] > a[p1 + 1] and a[p1] + a[p1 + 1] <= b[p2]:
                acum = a[p1] + a[p1 + 1]
                a.pop(0)
                a[0] = acum
                instructions.append('{0} R'.format(p1 + 1))
            else:
                p1 -= 1
        elif p1 == len(a) - 1 and len(a) > 1:
            # only left
            if a[p1] > a[p1 - 1] and a[p1] + a[p1 - 1] <= b[p2]:
                acum = a[p1] + a[p1 - 1]
                a.pop()
                a[-1] = acum
                instructions.append('{0} L'.format(p1 + 1))
            p1 -= 1
        else:
            # both sides
            if len(a) > 1:
                if a[p1] > a[p1 + 1] and a[p1] + a[p1 + 1] <= b[p2]:
                    acum = a[p1] + a[p1 + 1]
                    a.pop(p1 + 1)
                    a[p1] = acum
                    instructions.append('{0} R'.format(p1 + 1))
                    continue
                elif a[p1] > a[p1 - 1] and a[p1] + a[p1 - 1] <= b[p2]:
                    acum = a[p1] + a[p1 - 1]
                    a.pop(p1 - 1)
                    a[p1 - 1] = acum
                    instructions.append('{0} L'.format(p1 + 1))
                p1 -= 1
            else:
                break
    if len(a) == len(b) and a[0] == b[0]:
        print('YES')
        for i in instructions:
            print(i)
    else:
        print('NO')
main()