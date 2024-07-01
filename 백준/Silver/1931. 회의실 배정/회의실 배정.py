import sys; input = sys.stdin.readline

def main() :
    meetings = [list(map(int, input().split())) for _ in range(int(input()))]
    meetings.sort(key = lambda x : (x[1], x[0]))
    now = meetings[0][1]
    numMeetings = 1
    for i in meetings[1:] :
        if(now <= i[0]) :
            numMeetings += 1
            now = i[1]
    print(numMeetings)


main()