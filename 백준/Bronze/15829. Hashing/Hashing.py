import sys; input = sys.stdin.readline

def main() :
    numChars = int(input())
    result = 0
    for index, value in enumerate(input().rstrip()) :
        result += (ord(value) - 96) * (31 ** index) % 1234567891
    result %= 1234567891
    print(result)

main()