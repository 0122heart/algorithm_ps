from queue import PriorityQueue

class Vertex:
    def __init__(self, vertex_num, distance):
        self.vertex_num = vertex_num
        self.distance = distance

    def __lt__(self, other):
        if self.distance == other.distance:
            return self.vertex_num < other.vertex_num
        return other.distance < self.distance

def find_longest(start):
    frontier = PriorityQueue()
    visited = {start}
    frontier.put(Vertex(start, 0))
    farthest_distance = 0
    farthest_vertex = start

    while not frontier.empty():
        now = frontier.get()
        now_vertex = now.vertex_num
        now_distance = now.distance

        for i in relation[now_vertex]:
            if i not in visited:
                temp_distance = distance[frozenset([now_vertex, i])]
                new_distance = now_distance + temp_distance
                frontier.put(Vertex(i, new_distance))
                visited.add(i)
                
                if farthest_distance < new_distance:
                    farthest_distance = new_distance
                    farthest_vertex = i

    return farthest_vertex

def distance_between_farthest(a, b):
    frontier = PriorityQueue()
    visited = {a}
    frontier.put(Vertex(a, 0))
    now_vertex = a
    
    while now_vertex != b:
        now = frontier.get()
        now_vertex = now.vertex_num
        now_distance = now.distance

        for i in relation[now_vertex]:
            if i not in visited:
                temp_distance = distance[frozenset([now_vertex, i])]
                new_distance = now_distance + temp_distance
                frontier.put(Vertex(i, new_distance))
                visited.add(i)

    return now_distance
                

the_num_of_vertexes = int(input())
relation = {i:[] for i in range(1, the_num_of_vertexes + 1)}
distance = {}

# 관계 및 거리 설정
for i in range(the_num_of_vertexes):
    vertex_a, *target, end_point = list(map(int, input().split()))
    for i in range(len(target) // 2):
        vertex_b = target[2 * i]
        relation[vertex_a].append(vertex_b)
        relation[vertex_b].append(vertex_a)

        temp_distance = target[2 * i + 1]
        between_vertexes = frozenset([vertex_a, vertex_b])
        if between_vertexes not in distance:
            distance[between_vertexes] = temp_distance

one_side = find_longest(1)
the_other_side = find_longest(one_side)
print(distance_between_farthest(one_side, the_other_side))