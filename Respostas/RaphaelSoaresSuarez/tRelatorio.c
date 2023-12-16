#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tRelatorio.h"

typedef struct tRelatorio
{
    int idadeMedia;
    int numeroPacientes;
    int homens;
    int mulheres;
    int outros;
    int tamanhoMedioLesoes;
    int numeroLesoes;
    int numeroCirurgias;
    int numeroCrioterapia;
} tRelatorio;

/**
 * Função que recebe todas as informações pertinentes a uma receita e retorna
 * um ponteiro com a receita criada.
 *
 */
tRelatorio *criaRelatorio()
{
    tRelatorio *relatorio = (tRelatorio *)calloc(1, sizeof(tRelatorio));
    return relatorio;
}

/**
 * Função que recebe o ponteiro genérico (que deve conter uma receita) e o desaloca da memória.
 * Essa função primeiro verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaRelatorio(tRelatorio *r){
    if (r != NULL){
        free(r);
    }
}

void atualizaRelatorio(tRelatorio* r, int idadeMedia, int numeroPacientes,int homens,int mulheres,
                       int outros,int tamanhoMedioLesoes,int numeroCirurgias,int numeroLesoes,
                       int numeroCrioterapia){
                        r->homens = homens;
                        r->idadeMedia = idadeMedia;
                        r->mulheres = mulheres;
                        r->numeroCirurgias = numeroCirurgias;
                        r->numeroCrioterapia = numeroCrioterapia;
                        r->numeroPacientes = numeroPacientes;
                        r->outros = outros;
                        r->tamanhoMedioLesoes = tamanhoMedioLesoes;
                        r->numeroLesoes = numeroLesoes;

                        return;
                    }

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void imprimeNaTelaRelatorio(tRelatorio *r){
    if (r != NULL) {
        printf("NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n", r->numeroPacientes);
        printf("IDADE MEDIA: %d\n", r->idadeMedia);
        printf("DISTRIBUICAO POR GENERO:\n");
        printf("- FEMININO: %d\n", r->mulheres);
        printf("- MASCULINO: %d\n", r->homens);
        printf("- OUTROS: %d\n", r->outros);
        printf("TAMANHO MEDIO DAS LESOES: %d\n", r->tamanhoMedioLesoes);
        printf("NUMERO TOTAL DE LESOES: %d\n", r->numeroLesoes);
        printf("NUMERO TOTAL DE CIRURGIAS: %d\n", r->numeroCirurgias);
        printf("NUMERO TOTAL DE CRIOTERAPIA: %d\n\n", r->numeroCrioterapia);
    }
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 * Ex: /home/usuario/Documentos
 * O nome do arquivo e a maneira de escrita é definido dentro da função
 */
void imprimeEmArquivoRelatorio(tRelatorio *r, char *path){

    char caminho[1000];
    sprintf(caminho, "%s/relatorio_geral.txt", path);

    FILE *relatorio = fopen(caminho, "a");

    if (relatorio != NULL && r != NULL) {
        fprintf(relatorio, "NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n", r->numeroPacientes);
        fprintf(relatorio, "IDADE MEDIA: %d\n", r->idadeMedia);
        fprintf(relatorio, "DISTRIBUICAO POR GENERO:\n");
        fprintf(relatorio, "- FEMININO: %d\n", r->mulheres);
        fprintf(relatorio, "- MASCULINO: %d\n", r->homens);
        fprintf(relatorio, "- OUTROS: %d\n", r->outros);
        fprintf(relatorio, "TAMANHO MEDIO DAS LESOES: %d\n", r->tamanhoMedioLesoes);
        fprintf(relatorio, "NUMERO TOTAL DE LESOES: %d\n", r->numeroLesoes);
        fprintf(relatorio, "NUMERO TOTAL DE CIRURGIAS: %d\n", r->numeroCirurgias);
        fprintf(relatorio, "NUMERO TOTAL DE CRIOTERAPIA: %d\n\n", r->numeroCrioterapia);

        fclose(relatorio);
    }
}
