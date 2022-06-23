#include "booklib.h"

int cmpTitle(const void *vbook1, const void *vbook2)
{
    const char *title1 = ((book *)vbook1)->title;
    const char *title2 = ((book *)vbook2)->title;

    return strcmp(title1, title2);
}


void printBooks_arr(book *bookArr)
{
    printf("Title is: %25s ", bookArr->title);
    printf("Author is: %25s ", bookArr->author);
    printf("Pages are: %25u", bookArr->pageCount);
    printf("Price is: %4.2lf\n", bookArr->price);
}

int randint(int min, int max){
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}


char* randomName(char* name){
    unsigned index = 0;
    name[index++] = randint('A', 'Z');
    int n = randint(10, 20);
    for (int i = 0; i < n; i++){
        name[index++] = randint('a', 'z');
    }

    name[index] = '\0';
    return name;
}


listNode *sortedMerge(listNode *left, listNode *right, int (*cmp)(const void *, const void *))
{
    listNode *res_head = NULL;

    if (!left)
    {
        return right;
    }
    else if (!right)
    {
        return left;
    }
    else if (cmp(&(left->data), &(right->data)) <= 0)
    {
        res_head = left;
        res_head->next = sortedMerge(left->next, right, cmp);
    }
    else
    {
        res_head = right;
        res_head->next = sortedMerge(left, right->next, cmp);
    }

    return res_head;
}

void split(listNode *head, listNode **left, listNode **right)
{
    listNode *fast = head, *slow = head;

    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    *left = head, *right = slow->next;
    slow->next = NULL;
}

void mergeSort(listNode **head, int (*cmp)(const void *, const void *))
{
    if (!(*head) || !(*head)->next)
    {
        return;
    }

    listNode *leftHalf = NULL, *rightHalf = NULL;
    split(*head, &leftHalf, &rightHalf);

    mergeSort(&leftHalf, cmp);
    mergeSort(&rightHalf, cmp);

    *head = sortedMerge(leftHalf, rightHalf, cmp);
}

void push_front(listNode **head, book val)
{
    listNode *newnode = (listNode *)malloc(sizeof(listNode));

    newnode->data = val;
    newnode->next = *head;

    *head = newnode;
}

book pop_front(listNode **head)
{
    if (!(*head))
        exit(-1);

    listNode *temp = *head;
    book result = temp->data;
    *head = (*head)->next;

    free(temp);
    return result;
}

void clearList(listNode **head)
{
    while (*head)
    {
        pop_front(head);
    }
}

void createBooks_list(listNode **head)
{
    for (int i = 0; i < COUNT_BOOKS; i++)
    {
        book push_book;

        // generate author - names start with capital letter
        int author_name_length = 10 + rand() % 11;
        push_book.author[0] = 'A' + rand() % ('Z' - 'A' + 1);
        for (int j = 1; j < author_name_length; j++)
        {
            char rand_lowercase = 'a' + rand() % ('z' - 'a' + 1);
            // if we are in the middle of the string start making second name
            if (j == author_name_length / 2)
            {
                push_book.author[j] = ' ';
                push_book.author[j + 1] = 'A' + rand() % ('Z' - 'A' + 1);

                j += 2;
            }
            push_book.author[j] = rand_lowercase;
        }
        push_book.author[author_name_length] = '\0';

        // generate title
        int book_title_length = 10 + rand() % 11;
        push_book.title[0] = 'A' + rand() % ('Z' - 'A' + 1);
        for (int j = 1; j < book_title_length; j++)
        {
            char rand_lowercase = 'a' + rand() % ('z' - 'a' + 1);
            char rand_uppercase = 'A' + rand() % ('Z' - 'A' + 1);
            int random_bit = rand() % 2;

            if (random_bit)
            {
                push_book.title[j] = rand_lowercase;
            }
            else
            {
                push_book.title[j] = rand_uppercase;
            }
        }
        push_book.title[book_title_length] = '\0';

        push_book.pageCount = 5 + rand() % 2001;

        push_book.price = 1 + ((double)rand() / RAND_MAX) * 999;

        push_front(head, push_book);
    }
}

void printBooks_list(listNode *head)
{
    printf("|%*cAuthor%*c|", 7, ' ', 8, ' ');
    printf("%*cTitle%*c|", 8, ' ', 8, ' ');
    printf("%*cPages%*c|", 2, ' ', 3, ' ');
    printf("%*cPrice%*c|", 2, ' ', 3, ' ');
    putchar('\n');
    printf("|%*c|%*c|%*c|%*c|\n", 21, ' ', 21, ' ', 10, ' ', 10, ' ');
    for (int i = 0; i < 67; i++)
        putchar('-');
    putchar('\n');

    listNode *current = head;
    while (current)
    {
        putchar('|');
        printf("%s%*c", current->data.author, 21 - (int)strlen(current->data.author), ' ');
        putchar('|');
        printf("%s%*c", current->data.title, 21 - (int)strlen(current->data.title), ' ');
        putchar('|');
        printf("%u%*c", current->data.pageCount, 10 - numDigits(current->data.pageCount), ' ');
        putchar('|');
        printf("%.2lf%*c", current->data.price, 7 - numWholeDigits(current->data.price), ' ');
        putchar('|');
        putchar('\n');

        current = current->next;
    }
}

unsigned numDigits(int number)
{
    unsigned cnt = 0;
    while (number != 0)
    {
        number /= 10;
        cnt++;
    }

    return cnt;
}

unsigned numWholeDigits(double dNum)
{
    int number = (int)dNum;
    unsigned cnt = 0;
    while (number != 0)
    {
        number /= 10;
        cnt++;
    }

    return cnt;
}