//I will be learning how to read Memory and use Pointers
/*in C, Variables live at specific memory address - unlike Python
Where Variables hold values
*/
#include <stdio.h>
#include <stdlib.h>


int var =42;
//global variable

void stack(void);

void stack(void){
    int var = 10;
    printf("Stack var address: %p\n", (void*)&var);
} //each time stack runs -> a new stack frame is created

int main (void) {
    int local_var = 5;
    static int static_var = 77;
    const int const_var = 123;
    volatile int volatile_var = 888;
    //stack addresses close together, often above heap addresses

    int *heap_var = malloc(sizeof(int));
    //this is a heap. Memory allocated outside the stack. 
    //You received a pointer but nothing is initialized (idk what this means)
    /*chatgpt says:int *heap_var = malloc(sizeof(int));

This creates two separate things:

┌────────────┐        ┌────────────┐
│ heap_var   │ -----> │ heap memory│
│ (pointer)  │        │ int value  │
└────────────┘        └────────────┘
heap_var lives on the stack

The memory it points to lives on the heap*/
    *heap_var = 99;


    printf("Global addr: %p\n", (void*)&var);
    /*%p a format specifier (print a pointer (memory address))
output is usuall hexadecimal
    %p expects a void*

\n escape sequence or means newline
 &var = "Give me the momory address where var lives"
    &var -> value(42)
    &var -> address (0x7ff...) 
(void*) is a type cast
    %p requires void*
    &var is an int*
    C does not auto convert here - So we say "treat this address as a generic pointer"
    */
    printf("Local address: %p\n", (void*)&local_var);
    //creats local_var stack
    printf("Heap adress: %p\n", (void*)heap_var);
    //The address of the heap memory block. This is the address returned by malloc.
    printf("Heap value: %d\n", *heap_var);
    //The integer stored in heap memory (*heap_var = 99;)
    //*pointer = value at the address
    printf("Pointer variable address: %p\n", (void*)&heap_var);
    //The address of the pointer itself. This is not the heap.
    
    printf("Static address: %p\n", (void*)&static_var);
    //static int -> persistant storage. means it lives for entire program


    printf("Constant address:%p\n", (void*)&const_var);
    //compiler enforces no midification. lives in memory

    printf("Volatile address: %p\n", (void*)&volatile_var);
    //this value changes outside this code - always read it
    //kind of like positions in games must be constantly updated
    //used in Embedded Systems / memory-mapped registers

    stack();


    free(heap_var);
    //memory is no longer yours. the pointer is dangling
    //this is danger

    printf("After free, pointer still holds: %p\n", (void*)heap_var);
    heap_var = NULL;
    //freeing memory does not erase the pointer. you must clear it yourself
    return 0;
}



/*
so, what does this teach me?
this tells me how to identify variables and find their memory addresses
this is not RAM memory address but Virtual memory address
    (important difference)
        bc -> Modern OSes use virtual memory
    my program sees:
        0x7ffd3a2c4abc
    But the CPU + OS translate that to:
    a physical RAM address
    or cache
    or even disk (temporarily)
    This keeps programs:
    isolated
    secure
    crash-resistant


important difference between Heap variables  addr and Local (stack) variable addr
    Local
        created when function is entered
        destroyed when exists
    Heap
        allocated by the heap allocator
        survives function exits
        stays valid until free()
        
Visual map (burn this into your brain)
Virtual Address Space of Your Program
─────────────────────────────────────

0x00000000
│
│  [ Code (.text) ]
│
│  [ Globals (.data / .bss) ]  ← global_var
│
│  [ Heap ]                    ← malloc()
│
│          ↓ grows upward
│
│
│          ↑ grows downward
│  [ Stack ]                   ← local_var, heap_var
│
0xFFFFFFFF   
*/

