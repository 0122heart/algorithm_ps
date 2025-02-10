import sys
import heapq

input = sys.stdin.readline

def main():
    numVertex, numEdge = map(int, input().split())
    startPoint = int(input())
    relation = {i + 1: {} for i in range(numVertex)}
    shortest = {i + 1: float("inf") for i in range(numVertex)}

    # make relation
    for _ in range(numEdge):
        start, end, value = map(int, input().split())
        if end in relation[start]:
            relation[start][end] = min(relation[start][end], value)
        else:
            relation[start][end] = value

    dijkstra(startPoint, relation, shortest)

    for i in range(1, numVertex + 1):
        if shortest[i] == float("inf"):
            print("INF")
        else:
            print(shortest[i])

def dijkstra(startPoint, relation, shortest):
    priority_queue = []
    heapq.heappush(priority_queue, (0, startPoint))
    shortest[startPoint] = 0

    while priority_queue:
        current_distance, current_vertex = heapq.heappop(priority_queue)

        if current_distance > shortest[current_vertex]:
            continue

        for neighbor, weight in relation[current_vertex].items():
            distance = current_distance + weight

            if distance < shortest[neighbor]:
                shortest[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))

main()
