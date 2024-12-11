chess = [input() for i in range(8)]

result = 0
for i in range(8) :
    for j in range(8) :
        if not (i + j) % 2 and chess[i][j] == 'F' :
            result += 1
print(result)