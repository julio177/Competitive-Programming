# http://codeforces.com/problemset/problem/548/A
def is_palindrome(s):
    size = len(s)
    if size == 1:
        return True
    half = int(size / 2)
    first = s[0:half]
    second = s[-half:]
    second = second[::-1]
    return first == second

def main():
    s = str(input())
    k = int(input())
    size = len(s)
    if size % k != 0:
        print('NO')
        return
    cant = int(size / k)
    initial = 0
    last = cant
    for i in range(0, k):
        current = s[initial:last]
        flag = is_palindrome(current)
        if not flag:
            print('NO')
            return
        initial = last
        last += cant
    print('YES')

main()