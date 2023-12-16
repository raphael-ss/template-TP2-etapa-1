


#ifndef _TCONSULTA_H_
#define _TCONSULTA_H_

#include "tPaciente.h"
#include "tMedico.h"


typedef struct tConsulta tConsulta;

tConsulta* criaConsulta(char* cpfPaciente, char* dataStr);

void cadastraLesao(tConsulta* c, char* rotulo, eDiagnostico diagnostico, eRegiao regiao,
int tamanho, int requerCirurgia, int requerCrioterapia);

void desalocaConsulta(tConsulta* c);

int obtemNumeroLesoes(tConsulta* c);

tLesao** obtemLesoes(tConsulta* c);

void salvaConsultaComLesoes(tConsulta* c, FILE* file);

tConsulta* recuperaConsultaComLesoes(FILE* file);

char* obtemDataConsulta(tConsulta*c);

#endif