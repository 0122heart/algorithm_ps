import sys
input = sys.stdin.readline

N = int(input())
start = end = 1
now = 1
result = 0

while(start <= N):
    if(now < N):
        end += 1
        now += end
    elif(now == N):
        result += 1
        now -= start
        start += 1
        end += 1
        now += end
    # N < now
    else:
        now -= start
        start += 1

print(result)