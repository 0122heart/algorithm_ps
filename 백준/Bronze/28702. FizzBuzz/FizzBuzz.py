import sys; input = sys.stdin.readline

def main() :
    first = input().rstrip()
    second = input().rstrip()
    third = input().rstrip()

    if(first.isdigit()) : 
        fizzbuzz(int(first) + 3)
        return
    if(second.isdigit()) :
        fizzbuzz(int(second) + 2)
        return
    if(third.isdigit()) :
        fizzbuzz(int(third) + 1)
        return
    

def fizzbuzz(num) :
    if(num % 15) :
        if(num % 3 == 0) :
            print('Fizz')
        elif(num % 5 == 0) :
            print('Buzz')
        else :
            print(num)
    else :
        print('FizzBuzz')

main()