import sys; input = sys.stdin.readline

def main() :
    numTest = int(input())
    for _ in range(numTest) :
        M, N, K = map(int, input().split())
        farm, planted = makeFarm(M, N, K)
        print(beforeDfs(farm, planted))

def makeFarm(M, N, K) :
    # 기본적으로 배추가 심어지지 않은 농장 생성
    farm = [[0 for _ in range(M + 2)] for __ in range(N + 2)]
    
    # 배추가 심어진 곳들 리스트
    planted = []

    # 배추가 심어진 곳들을 1로 표기
    for _ in range(K) :
        X, Y = map(int, input().split())
        planted.append((X + 1, Y + 1))
        farm[Y + 1][X + 1] = 1
    return farm, planted

def beforeDfs(farm, planted) :
    safeArea = 0
    while(planted) :
        safeArea += 1
        now = planted[0]
        planted = dfs(farm, now, planted)
    return safeArea

def dfs(farm, now, planted) :
    frontier = []
    while(1) :
        planted.remove(now)
        X = now[0]
        Y = now[1]
        farm[Y][X] = 0
        
        # 4개 방향으로 갈 수 있음
        for tempY, tempX in ((Y + 1, X), (Y - 1, X), (Y, X + 1), (Y, X - 1)) :
            if(farm[tempY][tempX] and (tempX, tempY) not in frontier) :
                frontier.append((tempX, tempY))
    
        # 다음 어디로 갈 지 정함
        if(frontier) :
            now = frontier.pop()       
        else :
            return planted 

main()