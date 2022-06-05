 #include <stdio.h>
 #include <stdlib.h>

int add();
int subtraction();
int multiplication();
int division();

int main()
{

    int op;
    do{
        printf("Select an operation:\n");
        printf ("\n 1 Addition  \t \t 2 Subtraction \n 3 Multiplication \t 4 Division \n 5 Square \t \t 6 Square Root \n 7 Exit \n \n Please, Make a choice "); 
        scanf("%d", &op);
    
    switch(op){
        case 1:  
            add(); 
            break; 
              
        case 2:  
            subtraction(); 
            break;  
              
        case 3:  
            multiplication(); 
            break;  
              
        case 4:  
            if(division() == -1){
                printf("Wrong number! You cant do division by zero");
            }else{
                division();
            }
            break;  
                
              
        case 5:  
            exit(0); // It call the exit() function  to exit from the program  
            break; // break the function  
              
        default:  
            printf(" Something is wrong!! ");  
            break;                        
    
    }
    }while (op != 5);

    return 0;
}


int add(){  
    double sum = 0, num;   
    while ((scanf("%lf", &num)) != EOF){
        sum += num;
        fprintf(stdout," Total Sum of the numbers = %lf", sum); 
    }
    return 0;  
}  


int subtraction(){
    double res = 0, num1, num2;
     while ((fscanf(stdin, "%lf %lf", &num1, &num2)) != EOF){
            res = num1 - num2;
            fprintf(stdout,"Result is = %.2lf", res); 
    }
    return 0;
}

int multiplication(){
    double res = 0, num1, num2;
    while ((fscanf(stdin, "%lf %lf", &num1, &num2)) != EOF){
            res = num1 * num2;
      fprintf(stdout,"Result is = %.2lf", res); 
    }
    return 0;
}

int division(){
    double res = 0, num1, num2;
     while ((fscanf(stdin, "%lf %lf", &num1, &num2)) != EOF){
            if(num2 == 0){
                    return -1;
            }
            res = num1 / num2;
      fprintf(stdout,"Result is = %.2lf", res); 
    }
    return 0;
}
