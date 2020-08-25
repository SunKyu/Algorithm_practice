def solution(n, times):
    left = 0;
    right = 0;
    answer = 0
    for x in times:
        right = x if x > right else right
    right = right * n
    
    while left <= right:
        mid = (left + right) // 2
        sum = 0
        for x in times:
            sum = sum + mid // x
        print(sum)    
        if sum >= n:
            answer = mid
            right = mid - 1
        else:
            left = mid + 1
        
    return answer
