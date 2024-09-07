import sys; input = sys.stdin.readline

def main() : 
    numTests = int(input())
    for test in range(numTests) :
        M, N, x, y = map(int, input().split())
        result = calender(M, N, x, y)
        print(result)

def calender(M, N, x, y) :

    # out of range
    if(M < x or N < y) :
        return -1
    
    candidateOfx = [x + M * i for i in range(N + 1)]

    for tempX in candidateOfx : 
        if(tempX % N == y % N) :
            return tempX
    return -1

main()