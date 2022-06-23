#ifndef _BOOKS_H_
#define _BOOKS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EPS 0.001
#define COUNT_BOOKS 30

typedef struct
{
    char title[151];
    char author[101];
    unsigned pageCount;
    double price;
} book;

typedef struct s_node
{
    book data;
    struct s_node *next;
} listNode;

int randint(int,int);
double randReal(double,double);
char* randomName(char*);

void printBooks_arr(book *);

void push_front(listNode **, book);
book pop_front(listNode **);
void clearList(listNode **);

listNode *sortedMerge(listNode *, listNode *, int (*)(const void*, const void*));
void split(listNode *, listNode **, listNode **);
void mergeSort(listNode **, int (*)(const void*, const void*));
int cmpPrice(const void*, const void*);

void createBooks_list(listNode **);
void printBooks_list(listNode *);
unsigned numDigits(int);
unsigned numWholeDigits(double);

int cmpTitle(const void *, const void *);

#endif