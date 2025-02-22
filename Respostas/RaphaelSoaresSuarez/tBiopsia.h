

#ifndef _TBIOPSIA_H_
#define _TBIOPSIA_H_

#include "tLesao.h"

typedef struct tBiopsia tBiopsia;

/**
 * Função que recebe todas as informações pertinentes a uma receita e retorna
 * um ponteiro com a receita criada.
 * Tem um vetor de tLesao e 
 */
tBiopsia *criaBiopsia(char *nomePaciente, char *CPF,
                      char *rotulo, eDiagnostico diagnostico, eRegiao regiao, 
                      int tamanho, int requerCrioterapia, char *nomeMedico, char *CRM, char *dataStr);

/**
 * Função que recebe o ponteiro genérico (que deve conter uma receita) e o desaloca da memória.
 * Essa função primeiro verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaBiopsia(tBiopsia* b);

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void imprimeNaTelaBiopsia(tBiopsia* b);

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 * Ex: /home/usuario/Documentos
 * O nome do arquivo e a maneira de escrita é definido dentro da função
 */
void imprimeEmArquivoBiopsia(tBiopsia* b, char* path);

#endif