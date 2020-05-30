from sys import stdin

n = int(stdin.readline())

m = []
for i in range(n):
    m.append(stdin.readline().strip())

ans = ""

def div(start_x, start_y, le, m):
    global ans
    b = m[start_x][start_y]
    for i in range(start_x, start_x+le):
        for j in range(start_y, start_y+le):
            if b != m[i][j]:
                les = int(le/2)
                ans +="("
                div(start_x, start_y, les, m)
                div(start_x, start_y+les, les, m)
                div(start_x+les, start_y, les, m)
                div(start_x+les, start_y+les, les, m)
                ans+=")"
                return
    if b=='1':
        ans+='1'
    else:
        ans+= '0'


div(0, 0, n, m)
print(ans)
    
