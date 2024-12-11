lenofnum = int(input())
summ = 0
num = int(input())

for i in range(lenofnum) :
    summ += num%10
    num //= 10

print(summ)