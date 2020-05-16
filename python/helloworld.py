def solution(x, y):
    myset=set(x)

    for num in myset:
        if(y-num in myset):
            return y-num

print(solution([1,2,3,4,5], 6))
