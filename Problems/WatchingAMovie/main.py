# http://codeforces.com/problemset/problem/499/A
def main():
    n, x = map(int, input().split())
    current = 1
    acum = 0
    for i in range(n):
        l, r = map(int, input().split())
        dif = l - current
        div = int(dif / x)
        minu = current + (div * x)
        acum += (r - minu + 1)
        current = r + 1
    print(acum)
main()