#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int myFPrintf(int fw, char *str);

int main()
{
    myFPrintf(1, "My fPrintf\n");
    int fp = open("file.txt", O_WRONLY, 0754);
    if (-1 == fp)
    {
        myFPrintf(2, "Error: Can not open the file!\n");
        return -1;
    }
    
    myFPrintf(fp, "My fPrintf in file\n");
    if(-1 == close(fp))
    {
        myFPrintf(2, "Error: Can not close the file!\n");
        return -1;
    }
    return 0;
}

int myFPrintf(int fw, char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        int bytes = write(fw, &str[i], 1);
        if(-1 == bytes)
        {
            return -1;
        }
    }

    return 0;
}