def main() :
    N = int(input())
    Pi = list(map(int, input().split()))

    for i in range(1, N) :
        for j in range(i) :
            if(Pi[i] < Pi[j]) :
                Pi = Pi[:j] + [Pi[i]] + Pi[j:i] + Pi[i + 1:]
                break

    total = 0
    for i in range(N) :
        total += sum(Pi[:i]) + Pi[i]

    print(total)

main()