def main():
    n = int(input())
    a = list(map(int, input().split()))
    m = int(input())
    b = list(map(int, input().split()))

    sum1, sum2 = 0, 0
    for i in a:
        sum1 += i
    for i in b:
        sum2 += i
    # validar que podemos obtener solucion
    if sum1 != sum2:
        print('NO')
        return
    # guardar instrucciones
    instructions = []
    index = 0
    for i in range(m):
        # valor a conseguir
        t = b[i]
        p1 = index
        p2 = index

        while t > 0:
            t -= a[index]
            if a[p2] < a[index]:
                p2 = index
            index += 1

        if t < 0:
            print('NO')
            return

        if p2 == p1:
            while p2 + 1 < index and a[p2] == a[p2 + 1]:
                p2 = p2 + 1

        flag = 0
        if p2 - 1 >= p1 and a[p2] > a[p2 - 1]:
            flag = 1
        elif p2 + 1 < index and a[p2] > a[p2 + 1]:
            flag = 2
        elif index - p1 == 1:
            continue

        if flag == 0:
            print('NO')
            return
        elif flag == 1:
            for x in range(p2, p1, -1):
                instructions.append('{0} L'.format(x - p1 + i + 1))
            for x in range(p2, index - 1):
                instructions.append('{0} R'.format(i + 1))
        elif flag == 2:
            for x in range(p2, index - 1):
                instructions.append('{0} R'.format(p2 - p1 + i + 1))
            for x in range(p2, p1, -1):
                instructions.append('{0} L'.format(x - p1 + i + 1))

    print('YES')
    for x in instructions:
        print(x)

main()