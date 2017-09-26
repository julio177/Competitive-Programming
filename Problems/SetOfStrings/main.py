# http://codeforces.com/problemset/problem/544/A
def main():
    n = int(input())
    s = str(input())
    if n > len(s):
        print('NO')
        return
    else:
        part = int(len(s) / n)
        initial = 0
        print('YES')
        strings = []
        for i in range(0, n):
            strings.append(s[initial:part])
            initial = part
            part += part
        resi = len(s) % n
        if resi > 0:
            strings[-1] = strings[-1] + s[-resi:]
        for i in strings:
            print(i)

main()