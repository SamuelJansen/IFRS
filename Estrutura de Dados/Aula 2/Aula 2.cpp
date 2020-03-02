#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main() {
    FILE *arqtxt;
    char palavra[100];
    int nlinhas=0, c;

    //////////////////////////////////////////////////////////////////////////////////
    /*
    arqtxt = fopen("arquivo.txt", "rt+");
    if (arqtxt == NULL) {
        printf("ERRO na abertura do arquivo!\n");
        exit(1);
    }
    while(!feof(arqtxt)) { //Lê palavra por palavra, até encontrar espaço ou enter
        fscanf(arqtxt, "%s", &palavra);
        printf("%s", palavra);
    }
    */
    //////////////////////////////////////////////////////////////////////////////////
    arqtxt = fopen("arquivo.txt", "rt");
    if (arqtxt == NULL) {
        printf("ERRO na abertura do arquivo!\n");
        exit(1);
    }
    while(EOF != (c = fgetc(arqtxt))) { //Lê palavra por palavra, até encontrar espaço ou enter
        if(c == '\n') {
            nlinhas++;
        }
    }
    printf("Arquivo com %d linhas\n", nlinhas);
    fclose(arqtxt);

    //////////////////////////////////////////////////////////////////////////////////
    /*
    FILE *otherxt;
    nlinhas=0;
    otherxt = fopen("arquivo.txt", "rt");
    if (otherxt == NULL) {
        printf("ERRO na abertura do arquivo!\n");
        exit(1);
    }
    while(fscanf(otherxt,"%c",&c) == 1) { //Lê palavra por palavra, até encontrar espaço ou enter
        if(c == '\n') {
            nlinhas++;
        }
    }
    printf("Arquivo com %d linhas\n", nlinhas);
    system("pause");
    fclose(otherxt);
    */

    return 0;
}
