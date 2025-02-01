import sys
from collections import deque

def is_exist_path(start, end):
    if dfs(start, end, set(), deque()):
        print(1, end = " ")
    else:
        print(0, end = " ")

def dfs(start, end, visited, frontier):
    for i in tuple(relation[start]):
        if i not in visited and i not in frontier:
            visited.add(i)
            frontier.append(i)

    if not frontier:    
        return False

    now = frontier.pop()
    if now == end:
        return True
    
    return dfs(now, end, visited, frontier)

num_vertexes = int(input())
relation = {i + 1 : set() for i in range(num_vertexes)}

# 간선이 있는 관계 구축
for i in range(1, num_vertexes + 1):
    neighborhood = [index + 1 for index, value in enumerate(map(int, input().split())) if value]
    for k in neighborhood:
        relation[i].add(k)

for i in range(1, num_vertexes + 1):
    for j in range(1, num_vertexes + 1):
        is_exist_path(i, j)
    print()    