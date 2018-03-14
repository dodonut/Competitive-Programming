#include <iostream>
#include <string>
using std::cin;
using std::cout;
int main()
{
  std::ios::sync_with_stdio(false);
  int T, A, B;
  char temp[6];
  std::string code, gen;
  cin >> T;
  while (T--)
  {
    cin >> temp >> A >> B;
    code = temp;
    int c = 1, i, j, ans = 0;
    for (i = 0; i < code.size(); i++)
      c *= 10;
    for (i = c / 10; i < c; i++)
    {
      gen = std::to_string(i);
      int count[10] = {}, qtA = 0, qtB = 0;
      int error = 0;
      for (j = 0; j < code.size(); j++)
      {
        count[gen[j] - '0']++;
        if (gen[j] == '0')
          error = 1;
      }
      if (error)
        continue;
      for (j = 0; j < code.size(); j++)
      {
        if (code[j] == gen[j])
        {
          qtA++;
          count[code[j] - '0']--;
        }
      }
      if (qtA != A)
        continue;
      for (j = 0; j < code.size(); j++)
      {
        if (code[j] != gen[j])
        {
          if (count[code[j] - '0'])
          {
            qtB++;
            count[code[j] - '0']--;
          }
        }
      }
      if (qtA == A && qtB == B)
        ans++;
    }
    printf("%d\n", ans);
  }
}