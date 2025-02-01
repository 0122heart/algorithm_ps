import sys
import heapq

def main():
    result = 0
    max_heap = []
    jewel_idx = 0

    for limit in limit_of_backpacks:
        # 현재 가방에 담을 수 있는 보석들을 최대 힙에 추가
        while jewel_idx < the_num_of_jewels and info_of_jewels[jewel_idx][0] <= limit:
            weight, value = info_of_jewels[jewel_idx]
            heapq.heappush(max_heap, -value)  # 최대 힙을 위해 음수로 저장
            jewel_idx += 1

        # 가장 가치가 높은 보석 선택
        if max_heap:
            result += -heapq.heappop(max_heap)

    print(result)

# 입력 받기
the_num_of_jewels, the_num_of_backpacks = map(int, sys.stdin.readline().split())

info_of_jewels = [tuple(map(int, sys.stdin.readline().split())) for _ in range(the_num_of_jewels)]
limit_of_backpacks = [int(sys.stdin.readline()) for _ in range(the_num_of_backpacks)]

# 무게 기준 정렬 (작은 무게부터)
info_of_jewels.sort()
limit_of_backpacks.sort()

main()
