import sys

input = sys.stdin.readline

N = int(input())
An = list(map(int, input().split()))

def main() :
    satisfying = 0
    # 오름차순 정렬
    An.sort()
    for i in range(N) :
        satisfying += isSatisfy(i)
    print(satisfying)

def isSatisfy(i) :
    start, end = 0, N - 1
    target = An[i]

    # 같은 수라면 다른 수로 만들기
    if(start == i) :
        start += 1
    elif(end == i) :
        end -= 1

    while(start < end) :
        sumNumbers = An[start] + An[end]

        if(sumNumbers == target) :
            return 1
        # 작을 때 -> 더 키워야함
        elif(sumNumbers < target) :
            start += 1
        # 클 때 -> 더 줄여야 함
        else :
            end -= 1
            
        # 같은 수라면 다른 수로 만들기
        if(start == i) :
            start += 1
        elif(end == i) :
            end -= 1
    return 0

main()