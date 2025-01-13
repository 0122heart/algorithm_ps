import sys
input = sys.stdin.readline

def main() :
    N = int(input())
    numList = [0] * 10001

    for i in range(N) :
        numList[int(input())] += 1
    
    for index, value in enumerate(numList) :
        for _ in range(value) :
            print(index)

main()