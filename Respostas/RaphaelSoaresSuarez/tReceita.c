#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tReceita.h"

#define MAX_TAM_NOME_MEDICAMENTO 50
#define MAX_TAM_TIPO_MEDICAMENTO 50
#define MAX_TAM_INSTRUCOES 300
#define NOME_ARQUIVO_RECEITA "receita.txt"

typedef struct tReceita {
    char *nomePaciente;
    char nomeMedicamento[50];
    char tipoMedicamento[50];
    char instrucoes[300];
    int qntd;
    char *nomeMedico;
    char CRM[12];
    char *dataStr;
    eTipoUso tipoUso;
} tReceita;

/**
 * Função que recebe todas as informações pertinentes a uma receita e retorna
 * um ponteiro com a receita criada.
 *
 */
tReceita *criaReceita(char *nomePaciente, eTipoUso tipoUso, char *nomeMedicamento,
                      char *tipoMedicamento, char *instrucoes, int qntd,
                      char *nomeMedico, char *CRM, char *dataStr){
                        tReceita* receita = malloc(sizeof(tReceita));
                        receita->nomePaciente = strdup(nomePaciente);
                        receita->nomeMedico = strdup(nomeMedico);
                        strcpy(receita->CRM,CRM);
                        receita->dataStr = strdup(dataStr);
                        strcpy(receita->nomeMedicamento,nomeMedicamento);
                        strcpy(receita->tipoMedicamento,tipoMedicamento);
                        strcpy(receita->instrucoes,instrucoes);
                        receita->qntd = qntd;
                        receita->tipoUso = tipoUso;

                        return receita;
                      }

/**
 * Função que recebe o ponteiro genérico (que deve conter uma receita) e o desaloca da memória.
 * Essa função primeiro verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaReceita(void *dado) {
    if (dado != NULL) {
        tReceita *receita = (tReceita *)dado;

        // Check and free strings within the struct
        if (receita->nomePaciente != NULL) {
            free(receita->nomePaciente);
        }
        if (receita->nomeMedico != NULL) {
            free(receita->nomeMedico);
        }
        if (receita->dataStr != NULL) {
            free(receita->dataStr);
        }

        // Finally, free the struct
        free(receita);
    }
}


/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void imprimeNaTelaReceita(void *dado) {
    if (dado != NULL) {
        tReceita *receita = (tReceita *)dado;

        // Print NOME DO PACIENTE
        if (receita->nomePaciente != NULL) {
            printf("NOME: %s\n\n", receita->nomePaciente);
        }

        // Print TIPO DO USO
        if (receita->tipoUso == ORAL) {
            printf("USO ORAL\n\n");
        }
        else if (receita->tipoUso == TOPICO) {
            printf("USO TOPICO\n\n");
        }

        // Print NOME DO MEDICAMENTO
        if (receita->nomeMedicamento != NULL) {
            printf("%s\n", receita->nomeMedicamento);
        }

        // Print QTD E TIPO
        if (receita->tipoMedicamento != NULL) {
            printf("%d %s\n\n", receita->qntd, receita->tipoMedicamento);
        }

        // Print INSTRUCOES
        if (receita->instrucoes != NULL) {
            printf("%s\n\n", receita->instrucoes);
        }

        // Print NOME DO MEDICO E CRM
        if ((receita->nomeMedico != NULL) && (receita->CRM != NULL)) {
            printf("%s (%s)\n", receita->nomeMedico, receita->CRM);
        }

        // Print DATA
        if (receita->dataStr != NULL) {
            printf("%s\n", receita->dataStr);
        }
    }
}


/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 * Ex: /home/usuario/Documentos
 * O nome do arquivo e a maneira de escrita é definido dentro da função
 */
void imprimeEmArquivoReceita(void *dado, char *path) {
    if (dado != NULL) {
        tReceita *receita = (tReceita *)dado;

        // Monta o caminho completo do arquivo
        char caminho[1000];
        sprintf(caminho, "%s/receita.txt", path);

        // Abre o arquivo para escrita (sobrescreve se já existir)
        FILE *receituario = fopen(caminho, "a");

        if (receituario != NULL) {
            // Escreve os dados no arquivo
            fprintf(receituario,"RECEITUARIO\n");
            // NOME DO PACIENTE
            fprintf(receituario,"NOME: %s\n\n", receita->nomePaciente);
            // TIPO DO USO
            fprintf(receituario,"USO %s\n\n", (receita->tipoUso == ORAL) ? "ORAL" : "TOPICO");
            // NOME DO MEDICAMENTO
            fprintf(receituario,"%s\n", receita->nomeMedicamento);
            // QTD E TIPO
            fprintf(receituario,"%d %s\n\n", receita->qntd, receita->tipoMedicamento);
            // INSTRUCOES
            fprintf(receituario,"%s\n\n", receita->instrucoes);
            // NOME DO MEDICO E CRM
            fprintf(receituario,"%s (%s)\n", receita->nomeMedico, receita->CRM);
            fprintf(receituario,"%s\n\n", receita->dataStr);

            // Fecha o arquivo
            fclose(receituario);
        }
    }
}
