import sys

input = sys.stdin.readline
the_number_of_nums = int(input())
nums = [(i, int(input())) for i in range(the_number_of_nums)]
nums.sort(key = lambda x : x[1])
max_move = 0
for i in range(the_number_of_nums):
    before_index = nums[i][0]
    if max_move < before_index - i:
        max_move = before_index - i

print(max_move + 1)
