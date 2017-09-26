# http://codeforces.com/problemset/problem/462/A
def check(i, j, mat):
    size = len(mat) - 1
    cant = 0
    # left
    a = j - 1
    if a >= 0:
        if mat[i][a] == 'o':
            cant += 1
    # right
    a = j + 1
    if a <= size:
        if mat[i][a] == 'o':
            cant += 1
    # top
    a = i - 1
    if a >= 0:
        if mat[a][j] == 'o':
            cant += 1
    # bot
    a = i + 1
    if a <= size:
        if mat[a][j] == 'o':
            cant += 1
    return cant

def main():
    n = int(input())
    mat = [['' for x in range(n)] for y in range(n)]
    mat = []
    for i in range(0, n):
        s = str(input())
        mat.append(list(s))
    size = len(mat)
    for i in range(size):
        for j in range(size):
            cant = check(i, j, mat)
            if cant % 2 != 0:
                print('NO')
                return
    print('YES')
    return

main()