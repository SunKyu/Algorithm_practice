from sys import stdin

N = int(stdin.readline())

m = []
for i in range(N):
    m.append(list(map(lambda x : int(x), stdin.readline().split())))


ans_m1 = 0
ans_0 = 0
ans_1 = 0

def div(s_x, s_y, size,m):
    global ans_m1, ans_0, ans_1
    a = m[s_x][s_y]
    for i in range(s_x, s_x+size):
        for j in range(s_y, s_y+size):
            if(m[i][j] != a):
                ns = int(size/3)
                div(s_x, s_y, ns, m)
                div(s_x, s_y+ns,ns, m )
                div(s_x, s_y+ns+ns,ns, m )
                div(s_x+ns, s_y, ns, m)
                div(s_x+ns, s_y+ns,ns, m )
                div(s_x+ns, s_y+ns+ns,ns, m )
                div(s_x+ns+ns, s_y, ns, m)
                div(s_x+ns+ns, s_y+ns,ns, m )
                div(s_x+ns+ns, s_y+ns+ns,ns, m )
                return
    if a==1:
        ans_1 = ans_1 + 1
    elif a==0:
        ans_0 = ans_0 + 1
    elif a==-1:
        ans_m1 = ans_m1 + 1

div(0, 0, N, m)

print(ans_m1)
print(ans_0)
print(ans_1)

