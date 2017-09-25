# http://codeforces.com/problemset/problem/447/A
def main():
    d = {}
    p, n = input().split()
    p = int(p)
    n = int(n)
    for i in range(0, n):
        num = int(input())
        val = num % p
        res = d.get(val, -1)
        if res != -1:
            print(i + 1)
            return 
        d[val] = num
    print(-1)
main()