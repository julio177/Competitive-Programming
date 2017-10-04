import math
from heapq import heappush, heappop, heapify, _heapify_max

def main():
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    heap = []
    maxsum = 0
    for i in range(len(nums)):
        heappush(heap, (nums[i], i, 0))
        maxsum += nums[i]
    maxd = len(heap) - 1
    _heapify_max(heap)
    print(heap)
    for i in range(0, k):
        # if len(el) > 1:
        #     aux = el[maxd] / el[maxd - 1]
        #     cant = int(math.ceil(math.log2(aux)))
        #     if cant > k:
        #         cant = k
        # print('prev')
        # print(prev)
        el[maxd].val = el[maxd].val - math.ceil(el[maxd].val / 2)
        # print('new')
        # print(el[maxd].val)
        # print('dif')
        dif = prev - el[maxd].val
        # print(dif)
        # print('maxsum')
        # print(maxsum)
        maxsum -= dif
        # print('after')
        # print(maxsum)
        el[maxd].used += 1
        if len(el) > 1 and maxd != 0:
            if el[maxd].val < el[maxd - 1].val:
                maxd = maxd - 1

    print(maxsum)
    
main()