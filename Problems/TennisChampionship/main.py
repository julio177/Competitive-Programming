# http://codeforces.com/problemset/problem/735/C
def main():
    num = int(input())
    num1 = 1
    num2 = 2
    tmp = 0
    cont = 0
    while tmp <= num:
        tmp = num1 + num2
        num1 = num2
        num2 = tmp
        cont += 1
    print(cont)
main()