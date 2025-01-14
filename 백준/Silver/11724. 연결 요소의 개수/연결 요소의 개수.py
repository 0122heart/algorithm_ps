import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

numVertex, numEdge = map(int, input().split())
    
# 정점간의 관계
relation = {i + 1:[] for i in range(numVertex)}
    
# 방문 여부
visited = [True] + [False for i in range(numVertex)]
    
# 정점들 사이의 관계 기록
for i in range(numEdge) :
    vertexA, vertexB = map(int, input().split())
    relation[vertexA].append(vertexB)
    relation[vertexB].append(vertexA)

def main() :
    # 연결 요소
    component = 0

    # dfs
    while(False in visited) :
        component += 1
        dfs(visited.index(False))

    # 연결 요소 수 출력
    print(component)

def dfs(now) :
    visited[now] = True
    for i in relation[now] :
        if(visited[i] == False) : dfs(i)     

main()