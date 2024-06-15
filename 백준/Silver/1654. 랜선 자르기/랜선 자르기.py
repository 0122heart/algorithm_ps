import sys; input = sys.stdin.readline

K, N = map(int, input().split())
cables = [int(input()) for i in range(K)]

def main() :
    start = 0
    end = max(cables) + 1
    middle = (start + end) // 2
    while(True) :
        numCables = findNumCables(middle)
        if(numCables < N) :
            end = middle
            middle = (start + end) // 2
        elif(N <= numCables and N <= findNumCables(middle + 1)) :
            start = middle
            middle = (start + end) // 2
        else :
            print(middle)
            return


def findNumCables(divisor) : 
    numCables = 0
    for j in cables :
        numCables += j // divisor
    return numCables


main()