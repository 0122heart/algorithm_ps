import sys
input = sys.stdin.readline

row_size, the_num_of_add = map(int, input().split())
num_table = [list(map(int, input().split())) for _ in range(row_size)]
sum_table = [[0 for _ in range(row_size + 1)] for __ in range(row_size + 1)]

# 합 배열 구하기
for row in range(1, row_size + 1):
    for col in range(1, row_size + 1): 
        sum_table[row][col] = sum_table[row - 1][col] + sum_table[row][col - 1] - sum_table[row - 1][col - 1] + \
            num_table[row - 1][col - 1]

# add
for add in range(the_num_of_add):
    x1, y1, x2, y2 = map(int, input().split())
    result = sum_table[x2][y2] - sum_table[x1 - 1][y2] - sum_table[x2][y1 - 1] + sum_table[x1 - 1][y1 - 1]
    print(result)
