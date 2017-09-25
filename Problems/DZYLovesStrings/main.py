# http://codeforces.com/problemset/problem/447/B
def main():
    s = str(input())
    k = int(input())
    values = list(map(int, input().split()))
    letters = "abcdefghijklmnopqrstuvwxyz"
    val_sort = sorted(values)
    vald = {}
    for i in range(0, 26):
        vald[letters[i]] = values[i]
    acum = 0
    last = 1
    for i in range(len(s)):
        acum += (last) * vald[s[i]]
        last += 1
    # Calculo de sumatorias
    n = len(s) + k
    sum1 = int((n * (n + 1))/2)
    n = len(s)
    sum2 = int((n * (n + 1))/2)
    # Rango que nos interesa
    dif =  sum1 - sum2
    acum += dif * val_sort[-1]
    print(acum)

main()