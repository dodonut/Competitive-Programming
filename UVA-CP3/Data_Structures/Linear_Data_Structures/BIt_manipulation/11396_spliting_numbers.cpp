#include <iostream>
#include <bitset>

int main()
{
    std::bitset<32> a, b;
    unsigned int n;
    int i;
    while (scanf("%ud", &n), n)
    {
        i = 1;
        a.reset();
        b.reset();
        int k = 0;
        while ((1 << i) < n)
        {
            if (k % 2)
                b.set(j, n | (1 << j));
            else
                a.set(j, n | (1 << j));
            k++;
        }
        printf("%ul %ul\n", a.to_ulong(), b.to_ulong());
    }
}