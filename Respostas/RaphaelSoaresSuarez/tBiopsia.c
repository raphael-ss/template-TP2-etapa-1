#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tLesao.h"
#include "tBiopsia.h"


typedef struct tBiopsia {
    tLesao **lesoes;
    char *nomePaciente; 
    char CPF[14];
    char *nomeMedico;
    char CRM[12];
    char *dataStr;
    int numeroLesoes;
} tBiopsia;

/**
 * Função que recebe todas as informações pertinentes a uma receita e retorna
 * um ponteiro com a receita criada.
 * Tem um vetor de tLesao e 
 */
tBiopsia *criaBiopsia(char *nomePaciente, char *CPF,
                      char *rotulo, eDiagnostico diagnostico, eRegiao regiao, 
                      int tamanho, int requerCrioterapia, char *nomeMedico, char *CRM, char *dataStr){

                        tBiopsia* biopsia = malloc(sizeof(tBiopsia));
                        
                        tLesao* lesao = criaLesao(rotulo, diagnostico, regiao, tamanho,
                        1, requerCrioterapia);

                        biopsia->numeroLesoes = 1;
                        biopsia->lesoes = malloc(sizeof(tLesao*));
                    
                        strcpy(biopsia->CRM, CRM);
                        strcpy(biopsia->CPF, CPF);
                        
                        biopsia->nomeMedico = strdup(nomeMedico);
                        biopsia->nomePaciente = strdup(nomePaciente);
                        biopsia->dataStr = strdup(dataStr);

                        return biopsia;                      
                      }

/**
 * Função que recebe o ponteiro genérico (que deve conter uma receita) e o desaloca da memória.
 * Essa função primeiro verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaBiopsia(tBiopsia* b){
    if (b != NULL) {
        if (b->dataStr != NULL) {
            free(b->dataStr);
        }
        if (b->nomePaciente!= NULL) {
            free(b->nomePaciente);
        }
        if (b->nomeMedico != NULL) {
            free(b->nomeMedico);
        }
        if (b->lesoes != NULL) {
            for (int i = 0; i < b->numeroLesoes; i++) {
                desalocaLesao(b->lesoes[i]);
            }
            free(b->lesoes);
        }
        free(b);
    }
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void imprimeNaTelaBiopsia(tBiopsia* b){
    if (b != NULL) {
        printf("PACIENTE: %s\n", b->nomePaciente);
        printf("CPF: %s\n\n", b->CPF);
        printf("SOLICITACAO DE BIOPSIA PARA AS LESOES:\n");
        for (int i = 0; i < b->numeroLesoes; i++) {
            printf("%s", obtemExibicaoLesao(b->lesoes[i]));
        }

        printf("%s (%s)\n", b->nomeMedico, b->CRM);
        printf("%s\n", b->dataStr);
    }
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 * Ex: /home/usuario/Documentos
 * O nome do arquivo e a maneira de escrita é definido dentro da função
 */
void imprimeEmArquivoBiopsia(tBiopsia* b, char* path){
        char caminho[1000];
        sprintf(caminho, "%s/biopsia.txt", path);

        FILE *biopsia = fopen(caminho, "a");

        if (b != NULL) {
            fprintf(biopsia, "PACIENTE: %s\n", b->nomePaciente);
            fprintf(biopsia, "CPF: %s\n\n", b->CPF);
            fprintf(biopsia, "SOLICITACAO DE BIOPSIA PARA AS LESOES:\n");
            for (int i = 0; i < b->numeroLesoes; i++) {
                fprintf(biopsia, "%s", obtemExibicaoLesao(b->lesoes[i]));
            }

            fprintf(biopsia, "%s (%s)\n", b->nomeMedico, b->CRM);
            fprintf(biopsia, "%s\n", b->dataStr);

            fclose(biopsia);
        }
}

