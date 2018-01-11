def format(s):
    punctuations = [',', '.', ';', '(', ')']

    if s[0] in punctuations:
        s = s[1:]
    
    if s[-1] in punctuations:
        s = s[:-1]
    
    if s.endswith('\'s'):
        s = s[:-2]
    return s

def word_cloud(s):
    words = {}

    for line in s:
        curr_words = line.split()
        for i in range(len(curr_words)):
            curr_words[i] = format(curr_words[i])
            
            # case 0
            if curr_words[i] in words:
                words[curr_words[i]] += 1
            # case 1, lowercase version already in dict
            if curr_words[i].lower() in words:
                words[curr_words[i].lower()] += 1
                continue
            
            # case 2, uppercase version already in dict
            elif curr_words[i].capitalize() in words:
                words[curr_words[i]] = 1
                words[curr_words[i]] += words[curr_words[i].capitalize()]
                del words[curr_words.capitalize()]

            else:
                words[curr_words[i]] = 1
            # case 3, not in dict

    print(words)

def main():
    strings = [
        'We came, we saw, we conquered...then we ate Bill\'s (Mille-Feuille) cake.',
        'The bill came to five dollars.'
    ]

    word_cloud(strings)

main()