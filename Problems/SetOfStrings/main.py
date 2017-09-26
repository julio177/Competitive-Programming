# http://codeforces.com/problemset/problem/544/A
def main():
    n = int(input())
    s = str(input())
    if n > len(s):
        print('NO')
        return
    elif n == 1:
        print('YES')
        print(s)
    else:
        strings = []
        letters = len(set(list(s)))
        if letters < n:
            print('NO')
            return
        curr = s[0]
        comp = s[0]
        used = {s[0]: 1}
        cant = 0
        for i in range(1, len(s)):
            if s[i] == comp:
                curr += s[i]
            else:
                check = used.get(s[i], -1)
                if check != -1:
                    curr += s[i]
                    if i == len(s) - 1:
                        strings.append(curr)
                        break
                    continue
                else:
                    strings.append(curr)
                    cant += 1
                    if cant == n:
                        strings[-1] = strings[-1] + s[i:]
                        break
                    curr = s[i]
                    comp = s[i]
                    used[comp] = 1
                    if i == len(s) - 1:
                        strings.append(curr)
                        break
        if curr != strings[-1] and cant != n:
            strings.append(curr)
        print('YES')
        for i in strings:
            print(i)
main()