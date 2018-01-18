def binary(letters):
    '''Funcion para encontrar un caracter 
    repetido entre pares continuos'''
    low = 0
    high = len(letters) - 1

    while low < high:
        mid = (low + high) / 2
        if letters[mid + 1] == letters[mid] or letters[mid - 1] == letters[mid]:
            if letters[mid + 1] == letters[mid]:
                left = mid
                right = len(letters) - mid - 1
                if left % 2 == 0:
                    low = mid + 2
                else:
                    high = mid - 1
            elif letters[mid - 1] == letters[mid]:
                left = mid - 1
                right = len(letters) - mid
                if left % 2 == 0:
                    low = mid + 1
                else:
                    high = mid - 2
        else:
            return letters[low]

def rotateList(k, linked):
    '''Funcion para rotar una lista ecadenada k espacios'''
    rest = linked.size() - k
    aux = linked.head
    cont = 0

    while cont < rest:
        aux = aux.next
        cont += 1

    tmp = aux.next
    aux.next = None
    while tmp.next != None:
        tmp = tmp.next
    tmp.next = linked.head
    return linked

def removeDuplicate(word):
    '''Funcion para remover caracteres duplicados
    y que solo aparezca una vez cada uno'''
    letters = [False] * 26
    res = ''
    for i in word:
        index = ord(i) - ord('a')
        if not letters[index]:
            res += i
            letters[index] = True
    return res

def removeDuplicate2(word):
    '''Funcion que remueve duplicados y
    da el mejor string lexicografico'''
    letters = [False] * 26
    cont = len(word) - 1
    ranges = []
    # Obtiene donde termina cada rango de letras unicas
    while cont >= 0:
        index = ord(word[cont]) - ord('a')
        if not letters[index]:
            ranges.append(cont)
            letters[index] = True
        cont -= 1
    # Invierte lista con indices de los rangos
    ranges = ranges[::-1]
    cont = 0 # Contador para rangos
    res = '' # String resultado
    included = [False] * 26 # Arreglo de caracteres ya incluidos
    for i in ranges:
        best = word[cont]
        # itera rango no inclusivo con tope
        for j in range(cont, i):
            if ord(word[j]) < ord(best):
                best = word[j]
        # Incluir la mejor opcion
        if not included[ord(best) - 'a']:
            included[ord(best) - 'a'] = True
            res += best
        # Incluir la ultima instancia de esa letra si no se ha incluido
        if not included[ord(i) - 'a']:
            included[ord(i) - 'a'] = True
            res += i
        # Aumenta contador para rangos de letras
        cont = i + 1
    return res
