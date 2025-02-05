'''
10^14 = 10^7^2 = 10,000,000 ^ 2
10^14 = 10^(14/3) = (10 ^ (4 + 2/3)) ^ 2

logic:
number( <= 10^14)가 소수의 n제곱인지 확인해야함
n이 커질수록 소수의 수가 작아질거임 -> n = 2 : 10^7^2 | n = 3 : 10^(14/3)^3 | n = 4 : 10^(7/2)^4 ...

number가 어떤 수의 제곱인지 확인하려면 ~> 10^7 이하인 수에서 소수를 확인
number가 어떤 수의 세제곱인지 확인하려면 ~> 10^(14/3) 이하인 수에서 소수를 확인
number가 어떤 수의 네제곱인지 확인하려면 ~> 10^(7/2) 이하인 수에서 소수를 확인...

우리는 10^7(= 10,000,000) 이하의 수 중에서 소수를 체크하면 됨
10^7 이하의 수가 소수인지 확인하려면 10^(7/2) (= 1000 * 3.xxx)까지의 수로 나눠지는지 확인하면 됨

'''

boundary_min, boundary_max = map(int, input().split())
nums = [True] * 10000001

for i in range(2, int(10000001 ** (1/2)) + 1):
    if nums[i]:
        for j in range(2 * i, 10000001, i):
            nums[j] = False

result = 0

for i in range(2, 10000001):
    if nums[i]:
        temp = i ** 2
        while temp <= boundary_max:
            if boundary_min <= temp:
                result += 1
            temp *= i

print(result)
