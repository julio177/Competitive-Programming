'''Method to replace spaces in string with %20'''
def replace_spaces(s):
    '''Function to replace spaces with strings'''
    s = list(s)
    for i in range(0, len(s)):
        if s[i] == ' ':
            s[i] = "%20"

    return ''.join(s)

def main():
    '''Main func'''
    cases = int(input())
    for i in range(0, cases):
        s = input()
        print(replace_spaces(s))

main()
