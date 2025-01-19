import sys

def insertion_sort():
    for index in range(the_num_of_people):
        now_time = times[index]
        index -= 1
        while 0 <= index and now_time < times[index]:
            # 삽입할 요소보다 크면 뒤로 미루기
            times[index + 1] = times[index]
            index -= 1
        times[index + 1] = now_time

def make_shortest_time():
    for index in range(1, the_num_of_people):
        times[index] += times[index - 1]

input = sys.stdin.readline
the_num_of_people = int(input())
times = list(map(int, input().split()))

# 오름차순 정렬
insertion_sort()
make_shortest_time()
print(sum(times))