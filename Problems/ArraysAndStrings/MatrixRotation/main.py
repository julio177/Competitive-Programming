'''Write a method to rotate a matrix'''
def matrix_rotation(mat):
    '''Method to rotate a matrix'''

def main():
    '''Main program'''
    n = int(input())
    mat = [[0 for x in range(n)] for y in range(n)]
    for x in range(n):
        line = input()
        line = line.split()
        for y in line:
            mat[x][y] = y

main()
