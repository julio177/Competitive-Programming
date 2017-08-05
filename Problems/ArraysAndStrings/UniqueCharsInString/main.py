'''Determine if a string has all unique chars'''

def unique_chars(s):
    '''Function to determine if a string has all unique chars'''
    letters = [0] * 26
    index = 0
    for i in s:
        index = ord('a') - ord(i.lower())
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
