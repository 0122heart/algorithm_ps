import sys; input = sys.stdin.readline

def main() :
    N = int(input())
    sizes = list(map(int, input().split()))
    T, P = map(int, input().split())

    # 티셔츠 묶음 구하기
    numT = 0
    for i in sizes :
        numT += i // T
        if(i % T) : numT += 1

    # 펜 묶음과 낱개 구하기
    numPBundle = N // P
    numPEach = N % P

    print(numT)
    print(numPBundle, numPEach)
        

main()