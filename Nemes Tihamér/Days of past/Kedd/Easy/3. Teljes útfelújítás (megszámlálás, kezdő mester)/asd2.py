N,M=map(int,input().split())
u=[0]*(N+1)
for i in range(M):
    e,v=map(int,input().split())
    for j in range(e,v+1):
        u[j]+=1
    
print(u.count(0))