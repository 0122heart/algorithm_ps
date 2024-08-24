'''
풀이 방식 : 
f(A) = A의 약수의 합
g(x) = f(1) + ... + f(x)
우리는 g(x)를 구하고 싶다
f(1) + f(2) + ... + f(x-1) + f(x)에서 
f(1), ... , f(x)는 모두 1을 약수로 가진다
f(1), ... , f(x)는 2의 배수만이 2를 약수로 가진다
f(1), ... , f(x)는 3의 배수만이 3을 약수로 가진다
...
i에 대해 f(1), ... , f(x)는 i의 배수만이 i를 약수로 가진다

'''

import sys; input = sys.stdin.readline

def main() : 
    num = int(input())
    result = 0
    for i in range(1, num + 1) :
        result += num // i * i
    print(result)

main()