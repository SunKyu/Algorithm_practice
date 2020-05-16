from sys import stdin
ans_b = 0
ans_w = 0

def divide(n, x, y):
    color = m[x][y]
    for i in range(x, x+n):
        for j in range(y, y+n):
            if(m[i][j]!=color):
                divide(int(n/2), x, y)
                divide(int(n/2), x+int(n/2), y)
                divide(int(n/2), x, y+int(n/2))
                divide(int (n/2), int(x+n/2), int(y+n/2))
                return
    if color == 1:
        global ans_b 
        ans_b += 1
    else:
        global ans_w
        ans_w += 1

n = int(stdin.readline())
m = []
for i in range(n):
    a = list(map(int, stdin.readline().split()))
    m.append(a)

divide(n, 0, 0)
print(ans_w)
print(ans_b)
