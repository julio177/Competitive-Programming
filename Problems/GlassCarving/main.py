def main():
    w, h, n = map(int, input().split())
    H = [0, h]
    W = [0, w]
    instructions = []
    for i in range(n):
        x, y = map(str, input().split())
        if x == 'H':
            H.append(int(y))
        else:
            W.append(int(y))
        instructions.append(x + ' ' + y)

    H = sorted(H)
    W = sorted(W)
    hdif = []
    wdif = []
    # Arreglos de diferencias
    for i in range(0, len(H) - 1):
        val = H[i + 1] - H[i]
        hdif.append(val)
    for i in range(0, len(W) - 1):
        val = W[i + 1] - W[i]
        wdif.append(val)

    res = []
    maxh = max(hdif)
    maxw = max(wdif)
    for i in reversed(range(0, len(instructions))):
        res.append(maxh * maxw)
        ins = instructions[i]
        x, y = map(str, ins.split())
        val = int(y)
        if x == 'H':
            index = H.index(val)
            H.pop(index)
            hdif[index - 1] += hdif[index]
            if hdif[index - 1] > maxh:
                maxh = hdif[index - 1]
            hdif.pop(index)
        else:
            index = W.index(val)
            W.pop(index)
            wdif[index - 1] += wdif[index]
            if wdif[index - 1] > maxw:
                maxw = wdif[index - 1]
            wdif.pop(index)
    res = reversed(res)
    for i in res:
        print(i)

main()