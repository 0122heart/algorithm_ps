def dfs(num):    
    for i in (1, 3, 5, 7, 9):
        temp = num * 10 + i

        if temp // (10 ** max_digit):
            print(num)
            return
        
        if is_prime(temp):
            dfs(temp)

def is_prime(num):
    now = 2
    while now * now <= num:
        if num % now == 0:
            return False
        now += 1
    
    return True

max_digit = int(input())
for i in (2, 3, 5, 7):
    dfs(i)