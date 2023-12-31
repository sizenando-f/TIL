/*  Resolva T4 usando modulariza��o. Os dados de execu��o dever�o ser
    recebidos via argumento do programa na linha de comando.

    Exemplos de execu��es

    app 3 GCTTTCGACGAT GATCGAGCTTCGAA GGTCTAGCTAAT TCGA

    SAIDA_2 = Quantidade de bacterias: 3
    SAIDA_3 = Bacteria: GCTTTCGACGAT
    SAIDA_3 = Bacteria: GATCGAGCTTCGAA
    SAIDA_3 = Bacteria: GGTCTAGCTAAT
    SAIDA_4 = Virus: TCGA
    SAIDA_5 = Bacteria infectada: GCTT
    SAIDA_5 = Bacteria infectada: GAGCTA
    SAIDA_5 = Bacteria infectada: GGTCTAGCTAAT
    SAIDA_6 = DNA resultante: GCT



    app 5 AGCT TGC CGCAA TGTC ATGTTC T

    SAIDA_2 = Quantidade de bacterias: 5
    SAIDA_3 = Bacteria: AGCT
    SAIDA_3 = Bacteria: TGC
    SAIDA_3 = Bacteria: CGCAA
    SAIDA_3 = Bacteria: TGTC
    SAIDA_3 = Bacteria: ATGTTC
    SAIDA_4 = Virus: T
    SAIDA_5 = Bacteria infectada: AGC
    SAIDA_5 = Bacteria infectada: GC
    SAIDA_5 = Bacteria infectada: CGCAA
    SAIDA_5 = Bacteria infectada: GC
    SAIDA_5 = Bacteria infectada: AGC
    SAIDA_6 = DNA resultante: GC

    Falta fazer o programa descobrir a substring mais longa dentro das strings
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LIMITE_BACTERIAS 10
#define COMPR_BACTERIAS 1000
#define COMPR_VIRUS 1000

#define SAIDA_2 "\nSAIDA_2 = Quantidade de bacterias: %d"
#define SAIDA_3 "\nSAIDA_3 = Bacteria: %s"
#define SAIDA_4 "\nSAIDA_4 = Virus: %s"
#define SAIDA_5 "\nSAIDA_5 = Bacteria infectada: %s"
#define SAIDA_6 "\nSAIDA_6 = DNA resultante: %s"

// rrocedimento que descobre a maior substring comum
void dnaResultante(char bacterias[][COMPR_BACTERIAS], int nBacterias, char resultado[]){
    size_t tamBac = strlen(bacterias[0]);
    char bacteriaPrinc[tamBac]; // Recebe primeira bacteria como base
    char resultadoFinal[COMPR_BACTERIAS] = "";

    strcpy(bacteriaPrinc, bacterias[0]);

    for(size_t tam = tamBac; tam >= 1; tam--){
        for(size_t i = 0; i <= tamBac - tam; i++){
            char temp[tam + 1]; // Armazena parte da string
            strncpy(temp, bacteriaPrinc + i, tam);
            temp[tam] = '\0';   // Insere o finalizador de strings no final do vetor

            int cont = 0;
            for(int k = 0; k < nBacterias; k++){
                if(strstr(bacterias[k], temp)){ // Verifica se a substring criada existe nas outras bacterias
                    cont++;
                }
            }

            if(cont == nBacterias && strlen(temp) > strlen(resultadoFinal)){
                strcpy(resultadoFinal, temp);   // Armazena maior substring
            }
        }
    }
    strcpy(resultado, resultadoFinal);
}

// Procedimento que remove o RNA do virus do DNA da bacteria
void destroiDNA(char bacterias[][COMPR_BACTERIAS], int nBacterias, char virus[COMPR_VIRUS]){
    for(int i = 0; i < nBacterias; i++){
        char *resultado = strstr(bacterias[i], virus);  // Descobre primeira posição do RNA no DNA
            while(resultado){   // Enquanto existir a substring
            size_t len = strlen(virus); // Pega o tamanho do RNA
            memmove(resultado, resultado + len, strlen(resultado + len) + 1); // Move o restante do DNA para a posição onde o RNA foi encontrado, "apagando" ele
            resultado = strstr(bacterias[i], virus); // Renova o resultado em busca de outro RNA
            }
    }  
}

int main (int argc, char *argv[]){
    int nBacterias;
    char BACTERIAS[LIMITE_BACTERIAS][COMPR_BACTERIAS];
    char VIRUS[COMPR_VIRUS];
    char dnaResult[COMPR_BACTERIAS];
    int validaBacteria = 0;

    nBacterias = atoi(argv[1]);
    if(nBacterias >= 1 && nBacterias <= 10){ // Valida a quantidade de bacterias está no intervalo
        if((argc - 3) == nBacterias){   // Valida se existe a quantidade correta de bacterias informada pelo usuario
            for(int j = 2; j < argc - 1; j++){  // Verifica se todas bacterias estão no intervalo correto
                if((strlen(argv[j]) >= 1) && (strlen(argv[j]) <= 1000)){
                    validaBacteria++;
                }
            }
            if(validaBacteria == nBacterias){ 
                if((strlen(argv[argc-1]) >= 1) && (strlen(argv[argc-1]) <= 1000)){  // Verifica se o RNA do virus está no intervalo correto
                    printf(SAIDA_2,nBacterias);
                    for(int i=2;i<argc-1;i++) {
                        strcpy(BACTERIAS[i-2],argv[i]);
                        printf(SAIDA_3,BACTERIAS[i-2]);
                    }
                    strcpy(VIRUS,argv[argc-1]);
                    printf(SAIDA_4,VIRUS);
                    
                    destroiDNA(BACTERIAS, nBacterias, VIRUS);
                    for(int i = 0; i < nBacterias; i++){
                        printf(SAIDA_5, BACTERIAS[i]);
                    }
                    
                    dnaResultante(BACTERIAS, nBacterias, dnaResult);
                    if(!strcmp(dnaResult, "")){
                        printf(SAIDA_6, "DNA COMUM INEXISTENTE");
                    } else {
                        printf(SAIDA_6, dnaResult); 
                    }
                } else {
                    printf("O RNA DO VIRUS POSSUI O TAMANHO INCORRETO\n");
                }
            } else {
                printf("UMA DAS BACTERIAS NAO POSSUI A QUANTIDADE CORRETA DE PROTEINA\n");
            }
        } else {
            printf("QUANTIDADE INCORRETA DA BACTERIAS INFORMADA\n");
        }
    } else {
        printf("NUMERO INVALIDO DE BACTERIAS, PRECISA SER >= 1 E <= 10\n");
    }
    

    return 0;
}

