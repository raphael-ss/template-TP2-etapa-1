

#ifndef _TLISTABUSCA_H_
#define _TLISTABUSCA_H_

#include "tPaciente.h"

typedef struct tListaBusca tListaBusca;

tListaBusca* criaLista();

void desalocaLista(tListaBusca* lb);

void ExecutaBusca(tListaBusca *lb, char *nome);

tPaciente** obtemLista(tListaBusca *lb);

void imprimeListaTela(tListaBusca *lb);

void imprimeListaArquivo(tListaBusca *lb, char *path);

#endif