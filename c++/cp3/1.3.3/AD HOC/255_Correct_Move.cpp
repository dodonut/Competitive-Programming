#include <iostream>
#include <string>
using namespace std;

bool istate(int kp, int qp)
{
    if (kp == qp)
        return true;
    return false;
}

bool imove(int kp, int qp, int qm)
{
    int lowh = ((qm % 8) + 1) * 8;
    int highh = lowh + 7;
    int lowv = qp / 8;
    int highv = 63;
    if (qm == kp)
        return true;
    for (int i = lowh; i < highh; i++)
    {
        if (i == qm)
            return false;
    }
    for (int i = qm; i > lowv; i -= 8)
    {
        if (i == qm)
            return false;
        if (i == kp)
            return true;
    }
    for (int i = qm; i < highv; i += 8)
    {
        if (i == qm)
            return false;
        if (i == kp)
            return false;
    }
    return true;
}

bool moveNotAllowed(int kp, int qp, int qm)
{
    int lowh = (kp % 8 == 0) ? kp : kp - 1;
    int highh = ((kp + 1) % 8 == 0) ? kp : kp + 1;
    int lowv = (kp - 8 < 0) ? kp : kp - 8;
    int highv = (kp + 8 > 63) ? kp : kp + 8;

    if (qm == lowh || qm == lowv || qm == highv || qm == highh)
        return true;
    return false;
}

bool stop(int kp, int qp, int qm)
{
    int dif = abs(kp - qm);
    if (dif == 7 || dif == 9)
        return true;
    return false;
}

string verify(int kp, int qp, int qm)
{
    if (istate(kp, qp))
        return "Illegal state";

    else if (imove(kp, qp, qm))
        return "Illegal move";

    else if (moveNotAllowed(kp, qp, qm))
        return "Move not allowed";

    else if (stop(kp, qp, qm))
        return "Stop";

    else
        return "Continue";
}

int main()
{
    int kp, qp, qm;

    while (cin >> kp >> qp >> qm)
    {
        cout << verify(kp, qp, qm) << endl;
    }
}
