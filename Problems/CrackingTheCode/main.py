# http://codeforces.com/problemset/problem/630/L
def main():
    num = input()
    new_num = num[0] + num[2] + num[4] + num[3] + num[1]
    num = int(new_num)
    num = num ** 5
    print(num % 100000)

main()