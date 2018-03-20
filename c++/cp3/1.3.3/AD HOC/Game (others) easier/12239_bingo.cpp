// #include <cstdio>
// #include <cmath>
// int main()
// {
//   int a, b;
//   bool won;
//   int *num, *match;
//    while (scanf("%d %d", &a, &b) && a && b)
//   {
//     won = true;
//     num = new int[b + 5];
//     match = new int[a + 5];
//     for (int i = 0; i <= a; i++)
//       match[i] = 0;

//     for (int i = 0; i < b; i++)
//       scanf("%d", &num[i]);

//     for (int i = 0; i < b; i++)
//       for (int j = i + 1; j < b; j++)
//         match[(int)std::abs(num[i] - num[j])] = 1;

//     for (int i = 1; i <= a; i++)
//       if (!match[i])
//         won = false;

//     if (won)
//       printf("Y\n");
//     else
//       printf("N\n");

//     delete[] match;
//     delete[] num;
//   }
//   delete match;
//   delete num;
// }

#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
  int N, B;

  while (scanf("%d%d", &N, &B), N)
  {
    vector<int> balls(B);
    vector<bool> able(N + 1, false);

    for (int i = 0; i < B; ++i)
    {
      scanf("%d", &balls[i]);
      for (int j = i - 1; j >= 0; --j)
        able[abs(balls[i] - balls[j])] = true;
    }

    bool valid(true);

    for (int i = 1; i < N + 1; ++i)
      if (!able[i])
        valid = false;

    if (valid)
      printf("Y\n");
    else
      printf("N\n");
  }
}