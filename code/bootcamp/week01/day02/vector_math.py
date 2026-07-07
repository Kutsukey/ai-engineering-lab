def vector_add(v1,v2):
    if len(v1) == len(v2) and len(v1) != 0:
        i = 0
        res_v = []
        while i < len(v1):
            res_v.append(v1[i]+v2[i])
            i += 1
        return res_v
    else:
        raise ValueError("Vector sizes must be equal.")
    
def scalar_mult(v,x):
    if len(v) != 0:
        res = []
        for e in v:
            res.append(e*x)
        return res
    else:
        raise ValueError("Vector is empty.")

def dot_prod(v1,v2):
    if len(v1) == len(v2) and len(v1) != 0:
        i = 0
        res = 0
        while i < len(v1):
            res += (v1[i]*v2[i])
            i += 1
        return res
    else:
        raise ValueError("Vector sizes must be equal.")


v1 = [1,2,3]
v2 = [3,4,5]

print(vector_add(v1,v2))

print(scalar_mult(v1,5))

print(dot_prod(v2,v1))