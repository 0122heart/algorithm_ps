import sys; input = sys.stdin.readline
from queue import PriorityQueue

def main() :
    N = int(input())
    
    # 한 묶음이라면
    if(N == 1) :
        print(0)
        return
    
    numCards = PriorityQueue()
    for _ in range(N) :
        numCards.put(int(input()))

    # 어차피 모든 카드 묶음들은 한번씩은 더해져야 함
    now = numCards.get() + numCards.get()
    total = now
    while(not numCards.empty()) :
        numCards.put(now)
        now = numCards.get() + numCards.get()
        total += now

    print(total)
    return

main()