import sys; input = sys.stdin.readline

def main() :
    numTests = int(input())
    for _ in range(numTests) :
        findStep()

def findStep() :
    ''' 순서 찾는 함수 '''

    # 문서 수, 현재 어디있는지
    numDocuments, now = map(int, input().split())

    # 중요도 받기
    importances = []
    for index, value in enumerate(map(int, input().split())) :
        importances.append((value, index))
    
    printNum = 1
    while(True) :
        for i in importances[1:] :
            if(importances[0][0] < i[0]) :
                importances = importances[1:] + [importances[0]]
                break
        else :
            if(importances[0][1] == now) :
                print(printNum)
                return
            del importances[0]
            printNum += 1

    



main()