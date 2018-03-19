#include <iostream>
#include <cstring>
int main()
{
  char fword[8], sword[8], cont = 0;
  int guess, high = 11, low = 0, righton = 0;
  while (scanf("%d", &guess) && guess)
  {
    if (cont == 14)
    {
      int p = 0;
    }
    scanf(" %s %s", &fword, &sword);
    if (strcmp(sword, "high") == 0)
    {
      if (guess < high)
        high = guess;
    }
    else if (strcmp(sword, "low") == 0)
    {
      if (guess > low)
        low = guess;
    }
    else
    {
      if (guess >= high || guess <= low || low > high || high < low)
        printf("Stan is dishonest\n");
      else
        printf("Stan may be honest\n");
      high = 11;
      low = 0;
    }
  }
}