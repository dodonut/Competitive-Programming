#include <iostream>
#include <cmath>
#include <set>

int main()
{
    int t, n, price;
    uint64_t total_paid;

    while (scanf("%d", &t), t)
    {
        total_paid = 0;
        std::multiset<uint64_t> promo;
        while (t--)
        {
            scanf("%d", &n);
            while (n--)
            {
                scanf("%d", &price);
                promo.insert(price);
            }

            promo.erase(promo.begin());
            promo.erase(--promo.end());

            total_paid += (*promo.rbegin() - *promo.begin());
        }

        printf("%llu\n", total_paid);
    }
}