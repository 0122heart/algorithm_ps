import sys; input = sys.stdin.readline

def main() :
    numDivisors = int(input())
    divisors = list(map(int, input().split()))
    print(max(divisors) * min(divisors))

main()