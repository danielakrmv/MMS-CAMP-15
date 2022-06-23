#include <stdio.h>
#include "booklib.h"


int main()
{
    book bookArr[COUNT_BOOKS];
    for(int i=0; i < COUNT_BOOKS; i++){
        randomName(bookArr[i].title);
        randomName(bookArr[i].author);
        bookArr[i].pageCount = randint(5, 2000);
        bookArr[i].price = randReal(1.00, 1000.00);
    }

    // write to file
    char filename[100];
    printf("Please enter filename:\n");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "wb");
    fwrite(&bookArr, sizeof(book), COUNT_BOOKS, fp);
    fclose(fp);

    // CHECK IF WE REALLY SAVED TO ARRAY TO A FILE
    book bookArrTest[COUNT_BOOKS];

    fp = fopen(filename, "rb");
    fread(&bookArrTest, sizeof(book), COUNT_BOOKS, fp);

    printBooks_arr(bookArrTest);
    fclose(fp);

    return 0;
}