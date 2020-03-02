#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main() {
    char palavra[100];
    int nlinhas=0;
	char c;

	//////////////////////////////////////////////////////////////////////////////////
	FILE *firstarqtxt;
    firstarqtxt = fopen("arquivo.txt", "rt+");
    if (firstarqtxt == NULL) {
        printf("ERRO na abertura do arquivo!\n");
        exit(1);
    }
    while(!feof(firstarqtxt)) { //L� palavra por palavra, at� encontrar espa�o ou enter
        fscanf(firstarqtxt, "%s", &palavra);
        printf("%s\n", palavra);
    }
    fclose(firstarqtxt);
    
	//////////////////////////////////////////////////////////////////////////////////
    FILE *arqtxt;
    arqtxt = fopen("arquivo.txt", "rt");
    if (arqtxt == NULL) {
        printf("ERRO na abertura do arquivo!\n");
        exit(1);
    }
    while(EOF != (c = fgetc(arqtxt))) { //L� palavra por palavra, at� encontrar espa�o ou enter
        if(c == '\n') {
            nlinhas++;
        }
    }
    printf("Arquivo com %d linhas\n", nlinhas);
    fclose(arqtxt);
    
    //////////////////////////////////////////////////////////////////////////////////
    FILE *otherxt;
    nlinhas=0;
    otherxt = fopen("arquivo.txt", "rt");
    if (otherxt == NULL) {
        printf("ERRO na abertura do arquivo!\n");
        exit(1);
    }
    while(fscanf(otherxt,"%c",&c) == 1) { //L� palavra por palavra, at� encontrar espa�o ou enter
        if(c == '\n') {
            nlinhas++;
        }
    }
    printf("Arquivo com %d linhas\n", nlinhas);
    system("pause");
    fclose(otherxt);
    
    
    
    return 0;
}

