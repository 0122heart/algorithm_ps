def main():
    result = 0

    for index, value in enumerate(S):
        if value == "I":
            if S[index:index + 2 * N + 1] == P_N:
                result += 1

    print(result)

N = int(input())
P_N = "O".join("I" * (N + 1))
len_S = int(input())
S = input()
main()