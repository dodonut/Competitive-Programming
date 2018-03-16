#include <iostream>
#include <cstring>
int main()
{
  char fword[8], sword[8];
  int guess, high = 11, low = 0, righton = 0;
  while (scanf("%d", &guess) && guess)
  {
    scanf(" %s %s", &fword, &sword);
    if ((strcmp(sword, "high") == 0) && high > guess)
      high = guess;
    else if ((strcmp(sword, "low") == 0) && low < guess)
      low = guess;
    else
    {
      if (guess <= low || guess >= high)
        printf("Stan is dishonest\n");
      else
        printf("Stan may be honest\n");
      high = 11;
      low = 0;
    }
  }
}