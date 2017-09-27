# http://codeforces.com/problemset/problem/760/B
def calc(y, x):
    if y > x - 1:
        return int((x * (x - 1))/2) + y - x + 1
    return int(((x - 1 + x - y) * y) / 2)

def main():
    n, m, k = map(int, input().split())
    low = 1
    hi = m
    beds_left = k - 1
    beds_right = n - k
    while low <= hi:
        mid = (low + hi) >> 1
        cant = calc(beds_left, mid) + calc(beds_right, mid)
        comp = m - mid - cant
        if comp < 0:
            hi = mid - 1
        else:
            low = mid + 1
    print(low - 1)

main()