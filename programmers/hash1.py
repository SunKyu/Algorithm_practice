#https://programmers.co.kr/learn/courses/30/lessons/42576?language=python3
def solution(participant, completion):
    mapping = {}
    answer = ''
    for x in participant:
        if x not in mapping:
            mapping[x] = 1
        else:
            mapping[x] = mapping[x] + 1
    
    for x in completion:
        mapping[x] = mapping[x] - 1
        
    for k in mapping.keys():
        if mapping[k] != 0:
            answer = k
        
    return answer
