import random


def BinSearch(vet, pi, pf, x):
    if pi == pf:
        if vet[pi] == x:
            return pi
        return -1
    m = (pi + pf) / 2
    if vet[m] < x:
        return BinSearch(vet, m + 1, pf, x)
    return BinSearch(vet, pi, m, x)


def test_BinSearch(numValues, X):
    vet = []
    for i in range(numValues):
        vet.append(i)
    return BinSearch(vet, 0, len(vet) - 1, X)


def sim_BinSearch(numValues, numTrials):
    for i in range(numTrials):
        r = random.randint(-numValues, numValues)
        pos = test_BinSearch(numValues, r)
        if pos == -1:
            print 'could not find the value ', r, 'on the list'
        else:
            print 'Value ', r, 'is in position', pos


sim_BinSearch(1000, 10)
