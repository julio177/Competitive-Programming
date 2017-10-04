def main():
    num = int(input())
    b = num // 7 + 1
    while b >= 0:
        a = (num - b * 7)
        if a % 4 == 0 and a >= 0:
            print('4' * (a // 4) + '7' * b)
            return
        b -= 1
    print(-1)
    return
main()