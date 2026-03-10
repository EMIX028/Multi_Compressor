#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
    char *message = malloc(200);

    if (message == NULL){
        return EXIT_FAILURE;
    }

    strcpy(message, "Hello World");
    printf("%s\n",message);
    free(message);

}