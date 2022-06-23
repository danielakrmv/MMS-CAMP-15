#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define EPS 0.0001
#define COUNT 10

typedef struct Book{
    char title[151];
    char author[101];
    unsigned pages;
    double price;
}Book;


int (*getComparator(int))(const void *, const void *);

int randint(int,int);
double randReal(double,double);
char* randomName(char*);
void createBook(Book*);
void printBook(Book*);
int cmpTitleASC(const void *, const void *);
int cmpTitleDSC(const void *, const void *);
int cmpAuthorASC(const void *, const void *);
int cmpAuthorDSC(const void *, const void *);
int cmpPagesASC(const void *, const void *);
int cmpPagesDSC(const void *, const void *);
int cmpPriceASC(const void *, const void *);
int cmpPriceDSC(const void *, const void *);

void *lsearch(const void *, const void *, size_t, size_t, int (*)(const void *, const void *));

Book books[COUNT];
int main(){
    srand(time(NULL));
    for(int i=0; i < COUNT; i++){
        createBook(books + i);
    }
    printf("enter number of cmp function:\n");
    int n;
    scanf("%d", &n);
    qsort(books, COUNT, sizeof(books[0]), getComparator(n));
    
    for(int i=0; i < COUNT; i++){
        printBook(books + i);
    }

    return 0;
}

void createBook(Book* book){
    Book *b1 = (Book*)book;
    for(int i = 0; i < COUNT; i++){
        randomName(book->title);
        randomName(book->author);
        book->pages = randint(5, 2000);
        book->price = randReal(1.00, 1000.00);
    }
}

int (*getComparator(int n))(const void *, const void *)
{
    switch (n)
    {
    case 1:
        return cmpTitleASC;
        break;
    case 2:
        return cmpTitleDSC;
        break;
    case 3:
        return cmpAuthorASC;
        break;
    case 4:
        return cmpAuthorDSC;
        break;
    case 5:
        return cmpPagesASC;
        break;
    case 6:
        return cmpPagesDSC;
        break;
    case 7:
        return cmpPriceASC;
        break;
    case 8:
        return cmpPriceDSC;
        break;
    default:
        return NULL;
        break;
    }
}

int randint(int min, int max){
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}


char* randomName(char* name){
    // [A-Z][a-z]{5,10} [A-Z][a-z]{5,10}
    // Stanislav Ivanov 
    unsigned index = 0;
    name[index++] = randint('A', 'Z');
    int n = randint(10, 20);
    for (int i = 0; i < n; i++){
        name[index++] = randint('a', 'z');
    }
    name[index++] = ' ';
    n = randint(10, 20);
    name[index++] = randint('A', 'Z');
    for (int i = 0; i < n; i++){
        name[index++] = randint('a', 'z');
    }
    name[index] = '\0';
    return name;
}

int cmpTitleASC(const void *tp1, const void *tp2){
    Book *b1 = (Book*)tp1;
    Book *b2 = (Book*)tp2;
    return strcmp(b1->title, b2->title);
}

int cmpTitleDSC(const void *tp1, const void *tp2){
    Book *b1 = (Book*)tp1;
    Book *b2 = (Book*)tp2;
    return strcmp(b2->title, b1->title);
}

int cmpAuthorASC(const void *tp1, const void *tp2){
    Book *b1 = (Book*)tp1;
    Book *b2 = (Book*)tp2;
    return strcmp(b1->author, b2->author);
}

int cmpAuthorDSC(const void *tp1, const void *tp2){
    Book *b1 = (Book*)tp1;
    Book *b2 = (Book*)tp2;
    return strcmp(b2->author, b1->author);
}

int cmpPagesASC(const void *tp1, const void *tp2){
    Book *b1 = (Book*)tp1;
    Book *b2 = (Book*)tp2;
    return b1->pages - b2->pages;
}

int cmpPagesDSC(const void *tp1, const void *tp2){
    Book *b1 = (Book*)tp1;
    Book *b2 = (Book*)tp2;
    return b2->pages - b1->pages;
}

int cmpPriceASC(const void *tp1, const void *tp2){
    Book *b1 = (Book*)tp1;
    Book *b2 = (Book*)tp2;
    if (fabs(b1->price - b2->price) < EPS){
        return 0;
    } else if (b1->price > b2->price){
        return 1;
    }
    return -1;

}

int cmpPriceDSC(const void *tp1, const void *tp2){
    Book *b1 = (Book*)tp1;
    Book *b2 = (Book*)tp2;
    if (fabs(b1->price - b2->price) < EPS){
        return 0;
    } else if (b1->price < b2->price){
        return 1;
    }
    return -1;

}

void printBook(Book *b){
    printf("Title: %25s ", b->title);
    printf("Author: %25s ", b->author);
    printf("Pages: %4u ", b->pages);
    printf("Price: %4.2lf\n", b->price);
}

