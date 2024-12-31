import sys
from collections import deque

input = sys.stdin.readline

def main():
    global target, result

    for now in range(1, length_of_sequence + 1):
        result += '+'
        stack.append(now)
        if(now == target):
            find()

    if(target):
        print("NO")
    else:
        for i in result:
            print(i)

def find():
    global target, result

    while(target_sequence and stack and target == stack[-1]):
        result += '-'
        target = target_sequence.popleft()
        stack.pop()

length_of_sequence = int(input())

# queue 자료구조로 목표 수열을 저장
target_sequence = deque()
for _ in range(length_of_sequence):
    target_sequence.append(int(input()))
target_sequence.append(0)
target = target_sequence.popleft()
stack = []

result = ''
main()