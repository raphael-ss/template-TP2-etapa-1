

#ifndef _TMEDICO_H_
#define _TMEDICO_H_

/*
CRM
NOME DE USUARIO
SENHA
*/

typedef struct tMedico tMedico;


/**
 * Função que cria uma pessoa e retorna um ponteiro para ela.
 */
tMedico *criaMedico();

/**
 * Função que recebe um ponteiro para uma pessoa e desaloca toda a memória
 * associada a ela.
 * Essa função sempre verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaMedico(tMedico *m);


#endif