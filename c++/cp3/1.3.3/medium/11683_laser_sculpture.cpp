#include <iostream>
using namespace std;
int main()
{
  int A, C;
  int i, ht, last, temp;
  while(cin >> A >> C, A)
  {
    ht = 0;
    last = A;
    for(i = 0; i < C; i++)
    {
      cin >> temp;
      if(temp < last)
      {
        ht += last - temp;
      }
      last = temp;
    }
    cout << ht << endl;
  }
  return 0;
}
