while(True):
    a, b = map(int, input().split())
    if(not a and not b):
        break
    
    if(b < a):
        print("Yes")
    else:
        print("No")