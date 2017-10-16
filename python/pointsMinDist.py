import math, random

class Point(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def __str__(self):
        return '('+str(self.x)+','+str(self.y)+')'

def dist(A, B):
    return math.sqrt( (A.x - B.x)**2 + (A.y - B.y)**2 )

def MinDist(vet, N):
    menor = dist(vet[0],vet[1])  
    for i in range(N):
        for j in range(i+1, N):        
            x = dist(vet[i], vet[j])
            if x <= menor:
                a,b,menor = i,j,x
                
    print vet[a], vet[b], menor

                #MinDist(vet, N ,menor, i, j)
                

vet = []
vet.append(Point(1,1))
vet.append(Point(2,2))
vet.append(Point(2,1))
vet.append(Point(3,2))
vet.append(Point(3,1))
vet.append(Point(4,2))

for i in range(len(vet)):
    print vet[i]
MinDist(vet, len(vet))