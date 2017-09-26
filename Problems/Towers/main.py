# http://codeforces.com/problemset/problem/479/B
def main():
    n, k = map(int, input().split())
    towers = list(map(int, input().split()))
    min_index = towers.index(min(towers))
    max_index = towers.index(max(towers))
    dif = towers[max_index] - towers[min_index]
    cant = 0
    operations = []
    while k > 0 and dif > 0:
        if min_index == max_index:
            break
        towers[max_index] -= 1
        towers[min_index] += 1
        operations.append('{0} {1}'.format(max_index + 1, min_index + 1))
        cant += 1
        min_index = towers.index(min(towers))
        max_index = towers.index(max(towers))
        dif = towers[max_index] - towers[min_index]
        k -= 1
    print('{0} {1}'.format(dif, cant))
    for i in operations:
        print(i)
main()