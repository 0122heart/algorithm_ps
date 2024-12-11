import sys

input = sys.stdin.readline

def main() :
    N, testCase = map(int, input().split())
    matrix = [[0] * (N + 1)]
    for i in range(N) :
        matrix.append([0] + list(map(int, input().split())))
    newMatrix = [[0] * (N + 1) for _ in range(N + 1)]
    
    # 구간 합 구하기
    for i in range(1, N + 1) :
        for j in range(1, N + 1) :
            newMatrix[i][j] = newMatrix[i - 1][j] + newMatrix[i][j - 1] - \
                newMatrix[i - 1][j - 1] + matrix[i][j]
    
    for test in range(testCase) :
        x1, y1, x2, y2 = map(int, input().split())
        print(newMatrix[x2][y2] - newMatrix[x1 - 1][y2] - newMatrix[x2][y1 - 1] + 
              newMatrix[x1 - 1][y1 - 1])
    


main()