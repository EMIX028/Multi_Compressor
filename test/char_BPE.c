#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char **key;
    int *value;
    size_t count;
} Dict;

bool ch_in_key(Dict dico,const char *ch, size_t *k){
    size_t i = 0;
    while (i < dico.count){
        if ( strcmp(ch , dico.key[i])==0){
            *k = i;
            return true;
        }
        ++i;
    }
    return false;
}


int main(void){
    
    size_t capacity = 1;
    char **key = malloc(capacity*sizeof(char *));
    int *value = malloc(capacity*sizeof(int));

    char mot[] = "aqbbaabb";
    size_t L_mot = sizeof(mot)/sizeof(mot[0])-1;
    Dict dico = {key,value,0};
    
    char s[3];
    size_t k;

    
    if( L_mot%2 != 0 ){
        for (size_t i=0; i<L_mot; ++i){
            if ( i != (L_mot-1) ){
                sprintf(s,"%c%c",mot[i],mot[i+1]);
                if (ch_in_key(dico,s,&k)==1){
                    dico.value[k] += 1; 
                }
                else{
                    ++capacity;
                    char **newAllocKey = realloc(dico.key, capacity*sizeof(*dico.key));
                    if (newAllocKey == NULL ){
                        return EXIT_FAILURE;
                    }
                    int *newAllocVal = realloc(dico.value, capacity*sizeof(*dico.value));
                    if (newAllocVal == NULL ){
                        return EXIT_FAILURE;
                    }
                    dico.key = newAllocKey;
                    dico.value = newAllocVal;
                    dico.key[dico.count] = strdup(s);
                    dico.value[dico.count] = 1;
                    dico.count++;
                }
            }
        }
        char lastChar[2] = {mot[L_mot-1], '\0'};
        dico.key[capacity-1] = strdup(lastChar);
        dico.value[capacity-1] = -1;
    }
    else{
        for (size_t i=0; i<L_mot-1; ++i){
            if ( i != (L_mot-1) ){
                sprintf(s,"%c%c",mot[i],mot[i+1]);
                if (ch_in_key(dico,s,&k)==1){
                    dico.value[k] += 1; 
                }
                else{
                    ++capacity;
                    char **newAllocKey = realloc(dico.key, capacity*sizeof(*dico.key));
                    if (newAllocKey == NULL ){
                        return EXIT_FAILURE;
                    }
                    int *newAllocVal = realloc(dico.value, capacity*sizeof(*dico.value));
                    if (newAllocVal == NULL ){
                        return EXIT_FAILURE;
                    }
                    dico.key = newAllocKey;
                    dico.value = newAllocVal;
                    dico.key[dico.count] = strdup(s);
                    dico.value[dico.count] = 1;
                    dico.count++;
                }       
            }
        }
    }

    printf("{");
    for (int i =0; i<dico.count; i++){
        printf("%s : %d, ",dico.key[i],dico.value[i]);
    }
    printf("}\n");

    free(dico.key);
    free(dico.value);

    return EXIT_SUCCESS;
}