import sys
input = sys.stdin.readline

the_num_of_materials = int(input())
target_num = int(input())
materials = list(map(int, input().split()))

materials.sort()
start = 0
end = the_num_of_materials - 1
result = 0

while(start < end):
    now = materials[start] + materials[end]
    if(now < target_num):
        start += 1
    elif(now == target_num):
        result += 1
        start += 1
        end -= 1
    # target_num < now
    else:
        end -= 1

print(result)