

#ifndef _TPESSOA_H_
#define _TPESSOA_H_

#include <stdio.h>
#include <stdlib.h>

/*
Nome completo (string com no máximo 100 caracteres)
CPF (no formato: 000.000.000-00)
Data de nascimento (seguindo padrão dd/mm/aaaa)
Telefone (formato: (00)00000-0000)
Gênero (masculino, feminino, outros)
*/

typedef enum
{
    MASCULINO,
    FEMININO,
    OUTROS
} eGenero;

typedef struct tPessoa tPessoa;


/**
 * Função que cria uma pessoa e retorna um ponteiro para ela.
 */
tPessoa *criaPessoa(char* nome, char* cpf, char* dataNascimento, char* telefone, eGenero genero);

/**
 * Função que recebe um ponteiro para uma pessoa e desaloca toda a memória
 * associada a ela.
 * Essa função sempre verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaPessoa(tPessoa *p);

char* obtemNomePessoa(tPessoa *p);

char* obtemCPF(tPessoa *p);

char* obtemDataNascimento(tPessoa *p);

char* obtemTelefone(tPessoa *p);

eGenero obtemGenero(tPessoa *p);

void salvaPessoa(tPessoa* p, FILE* file);

tPessoa* recuperaPessoa(FILE* file);

#endif