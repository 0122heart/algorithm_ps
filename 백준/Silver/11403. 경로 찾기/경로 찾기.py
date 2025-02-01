import sys
from collections import deque

def is_exist_path(start, end):
    if bfs(start, end):
        print(1, end = " ")
    else:
        print(0, end = " ")

def bfs(start, end):
    visited = set()
    frontier = deque()

    for i in list(relation[start]):
        if i == end:
            return True
        visited.add(i)
        frontier.append(i)

    while frontier:
        now = frontier.popleft()
        for i in list(relation[now]):
            if i not in visited and i not in frontier:
                if i == end:
                    return True
                visited.add(i)
                frontier.append(i)
    
    return False

num_vertexes = int(input())
relation = {}

# 간선이 있는 관계 구축
for i in range(1, num_vertexes + 1):
    neighborhood = [index + 1 for index, value in enumerate(map(int, input().split())) if value]
    relation[i] = neighborhood

for i in range(1, num_vertexes + 1):
    for j in range(1, num_vertexes + 1):
        is_exist_path(i, j)
    print()    