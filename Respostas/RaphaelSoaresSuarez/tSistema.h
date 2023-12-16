

#ifndef _TSISTEMA_H_
#define _TSISTEMA_H_

#include "tPaciente.h"
#include "tBiopsia.h"
#include "tConsulta.h"
#include "tMedico.h"
#include "tDocumento.h"
#include "tSecretario.h"
#include "tEncaminhamento.h"
#include "tFila.h"
#include "tLesao.h"
#include "tListaBusca.h"
#include "tReceita.h"
#include "tRelatorio.h"
#include "tClinica.h"


typedef struct tSistema tSistema;


/**
 * Função que cria uma pessoa e retorna um ponteiro para ela.
 */
tSistema* criaSistema(char* path_db, char* path);

void cadastraSecretario(tSistema* s);

void cadastraMedico(tSistema* s);

void cadastraPaciente(tSistema* s);

/**
 * Função que recebe um ponteiro para uma pessoa e desaloca toda a memória
 * associada a ela.
 * Essa função sempre verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaSistema();

void realizaLogin(tSistema* sist);

tRelatorio* calculaRelatorio(tClinica* c);

/**
 * 
*/
void executaRelatorio();

void SalvaBancoDeDados(tSistema* sist);

#endif