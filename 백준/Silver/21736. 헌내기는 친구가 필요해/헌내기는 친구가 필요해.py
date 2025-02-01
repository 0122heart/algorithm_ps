import sys
from collections import deque

def bfs():
    drow = [1, 0, -1, 0]
    dcol = [0, 1, 0, -1]

    result = 0

    visited = [[True for i in range(col_campus)] for j in range(row_campus)]

    frontier = deque()
    for i in make_candidate(*start):
        temp = campus[i[0]][i[1]]
        if temp == "P":
            result += 1
            frontier.append(i)
        elif temp == "O":
            frontier.append(i)
        
        visited[i[0]][i[1]] = False

    while frontier:
        now = frontier.popleft()
        
        for i in make_candidate(*now):
            if visited[i[0]][i[1]]:
                temp = campus[i[0]][i[1]]
                if temp == "P":
                    result += 1
                    frontier.append(i)
                elif temp == "O":
                    frontier.append(i)
                
                visited[i[0]][i[1]] = False

    return result

def make_candidate(row, col):
    drow = [1, 0, -1, 0]
    dcol = [0, 1, 0, -1]

    result = []

    for i in range(4):
        new_row = row + drow[i]
        new_col = col + dcol[i]
        if 0 <= new_row < row_campus and 0 <= new_col < col_campus:
            result.append((new_row, new_col))

    return result


row_campus, col_campus = map(int, input().split())

campus = []
start = ()
for i in range(row_campus):
    row = input()
    for index, value in enumerate(row):
        if value == "I":
            start = (i, index)
    campus.append(row)

if result := bfs():
    print(result)
else:
    print("TT")