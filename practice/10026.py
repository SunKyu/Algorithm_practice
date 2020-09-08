#https://www.acmicpc.net/problem/10026
from sys import stdin

n = int(stdin.readline())

m = []
vi = [[False for x in range(101)] for i in range(101)]

for i in range(n):
    m.append(stdin.readline().strip())

def bfs(x, y, colors):
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    q = []
    q.append((x, y))
    while(len(q) != 0):
        x, y = q.pop(0)
        for i in range(4):
            nx = x + dx[i] 
            ny = y + dy[i] 
            if vi[nx][ny]:
                continue
            if nx>=0 and nx<n and ny>=0 and ny<n and m[nx][ny] in colors:
                vi[nx][ny] = True
                q.append((nx, ny))


ans = 0
ans2 = 0
for i in range(n):
    for j in range(n):
        if vi[i][j]:
            continue
        bfs(i, j, [m[i][j]])
        ans += 1
vi = [[False for x in range(101)] for i in range(101)]
for i in range(n):
    for j in range(n):
        if vi[i][j]:
            continue
        colors = []
        if m[i][j] == 'R' or m[i][j] == 'G':
            colors = ['R', 'G']
        else:
            colors = [m[i][j]]
        bfs(i, j, colors)
        ans2 += 1



print(ans, ans2)

