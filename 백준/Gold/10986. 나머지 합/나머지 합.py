import sys
input = sys.stdin.readline

def comb2(num) : 
    return num * (num - 1) // 2

the_number_of_nums, divisor = map(int, input().split())
nums = list(map(int, input().split()))
the_nums_of_reminders = {i:0 for i in range(divisor)}
the_nums_of_reminders[0] += 1
last_reminder = 0

# numA = a * divisor + r1, numA % divisor = r1
# numB = b * divisor + r2, numB % divisor = r2
# numA + numB = (a + b) * divisor + r1 + r2
# (numA + numB) % divisor = (r1 + r2) % divisor
# (numA % divisor + numB % divisor) % divisor = (r1 + r2) % divisor

for num in nums:
    last_reminder = (last_reminder + num % divisor) % divisor
    the_nums_of_reminders[last_reminder] += 1

result = 0
for reminder in the_nums_of_reminders:
    result += comb2(the_nums_of_reminders[reminder])

print(result)