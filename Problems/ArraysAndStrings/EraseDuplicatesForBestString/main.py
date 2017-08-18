def erase(s):
    alphabet = {}
    letters = "abcdefghijklmnopqrstuvwxyz"
    for i in letters:
        alphabet[i] = 0
    for i in s:
        alphabet[i] += 1
    result = ""
    cont = 0
    for i in s:
        if alphabet[i] > 1 and ord(i) >= ord(s[cont + 1]):
            alphabet[i] -= 1
        else:
            if alphabet[i] > 0:
                result += i
                alphabet[i] = 0
        cont += 1
    print(result)

erase("zzzzacabzbc")
erase('aaabbb')
