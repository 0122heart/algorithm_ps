import sys; input = sys.stdin.readline

heights = [int(input()) for _ in range(9)]
heights.sort()
total = sum(heights)

def main() :
    for i in range(8) :
        for j in range(i + 1, 9) :
            if(total - heights[i] - heights[j] == 100) :
                result = heights[:i] + heights[i+1:j] + heights[j+1:]
                break
    
    for i in result :
        print(i)


main()