def main() :
    nums = list(map(int, list(input())))
    for i in range(len(nums)) :
        temp = nums[i:]
        find = temp.index(max(temp)) + i
        nums[i], nums[find] = nums[find], nums[i]
    for i in nums :
        print(i, end="")


main()