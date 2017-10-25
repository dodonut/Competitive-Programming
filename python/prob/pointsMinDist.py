import math
import random


class Point(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return '(' + str(self.x) + ',' + str(self.y) + ')'

# distance of 2 points


def dist(A, B):
    return math.sqrt((A.x - B.x)**2 + (A.y - B.y)**2)


def MinDist(vet):
    stored = []
    minor = dist(vet[0], vet[1])
    for i in range(len(vet)):
        for j in range(i + 1, len(vet)):
            x = dist(vet[i], vet[j])
            tup = (i, j, x)
            stored.append(tup)
            if x <= minor:
                a, b, minor = i, j, x
    # it may have more than 1 point that has the same distance, so i search in the
    # list of tuples that contains the (positionA, positionB, dist(A,B)) where positionA
    # positionB are indexes for the real list that contains the points
    for i in range(len(stored)):
        if minor == stored[i][2]:
            print vet[stored[i][0]], vet[stored[i][1]], minor


def test_minDist(numPoints):
    vet = []
    for i in range(numPoints):
        x = random.randint(-numPoints, numPoints)
        y = random.randint(-numPoints, numPoints)
        vet.append(Point(x, y))
    MinDist(vet)


test_minDist(50)
