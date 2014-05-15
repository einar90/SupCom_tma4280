n = 6

A = [[[] for j in range(n)] for i in range(n)]

for i in range(n):
    for j in range(n):
        if i==j:
            A[i][j] = 2
        elif j==(i-1) or j==(i+1):
            A[i][j] = -1
    print A[i]
