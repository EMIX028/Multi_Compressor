#include <stdio.h>
#include <stdlib.h>

// CECI N'EST PAS MON PROGRAMME, JE L'AI REPRIS POUR TESTER
// THIS IS NOT MY CODE, I TAKE IT FOR SOME TEST



int main(void){
    FILE *in = fopen("input.txt","rb");

    if(in == NULL){
        fprintf(stderr,"impossible d'ouvrir le fichier");
        return EXIT_FAILURE;
    }
    FILE *out = fopen("output.bin","wb");
    
    unsigned char byte;
    while (fread(&byte,1,1,in)==1){
        printf("0x%02X",byte);
        fwrite(&byte,1,1,out);
    }
    fclose(in);
    fclose(out);
    return EXIT_SUCCESS;
}