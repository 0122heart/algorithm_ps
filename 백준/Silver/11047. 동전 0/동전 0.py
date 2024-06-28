import sys; input = sys.stdin.readline

def main() :
    numCoins, target = map(int, input().split())
    coins = []
    for _ in range(numCoins) :
        coin = int(input())
        
        # 조건에 안 맞는 것들 제외
        if(target < coin) :
            continue

        coins.append(coin)

    numNeedCoins = 0
    for i in coins[::-1] :
        numNeedCoins += target // i
        target %= i
        if(target == 0) :
            print(numNeedCoins)
            return


main()