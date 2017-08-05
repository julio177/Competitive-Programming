'''Determine if a string has all unique chars'''

def unique_chars(s):
    '''Function to determine if a string has all unique chars'''
    letters = [0] * 52
    index = 0
    for i in s:
        val = ord(i)
        if val >= 97:
            index = val - ord('a')
        else:
            index = val - ord('A') + 26
        letters[index] += 1
        if letters[index] > 1:
            return False
    return True

def main():
    '''Main func'''
    cases = int(input())
    for i in range(0, cases):
        s = input()
        print(unique_chars(s))

main()
