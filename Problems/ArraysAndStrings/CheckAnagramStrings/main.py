'''Determine if two strings are anagrams'''
def check_anagram(stra, strb):
    '''Function to determine if 2 strings are anagrams'''
    stra = stra.lower()
    strb = strb.lower()
    letters = [0] * 26
    for i in stra:
        index = ord(i) - ord('a')
        letters[index] += 1
    for i in strb:
        index = ord(i) - ord('a')
        letters[index] -= 1
        if letters[index] < 0:
            return False
    for i in letters:
        if i != 0:
            return False
    return True

def main():
    '''Main func'''
    cases = int(input())
    for i in range(0, cases):
        sa, sb = input().split()
        print(check_anagram(sa, sb))

main()
