#include <stdio.h>
#include "booklib.h"
#include <errno.h>

extern int errno;


listNode *read_list_from_file(FILE *fp)
{
    listNode tempNode;
    listNode *newNode = NULL;

    if(fread(&tempNode, sizeof(listNode), 1, fp))
    {
        newNode = malloc(sizeof(listNode));
        newNode->data = tempNode.data;
        newNode->next = read_list_from_file(fp);
    }
    
    return newNode;
}

int main()
{
    book bookArr[COUNT_BOOKS];

    char i_filename[100], o_filename[100];
    printf("Please enter input filename:\n");
    scanf("%s", i_filename);

    FILE *fp = fopen(i_filename, "rb");
    if(!fp)
    {
        perror("Could not open file");
        return 1;
    }
    fread(&bookArr, sizeof(book), COUNT_BOOKS, fp);
    fclose(fp);

    listNode *head;
    for(int i =0; i <COUNT_BOOKS; i++)
    {
        push_front(&head, bookArr[i]);
    }
    
    mergeSort(&head, cmpTitle);

    printf("Please enter output filename:\n");
    scanf("%s", o_filename);

    fp = fopen(o_filename, "wb");
        
    listNode *current = head;
    while(current)
    {
        fwrite(current, sizeof(listNode), 1, fp);
        current = current->next;
    }
    fclose(fp);

    clearList(&head);

    fp = fopen(o_filename, "rb");

    head = read_list_from_file(fp);

    fclose(fp);


    printBooks_list(head);
    clearList(&head);
    return 0;
}