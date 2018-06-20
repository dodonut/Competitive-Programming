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
    int lowh = (qp / 8) * 8;
    int highh = lowh + 7;
    int lowv = qp % 8;
    int highv = 56 + lowv;
    if (qm == qp)
        return true;

    if (abs(qm - qp) % 8 == 0)
    {
        if (qm < qp)
        {
            for (int i = qp; i >= lowv; i -= 8)
            {
                if (i == kp)
                    return true;
                if (i == qm)
                    return false;
            }
        }
        else
        {
            for (int i = qp; i <= highv; i += 8)
            {
                if (i == kp)
                    return true;
                if (i == qm)
                    return false;
            }
        }
    }
    else if (abs(qm - qp) < 8)
    {
        if (qm < qp)
        {
            for (int i = qp; i >= lowh; i--)
            {
                if (i == kp)
                    return true;
                if (i == qm)
                    return false;
            }
        }
        else
        {
            for (int i = qp; i <= highh; i++)
            {
                if (i == kp)
                    return true;
                if (i == qm)
                    return false;
            }
        }
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
    if (kp != 0 && kp != 56 && kp != 63 && kp != 7)
        return false;
    int dif = abs(kp - qm);
    if (dif == 7 || dif == 9)
        return true;
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
