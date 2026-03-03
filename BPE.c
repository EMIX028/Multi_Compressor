#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//#define LEN(tab) (sizeof(tab.key) / sizeof(tab.key[0]))

typedef struct{
    char **key;
    int *value;
    size_t count;
} Dict;

void append(char *key, int value, Dict *var1){
    var1->key[var1->count] = key;
    var1->value[var1->count] = value;
    var1->count +=1;
}

int main(){

    size_t var1Len = 3;
    char *key[] = {"Salut","erkhbd","azuvf"};
    int value[] = {2,1,5};

    Dict var1 = {key,value,var1Len};

    printf("%s -> %d, %d\n",var1.key[0],var1.value[0],var1.count);

    append("aurevoir",4,&var1);
    printf("%d\n",var1.value[3]);

    return EXIT_SUCCESS;
}