import sys

input = sys.stdin.readline

def main() :
    N, M = map(int, input().split())
    numList = [0]
    for i in input().split() :
        numList.append(numList[-1] + int(i))
    for _ in range(M) :
        start, end = map(int, input().split())
        print(numList[end] - numList[start - 1])

main()