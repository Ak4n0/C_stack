#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
typedef struct t_elem{
    int value;
    struct t_elem *next;
} elem;
 
struct {
    elem *top;
    size_t n_elems;
} stack;
 
void stack_initialize() {
    stack.top = NULL;
    stack.n_elems = 0;
}
 
bool stack_push(int value) {
    elem *e = malloc(sizeof(elem));
    if(!e)
        return false;
    e->value = value;
    e->next = stack.top;
    stack.top = e;
    ++stack.n_elems;
    return true;
}
 
bool stack_pop(int *retval) {
    if(!stack.top)
        return false;
    *retval = stack.top->value;
    elem *aux = stack.top;
    stack.top = stack.top->next;
    free(aux);
    --stack.n_elems;
    return true;
}
 
void stack_drop() {
    int dummy;
    while(stack.top)
        stack_pop(&dummy);
}
 
size_t stack_count() {
    return stack.n_elems;
}
 
//////////////////////////////////////////
 
int main() {
    int value;
    
    stack_initialize();
    stack_push(1);
    stack_push(2);
    stack_push(3);
 
    printf("elements in stack: %zu\n", stack_count());
 
    stack_pop(&value);
 
    printf("value popped: %d\n", value);
    printf("elements in stack: %zu\n", stack_count());
 
    stack_drop();
 
    printf("elements in stack: %zu\n", stack_count());
 
    if(!stack_pop(&value)) {
        puts("*** ERROR: The stack is empty!");
    }
}
