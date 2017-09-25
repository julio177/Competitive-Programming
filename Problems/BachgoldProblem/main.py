# http://codeforces.com/problemset/problem/749/A
def main():
    num = int(input())
    first = int(num / 2) - 1
    nums = [2] * first
    resi = num - (first * 2)
    if resi - 2 > 0:
        nums.append(3)
    else:
        nums.append(2)
    print(len(nums))
    for i in nums:
        print(i, end=" ")


main()