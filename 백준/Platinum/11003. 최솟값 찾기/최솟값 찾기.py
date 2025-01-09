import sys
from collections import deque
input = sys.stdin.readline

def main():
    for i in range(the_number_of_nums):
        check_windowx_range(i)
        num = nums[i]
        while(window):    
            top = window[-1][0]
            if num < top:
                window.pop()
            else:
                break
        window.append((num, i))
        print(window[0][0], end = " ")

def check_windowx_range(index):
    if range_of_window <= index - window[0][1]:
        window.popleft()

the_number_of_nums, range_of_window = map(int, input().split())
nums = list(map(int, input().split()))
window = deque()
window.append((10e9, -1))
main()