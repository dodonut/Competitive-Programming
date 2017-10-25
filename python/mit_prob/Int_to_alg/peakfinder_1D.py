import math
import random


def peakfinder_linear(vet):
    for i in range(len(vet)):
        if i != 0 and i != len(vet) - 1:
            print i, vet[i - 1], vet[i], vet[i + 1]
            if vet[i] >= vet[i - 1] and vet[i] >= vet[i + 1]:
                return i
        else:
            if i == 0:
                if vet[i] >= vet[i + 1]:
                    return i
            else:
                return i


def peakfinder_binSearch(vet, pi, pf):
    if pi != pf:
        m = (pi + pf) / 2
        # print 'm->', m, 'pi->', pi, 'pf->', pf, '|', vet[m - 1], vet[m], vet[m + 1]
        if vet[m] >= vet[m - 1] and vet[m] >= vet[m + 1]:
            return m
        elif vet[m] < vet[m + 1]:
            return peakfinder_binSearch(vet, m + 1, pf)
        return peakfinder_binSearch(vet, pi, m)
    return pi


def test_peakfinder():
    vet = []
    r = range(10)
    for i in r:
        vet.append(random.choice(r))
    print vet
    i = peakfinder_binSearch(vet, 0, len(vet) - 1)
    j = peakfinder_linear(vet)
    print 'BinSearch:', i, vet[i - 1], vet[i], vet[i + 1]
    print 'Linear:', j, vet[j - 1], vet[j], vet[j + 1]


def sim_test_peakfinder(numTrials):
    for i in range(numTrials):
        test_peakfinder()
        print '\n'


sim_test_peakfinder(10)
