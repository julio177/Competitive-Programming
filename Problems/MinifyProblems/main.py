import math

class Element(object):
    def __init__(self, val, index):
        self.val = val
        self.index = index
        self.used = 0

def main():
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    els = [Element(0, 0) for i in range(len(nums))]
    maxsum = 0
    for i in range(len(nums)):
        els[i].val = nums[i]
        els[i].index = i
        maxsum += nums[i]
    els = sorted(els, key=lambda x: x.val)
    maxd = len(els) - 1
    for i in range(0, k):
        prev = els[maxd].val
        # print('prev')
        # print(prev)
        els[maxd].val = els[maxd].val - math.ceil(els[maxd].val / 2)
        # print('new')
        # print(els[maxd].val)
        # print('dif')
        dif = prev - els[maxd].val
        # print(dif)
        # print('maxsum')
        # print(maxsum)
        maxsum -= dif
        # print('after')
        # print(maxsum)
        els[maxd].used += 1
        if len(els) > 1 and maxd != 0:
            if els[maxd].val < els[maxd - 1].val:
                maxd = maxd - 1
    els = sorted(els, key=lambda x: x.index)

    print(maxsum)
    for i in els:
        print(i.used, end=" ")
main()