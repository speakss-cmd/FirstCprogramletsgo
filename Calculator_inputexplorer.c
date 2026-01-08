#include <stdio.h>


int main (void) {

    double num1 = 0;
    double num2 = 0;
    double calc;
    char op;
    int choice = 1;

    while (choice) {
        printf("Please enter first number:\n");
        scanf("%lf", &num1);

        printf("What operation do you want to use?\n");
        scanf(" %c", &op);
        
               
        if (op == '+'){
            printf("Please enter second number:\n");
            scanf("%lf", &num2);
            calc = num1 + num2;
        }
        else if (op == '-'){
            printf("Please enter second number:\n");
            scanf("%lf", &num2);
            calc = num1 - num2;
        }
        else if (op == '*'){
            printf("Please enter second number:\n");
            scanf("%lf", &num2);
            calc = num1 * num2;
        }
        else if (op == '/'){
            printf("Please enter second number:\n");
            scanf("%lf", &num2);
            if (num2 != 0){
                calc = num1 / num2;
            }
            else {
                printf("Cant divide by zero!\n");
                continue;
            }
        }
        else {
            printf("Unkonwn operator!\n");
            continue;
        }
        printf("Result=%lf\n", calc);
        printf("Number1's memory addr: %p\n", (void*)&num1);
        printf("Number2's memory addr: %p\n", (void*)&num2);
        printf("Results memory addr: %p\n", (void*)&calc);
        printf("Want to do a new calculation? (Yes = 1/No = 0)\n");
        scanf("%d", &choice);
    }
    printf ("Calculator Exited. Goodbye!\n");


    return 0;
}