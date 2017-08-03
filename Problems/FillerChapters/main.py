caps = int(raw_input())
nums = map(int, raw_input().split())
nums = nums[1:]
fillers = len(set(nums))
print(caps - fillers)
