#include <stdio.h>
#include <stdlib.h>

int main(void){
    size_t capacity = 3;
    int *ptr = malloc(capacity* sizeof(int));
    //printf("%d\n",sizeof(ptr));

    ptr[0] = 12;

    capacity *= 2;
    int *newAlloc = realloc(ptr, capacity*sizeof(*ptr));
    
    if (newAlloc == NULL ){
        return EXIT_FAILURE;
    }

    ptr = newAlloc;
    
    printf("%d, capacité de ptr : %d\n",ptr[0],capacity*sizeof(*ptr));
    
    free(ptr);
    return EXIT_SUCCESS;
}