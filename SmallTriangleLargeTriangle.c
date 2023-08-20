// https://www.hackerrank.com/challenges/small-triangles-large-triangles/problem


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;



double heron(const triangle *tr)
{
    double p = (tr->a + tr->b + tr->c) / 2.;
    return sqrt(p * (p - tr->a) * (p - tr->b) * (p - tr->c));
}

int cmp(const triangle* tr1, const triangle* tr2)
{
    double s1 = heron(tr1);
    double s2 = heron(tr2);
    if (s1 < s2) return -1;
    else if (s1 > s2) return 1;
	else return 0;

}

void sort_by_area(triangle* tr, int n) {
	
    qsort(tr, n, sizeof(triangle), (int(*)(const void*, const void*)) cmp);
}

int main(){


	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}