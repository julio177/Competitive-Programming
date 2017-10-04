# http://codeforces.com/problemset/problem/129/A
def main():
    num = int(input())
    nums = list(map(int, input().split()))
    total = sum(nums)
    cant = 0
    for i in nums:
        val = total - i
        if val % 2 == 0:
            cant += 1
    print(cant)

main()