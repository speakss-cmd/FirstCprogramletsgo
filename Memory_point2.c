#include <stdio.h>
#include <stdlib.h>

int var = 24;


void stack(void);

void stack(void) {

    int var = 44;
    printf("Stack address: %p\n", (void*)&var);
}

int main(void){
    int local_var = 12;
    static int static_var = 22;
    volatile int vola_var = 88888;
    float gpa_var = 2.51;
    double pi = 3.14159265358979;
        //with doubles you can store 15-16 digits after decimal


    int *hvar = malloc(sizeof(var));
    *hvar = 77 + local_var;

    printf("Local var address: %p\n", (void*)&local_var);
    printf("Static var addr:%p\n", (void*)&static_var);
    printf("Volatile var addr:%p\n", (void*)&vola_var);
    printf("Your GPA is %.1f\n", gpa_var); //%.1f = show 1 after decimal so .5
    printf("Value of pi is%.15f\n", pi);  
    printf("Heap Variable:%d\n",*hvar);


    stack();

    free (hvar);
    printf("After free, pointer still holds: %p\n", (void*)hvar);
    hvar = NULL;

    return 0;
}