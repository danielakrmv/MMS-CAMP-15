#include <stdio.h>
#include <string.h>

size_t my_strlen(const char*);
size_t my_strnlen(const char*, size_t);
char* my_strcpy(char*,char*);
char* my_strncpy(char*, char*, size_t);
char* my_strncat(char* destination, const char* src, size_t n);
char* my_strcat(char* destination, const char* source);
int my_strcmp(const char *,const char *);
int my_strncmp(const char *,const char *, size_t);
const char *mystrstr(const char*, const char*);

int main(){
    char dest[30];
    char source[30] = "World!";

    printf("%s\n", my_strcpy(dest, "Hello "));
 
    printf("%lu\n", my_strlen(dest));
    printf("%lu\n", my_strnlen(source, 4));

    printf("%s\n", my_strncat(dest, source, 29));
    printf("%s\n", my_strcat(dest, source));

    printf("%d\n", my_strcmp("Hello", "Hello"));
    printf("%d\n", my_strcmp("Hello", "Hi"));
    
 
    if (my_strcmp(dest, source) > 0) {
        printf("%s", "First string is greater than second one.\n");
    }
    else if (my_strcmp(dest, source) < 0) {
        printf("%s", "First string is less than second one.\n");
    }
    else if(my_strcmp(dest, source) == 0){
        printf("%s", "First string is equal to second.\n");
    }

    const char* p = mystrstr(source, "rld");
    if(p != NULL)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

 
    return 0;
}

size_t my_strlen(const char* destination){
    int i;
    for(i=0; *(destination + i) != '\0'; i++);
    return i;
}

size_t my_strnlen(const char* destination, size_t n){
    int i;
    for(i=0; *(destination + i) != '\0' && i < n; i++);
    return i;
}

char* my_strcpy(char* destination, char* source){
    int i=0;

    for(i=0; source[i] != '\0'; i++){
        destination[i] = source[i];
    }
    destination[i] = '\0';
    return destination;
}

char* my_strncpy(char* destination, char* source, size_t n){
    int i=0;

    for(i=0; source[i] != '\0' && i < n; i++){
        destination[i] = source[i];
    }
    destination[i] = '\0';
    return destination;
}

char* my_strncat(char* destination, const char* source, size_t num)
{
    int i, j;
 
    for (i = 0; destination[i] != '\0'; i++);

    for (j = 0; source[j] != '\0' && j < num; j++) {
        destination[i + j] = source[j];
    }
 
    destination[i + j] = '\0';
    return destination;
}

char* my_strcat(char* destination, const char* source)
{
    int i, j;
 
    for (i = 0; destination[i] != '\0'; i++);

    for (j = 0; source[j] != '\0'; j++) {
        destination[i + j] = source[j];
    }
 
    destination[i + j] = '\0';
    return destination;
}

int my_strcmp(const char * destination, const char * source)
{
    while (*destination)
    {
        if (*destination != *source) {
            break;
        }
 
        destination++;
        source++;
    }
 
    return *(const unsigned char*)destination - *(const unsigned char*)source;
}

int my_strncmp(const char * destination, const char * source, size_t n)
{
    while (*destination && destination < n)
    {
        if (*destination != *source) {
            break;
        }
 
        destination++;
        source++;
    }
 
    return *(const unsigned char*)destination - *(const unsigned char*)source;
}

const char *mystrstr(const char* str1, const char* str2)
{
    int i = 0;

    while(str1[i] != '\0')
    {
        if(str1[i] == str2[0])
        {
            int j = 1;
            while(str2[j] == str1[i + j])
            {
                j++;
            }
            if(str2[j] == '\0')
            {
                return (str1 + i);
            }
        }
        i++;
    }

    return NULL;
}





