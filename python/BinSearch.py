def BinSearch(vet, pi, pf, x):
    if pi == pf:
        if vet[pi] == x:
            return pi
        return -1
    m = (pi + pf)/2
    if vet[m] < x:
        return BinSearch(vet, m+1, pf, x)
    return BinSearch(vet, pi, m, x)


vet = [1,2,3,4,5,8,9,15,20]

print BinSearch(vet, 0, len(vet)-1, 56)
print BinSearch(vet, 0, len(vet)-1, 5)