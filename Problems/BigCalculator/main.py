def print_nums(numbers):
    nums = ["/--\ /-|  ---\ ---\ |  | /--- /--- ---- /--\ /--\\ ",\
            "|  |   |     |    | |  | |    |       / |  | |  | ",\
            "|  |   |  /--/ ---| \--| \--\ |--\   /  |--| \--| ",\
            "|  |   |  |       |    |    | |  |  /   |  |    | ",\
            "\--/  --- \--- ---/    | ---/ |--/ /    \--/ \--/ "]
    for i in range(5):
        for x in numbers:
            # 0
            if x == "0":
                print(nums[i][0:5], end='')
            # 1
            elif x == "1":
                print(nums[i][5:10], end='')
            # 2
            elif x == "2":
                print(nums[i][10:15], end='')
            # 3
            elif x == "3":
                print(nums[i][15:20], end='')
            # 4
            elif x == "4":
                print(nums[i][20:25], end='')
            # 5
            elif x == "5":
                print(nums[i][25:30], end='')
            # 6
            elif x == "6":
                print(nums[i][30:35], end='')
            # 7
            elif x == "7":
                print(nums[i][35:40], end='')
            # 8
            elif x == "8":
                print(nums[i][40:45], end='')
            # 9
            elif x == "9":
                print(nums[i][45:], end='')
        print("")

def main():
    cases = int(input())
    for i in range(cases):
        a, b = map(int, input().split())
        res = a + b
        res = str(res)
        print_nums(res)

main()
