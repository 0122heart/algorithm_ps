import sys; input = sys.stdin.readline

def main() :
    N = int(input())
    positive = []
    negative = []
    zero = 0
    one = 0
    sumAn = 0

    for _ in range(N) :
        temp = int(input())
        if(1 < temp) :
            positive.append(temp)
        elif(temp < 0) :
            negative.append(temp)
        elif(temp == 1) :
            one += 1
        else :
            zero += 1

    # 정렬
    positive.sort(reverse = True)
    negative.sort()

    # 양수 합 구하기
    # 양수가 홀수개이면면
    if(len(positive) % 2) :
        positive.append(1)

    for i in range(0, len(positive), 2) :
        sumAn += positive[i] * positive[i + 1]

    # 음수 합 구하기
    # 음수가 홀수개이면
    if(len(negative) % 2 and zero) :
        negative.append(0)
    elif(len(negative) % 2 and not zero) :
        negative.append(1)

    for i in range(0, len(negative), 2) :
        sumAn += negative[i] * negative[i + 1]

    print(sumAn + one)


main()