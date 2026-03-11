typedef struct{
    char **key;
    int *value;
    size_t count;
} Dict;

bool ch_in_key(Dict *dico,const char *ch, size_t *k);

static int ch_to_dict( char mot[], size_t L_mot, Dict *dico, size_t *capacity);