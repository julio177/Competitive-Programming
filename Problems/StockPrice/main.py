def findBestBrute(nums):
    ret = 0
    for i in range(0, len(nums)):
        for j in range(0, len(nums)):
            ret = max(nums[j] - nums[i], ret)
    return ret

def findBestBetter(nums):
    if len(nums) < 2:
        raise IndexError("Too few elements")

    mini = nums[0]
    ret = nums[1] - nums[0]
    for index, val in enumerate(nums):
        if index == 0:
            continue

        ret = max(ret, val - mini)
        mini = min(mini, val)
    return ret


def main():
    stock_price_yesterday = [10, 9, 8, 7, 6, 5]
    # print(findBestBrute(stock_price_yesterday))
    print(findBestBetter(stock_price_yesterday))

main()