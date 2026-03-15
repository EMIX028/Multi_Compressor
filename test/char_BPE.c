#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "char_BPE_init.h"


int main(void){
    size_t capacity = 1;
    char **key = malloc(capacity*sizeof(char *));
    int *value = malloc(capacity*sizeof(int));

    char mot[] = "agbfk86k8Yakbfqazjvfhjgbkberbnjkedgnegkerjgerjhlnf";

    size_t L_mot = sizeof(mot)/sizeof(mot[0])-1;
    Dict dico = {key, value, 0, capacity};
    
    int res = ch_to_dict(mot,L_mot,&dico);
    if (res == -1){
        fprintf(stderr,"Erreur d'allocation mémoire");
        return EXIT_FAILURE;
    }

    printf("{");
    char **ptr_key = dico.key;
    int *ptr_val = dico.value;
    for (size_t i = 0; i < dico.count; i++) {
        printf("'%s' : %d,", *ptr_key, *ptr_val);
        ++ptr_key;
        ++ptr_val;
    }
    //printf("\n -> %ld\n",dico.capacity);
    //printf("\n -> %ld\n",dico.count);
    printf("}\n");


    for (char **ptr_Key = dico.key; ptr_Key < dico.key + dico.count; ++ptr_Key) {
        free(*ptr_Key);
    }
    free(dico.key);
    free(dico.value);   

    
    return EXIT_SUCCESS;
}


bool ch_in_key(Dict *dico,const char *ch, size_t *k){
    char **ptr_dico = dico->key;
    size_t i = 0;
    while (i < dico->count){
        if ( strcmp(ch , *ptr_dico)==0){
            *k = i;
            return true;
        }
        ++ptr_dico;
        ++i;
    }
    return false;
}


static int ch_to_dict( char mot[], size_t L_mot, Dict *dico){
    char s[3];
    size_t k;

    for (size_t i=0; i<L_mot; ++i){
        //printf("%ld\n",dico->capacity);
        if ( i != (L_mot-1) ){
            sprintf(s,"%c%c",mot[i],mot[i+1]);
            if (ch_in_key(dico,s,&k) == true){
                dico->value[k] += 1; 
            }
            else{
                if (dico->count == dico->capacity){
                    size_t newCapacity = dico->capacity * 2;
                
                    char **newAllocKey = realloc(dico->key, newCapacity*sizeof(*dico->key));
                    int *newAllocVal = realloc(dico->value, newCapacity*sizeof(*dico->value));
                    if (newAllocKey == NULL || newAllocVal == NULL ){
                        fprintf(stderr,"Erreur lors de la réallocation");
                        return -1;
                    }
                    dico->key = newAllocKey;
                    dico->value = newAllocVal;
                    dico->capacity= newCapacity;
                }
                    dico->key[dico->count] = strdup(s);
                    dico->value[dico->count] = 1;
                    dico->count++;
            }
        }
    }
        if( L_mot%2 != 0 ){
            char lastChar[2] = {mot[L_mot-1], '\0'};
            dico->key[dico->count-1] = strdup(lastChar);
            dico->value[dico->count-1] = -1;
        }
return 0;
}