// https://www.hackerrank.com/challenges/pointer-in-c/problem


#include <stdio.h>

void update(int *a,int *b) {
   

    int s = *a + *b;
    int d = *a - *b;
    if (d < 0) d = -d;
    *a = s;
    *b = d;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}