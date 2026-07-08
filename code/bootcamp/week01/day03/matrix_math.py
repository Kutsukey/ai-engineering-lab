def matrix_add(m1,m2):
    result = []
    if len(m1) == len(m2) and len(m1[0]) == len(m2[0]):
        r = 0
        c = 0
        result = [[None for _ in range(len(m1[0]))] for _ in range(len(m1))]
        while r < len(m1):
            while c < len(m1[0]):
                result[r][c] = m1[r][c] + m2[r][c]
                c += 1
            c = 0
            r += 1
        return result

    else:
        raise ValueError("Matrixes must be equal size.")
    

def transpose(m):
    m_T = [[None for _ in range(len(m))] for _ in range(len(m[0]))]
    r = 0 #2 -> 3
    c = 0 #3 -> 2
    while r < len(m):
        while c < len(m[0]):
            m_T[c][r] = m[r][c]
            c +=1
        c = 0
        r += 1

    return m_T

def matrix_multiply(A,B):
    if len(A[0]) != len(B):
        raise ValueError("Invalid matrix dimensions for multiplication.")
    rows_A = len(A)
    cols_A = len(A[0])
    rows_B = len(B)
    cols_B = len(B[0])
    C = [[0 for _ in range(cols_B)] for _ in range(rows_A)]
    r = 0
    c = 0
    m = 0
    while r < rows_A:
        while c < cols_B:
            while m < cols_A:
                C[r][c] += A[r][m] * B[m][c]
                m += 1
            c += 1
            m = 0
        r += 1
        c = 0    
    return C            
    

m1 = [[1,2],[1,2]]
m2 = [[2,3],[2,3]]

print(matrix_add(m1,m2))
print(m1)

mT = [[1,2],[1,2],[1,2]]

print(transpose(mT))

A = [
    [1, 2, 3],
    [4, 5, 6]
]

B = [
    [7, 8],
    [9, 10],
    [11, 12]
]

print(matrix_multiply(A,B))