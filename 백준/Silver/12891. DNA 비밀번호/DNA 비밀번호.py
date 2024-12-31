import sys
input = sys.stdin.readline

def main(): 
    pre_process()
    start = 0
    while(start + length_of_substring < length_of_string):
        delete = dna_string[start]
        need_of_acgt[delete] += 1
        add = dna_string[start + length_of_substring]
        need_of_acgt[add] -= 1
        is_satisfy()
        start += 1
    print(result)

def pre_process():
    # 최초의 구간에서 조건들을 충족하는지 검사
    for index in range(length_of_substring):
        now_dna = dna_string[index]
        need_of_acgt[now_dna] -= 1
    is_satisfy()

def is_satisfy():
    global result
    for need in need_of_acgt.values():
        if(0 < need):
            return False
    result += 1

length_of_string, length_of_substring = map(int, input().split())
dna_string = input().rstrip()
condition_of_acgt = list(map(int, input().split()))
need_of_acgt = {'A':condition_of_acgt[0], 'C':condition_of_acgt[1], 'G':condition_of_acgt[2], 'T':condition_of_acgt[3]}
result = 0
main()