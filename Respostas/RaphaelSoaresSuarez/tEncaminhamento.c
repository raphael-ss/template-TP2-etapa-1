#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tEncaminhamento.h"

typedef struct tEncaminhamento {
    char *nomePaciente;
    char CPF[14];
    char especialidade[50];
    char motivo[300];
    char *nomeMedico;
    char CRM[12];
    char *dataStr;
} tEncaminhamento;

/**
 * Função que recebe todas as informações pertinentes a uma receita e retorna
 * um ponteiro com a receita criada.
 * 
 */
tEncaminhamento *criaEncaminhamento(char *nomePaciente, char *CPF,
    char *especialidade, char *motivo, char *nomeMedico, char *CRM, char *dataStr){
        tEncaminhamento *encaminhamento = malloc(sizeof(tEncaminhamento));

        encaminhamento->nomePaciente = strdup(nomePaciente);
        encaminhamento->nomeMedico = strdup(nomeMedico);
        encaminhamento->dataStr = strdup(dataStr);

        strcpy(encaminhamento->CPF, CPF);
        strcpy(encaminhamento->especialidade, especialidade);
        strcpy(encaminhamento->motivo, motivo);
        strcpy(encaminhamento->CRM, CRM);

        return encaminhamento;
    }

/**
 * Função que recebe o ponteiro genérico (que deve conter uma receita) e o desaloca da memória.
 * Essa função primeiro verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaEncaminhamento(tEncaminhamento* e){
    if (e != NULL) {
        if (e->nomePaciente != NULL) {
            free(e->nomePaciente);
        }
        if (e->nomeMedico != NULL) {
            free(e->nomeMedico);
        }
        if (e->dataStr != NULL) {
            free(e->dataStr);
        }
        free(e);
    }
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void imprimeNaTelaEncaminhamento(tEncaminhamento* e){
    if (e != NULL) {
        printf("PACIENTE: %s\n", e->nomePaciente);
        printf("CPF: %s\n\n", e->CPF);
        printf("ESPECIALIDADE ENCAMINHADA: %s\n\n", e->especialidade);
        printf("MOTIVO: %s\n\n", e->motivo);
        printf("%s (%s)\n", e->nomeMedico, e->CRM);
        printf("%s\n", e->dataStr);
    }
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 * Ex: /home/usuario/Documentos
 * O nome do arquivo e a maneira de escrita é definido dentro da função
 */
void imprimeEmArquivoEncaminhamento(tEncaminhamento* e, char* path){
        char caminho[1000];
        sprintf(caminho, "%s/encaminhamento.txt", path);

        FILE *encaminhamento = fopen(caminho, "a");

        if (e != NULL) {
            fprintf(encaminhamento, "PACIENTE: %s\n", e->nomePaciente);
            fprintf(encaminhamento, "CPF: %s\n\n", e->CPF);
            fprintf(encaminhamento, "ESPECIALIDADE ENCAMINHADA: %s\n\n", e->especialidade);
            fprintf(encaminhamento, "MOTIVO: %s\n\n", e->motivo);
            fprintf(encaminhamento, "%s (%s)\n", e->nomeMedico, e->CRM);
            fprintf(encaminhamento, "%s\n", e->dataStr);

            fclose(encaminhamento);
        }
}
