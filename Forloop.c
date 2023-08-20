// https://www.hackerrank.com/challenges/for-loop-in-c/problem

#include <stdio.h>
#include <string.h>


static const char *digits[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int main()
{
    int c, d;
    scanf("%d\n%d", &c, &d);
  	

    for (int i = c; i <= d; ++i)
    {
        if (i >= 0 && i < 10)
            printf("%s\n", digits[i]);
        else if (i % 2 == 0)
            printf("even\n");
        else
            printf("odd\n");

    }

    return 0;
}