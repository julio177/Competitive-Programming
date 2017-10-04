# http://codeforces.com/problemset/problem/313/A
def main():
    num = str(input())
    val = int(num)
    if val >= 10:
        print(val)
        return
    else:
        a = list(num)
        b = list(num)
        a.pop()
        b.pop(len(b) - 2)
        res_a = ""
        res_b = ""
        for i in a:
            res_a += i
        for i in b:
            res_b += i
        print(max(int(res_a), int(res_b)))
        return
        # print(a)
        # print(b)



main()