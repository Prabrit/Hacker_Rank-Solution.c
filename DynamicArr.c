// https://www.hackerrank.com/challenges/dynamic-array-in-c/problem


#include <stdio.h>
#include <stdlib.h>


int* total_number_of_books;


int** total_number_of_pages;
//head--------------->>>>

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);

    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    total_number_of_books = (int *) calloc(sizeof(int), total_number_of_shelves);
    total_number_of_pages = (int **) calloc(sizeof(int *), total_number_of_shelves);

    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);

        if (type_of_query == 1) {
            
            int shelf, pages;
            scanf("%d %d", &shelf, &pages);

            total_number_of_books[shelf]++;
            total_number_of_pages[shelf] = realloc(total_number_of_pages[shelf], sizeof(int *) * total_number_of_books[shelf]);
            total_number_of_pages[shelf][total_number_of_books[shelf] - 1] = pages;

//tail--------------------->>>
} else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }

    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }

    if (total_number_of_pages) {
        free(total_number_of_pages);
    }

    return 0;
}