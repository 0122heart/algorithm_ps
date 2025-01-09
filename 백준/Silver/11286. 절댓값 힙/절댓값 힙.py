import sys
import queue
input = sys.stdin.readline

class AbsNum:
    def __init__(self, num):
        self.num = num
    
    def __lt__(self, other):
        if abs(other.num) == abs(self.num):
            return self.num < other.num
        else:
            return abs(self.num) < abs(other.num) 


def main():
    for i in range(num_execution):
        if cmd := int(input()):
            temp = AbsNum(cmd)
            pq.put(temp)
        else:
            if pq.empty():
                print(0)
            else:
                temp = pq.get().num
                print(temp)

num_execution = int(input())
pq = queue.PriorityQueue()
main()
