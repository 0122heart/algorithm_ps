import sys; input = sys.stdin.readline

def main() :
    N = int(input())
    numDict = {}
    numList = []
    for _ in range(N) :
        tempNum = int(input())
        numList.append(tempNum)
        if(tempNum in numDict) :
            numDict[tempNum] += 1
        else :
            numDict[tempNum] = 1
    
    # 산술 평균 구하기
    print(round(sum(numList) / N))

    # 중앙값
    numList.sort()
    print(numList[N // 2])

    # 최빈값
    maxNum = max(numDict.items(), key = lambda x : x[1])[1]
    maxList = []
    for i in numDict.items() :
        if(i[1] == maxNum) : maxList.append(i[0])
    if(len(maxList) == 1) :
        print(maxList[0])
    else :
        maxList.sort()
        print(maxList[1])

    # 범위
    print(numList[-1] - numList[0])

main()