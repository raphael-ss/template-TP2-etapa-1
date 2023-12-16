#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPaciente.h"
#include "tMedico.h"


typedef struct tConsulta {
    char cpfPaciente[15];
    char cpfMedico[15];
    char data[11];
    tLesao** lesoes;
    int numeroLesoes;
} tConsulta;

tConsulta* criaConsulta(char* cpfPaciente, char* dataStr){
    tConsulta* consulta = malloc(sizeof(tConsulta));

    consulta->lesoes = NULL;
    consulta->numeroLesoes = 0;
    strcpy(consulta->data, dataStr);
    //strcpy(consulta->cpfMedico, cpfMedico);
    strcpy(consulta->cpfPaciente, cpfPaciente);

    return consulta;
}

    /*char rotulo[5];
    eDiagnostico diagnostico;
    eRegiao regiao;
    int tamanho; // EM MILIMETROS
    int requerCirurgia;
    int requerCrioterapia;*/
        
void cadastraLesao(tConsulta* c, char* rotulo, eDiagnostico diagnostico, eRegiao regiao,
int tamanho, int requerCirurgia, int requerCrioterapia) {
                    if (c != NULL) {
                        tLesao* lesao = criaLesao(rotulo, diagnostico, regiao, tamanho, 
                        requerCirurgia, requerCrioterapia);
                        c->numeroLesoes++;
                        int n = c->numeroLesoes;
                        c->lesoes = realloc(c->lesoes, (n * sizeof(tLesao*)));
                        c->lesoes[n] = lesao;
                    }
                    return;
                }

void desalocaConsulta(tConsulta* c){
    if (c != NULL) {
        if (c->lesoes != NULL) {
            for (int i = 0; i < c->numeroLesoes; i++) {
                desalocaLesao(c->lesoes[i]);
            }
            free(c->lesoes);
        }
        free(c);
    }
}

void salvaConsultaComLesoes(tConsulta* c, FILE* file){
    fwrite(c, sizeof(tConsulta), 1, file);
    for (int i = 0; i < c->numeroLesoes; i++) {
        salvaLesao(c->lesoes[i], file);
    }
    return;
}

tConsulta* recuperaConsultaComLesoes(FILE* file){
    tConsulta* c = (tConsulta*)calloc(1, sizeof(tConsulta));
    fread(c, sizeof(tConsulta), 1, file);
    for (int i = 0; i < c->numeroLesoes; i++) {
        c->lesoes[i] = recuperaLesao(file);
    }
    return c;
}

int obtemNumeroLesoes(tConsulta* c) {
    return c->numeroLesoes;
}

tLesao** obtemLesoes(tConsulta* c) {
    return c->lesoes;
}

char* obtemDataConsulta(tConsulta*c){
    return c->data;
}