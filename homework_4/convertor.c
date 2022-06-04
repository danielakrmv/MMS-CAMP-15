#include <stdio.h>

int main(){
    int choice = 0;
    unsigned num;
    int input_base, output_base;
    while (choice != 7){
        printf("\nEnter from 1 to 6 option:");
        printf("\n 1 : HEX -> DEC");
        printf("\n 2 : DEC -> HEX");
        printf("\n 3 : OCT -> DEC");
        printf("\n 4 : DEC -> OCT");
        printf("\n 5 : HEX -> OCT");
        printf("\n 6 : OCT -> HEX");
        printf("\n 7: Exit");
        printf("\n Choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                scanf("%x", &num);
                printf("%x(16) = %d(10)\n", num, num);
                break;
            case 2:
                scanf("%d", &num);
                printf("%d(10) = %x(16)\n", num, num);
                break;
            case 3:
                scanf("%o", &num);
                printf("%o(8) = %d(10)\n", num, num);
                break;
            case 4:
                scanf("%d", &num);
                printf("%d(10) = %o(8)\n", num, num);
                break;
            case 5:
                scanf("%x", &num);
                printf("%x(16) = %o(8)\n", num, num);
                break;
            case 6:
                scanf("%o", &num);
                printf("%o(8) = %x(16)\n", num, num);
                break;
            default:
            printf("Wrong command!\n");
        }
    }
    return 0;
}