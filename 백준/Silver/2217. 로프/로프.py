import sys

def main():
    max_can_try = 0
    for i in range(the_num_of_ropes):
        result = ropes[i] * (i + 1)
        if max_can_try < result:
            max_can_try = result
    
    print(max_can_try)


the_num_of_ropes = int(input())
ropes = [int(input()) for i in range(the_num_of_ropes)]
ropes.sort(reverse = True)
new_ropes = [ropes[0] for i in range(the_num_of_ropes)]
for i in range(1, the_num_of_ropes):
    new_ropes[i] = new_ropes[i - 1] + ropes[i]
main()