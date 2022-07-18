from itertools import count

s = input()
ans = 50000

for step in range(1, len(s)//2+1):
    prev = s[0:step]
    count = 1
    compressed = ""
    for jump in range(step, len(s), step):
        if prev == s[jump:jump+step]:
            count+=1
        else:
            compressed += str(count) + prev if count>2 else prev
            prev = s[jump:jump+step]
            count = 1
    compressed += str(count) + prev if count>2 else prev
    ans = min(ans, len(compressed))

print(ans)
    