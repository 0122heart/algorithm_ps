import sys; input = sys.stdin.readline

def main() :
    while True :
        try :
            num = input().rstrip()
            print(judge(num))
        except :
            break

def judge(num) :
    # 원래 숫자 자릿수만큼 1로 채움
    compare = "1" * len(num)
    num = int(num)

    while(1) :
        # 각 자리에 1만 있는지 비교
        if(int(compare) % num) : 
            compare += "1"
        # 각 자리에 다 1만 있으면
        else :
            return len(compare)


main()