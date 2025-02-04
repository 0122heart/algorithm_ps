N, M = map(int, input().split())

def judge_prime_num(num) :
    if(num == 1) : return 0

    for i in range(2, int(num**0.5)+1) :
        if not(num%i) :
            return 0

    return 1

for i in range(N, M+1) :
    if(judge_prime_num(i)) : print(i)