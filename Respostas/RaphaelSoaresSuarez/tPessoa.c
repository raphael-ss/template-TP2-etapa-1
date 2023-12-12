#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPessoa.h"

/*
Nome completo (string com no máximo 100 caracteres)
CPF (no formato: 000.000.000-00)
Data de nascimento (seguindo padrão dd/mm/aaaa)
Telefone (formato: (00)00000-0000)
Gênero (masculino, feminino, outros)
*/

typedef struct tPessoa {
    char nome[100];
    char cpf[14];
    char dataNascimento[10];
    char telefone[14];
    eGenero genero;
} tPessoa;

/**
 * Função que cria uma pessoa e retorna um ponteiro para ela.
 */
tPessoa *criaPessoa(char* nome, char* cpf, char* dataNascimento, char* telefone, eGenero genero) {
    tPessoa* pessoa = malloc(sizeof(tPessoa));
    strcpy(pessoa->nome, nome);
    strcpy(pessoa->cpf, cpf);
    strcpy(pessoa->dataNascimento, dataNascimento);
    strcpy(pessoa->telefone, telefone);
    pessoa->genero = genero;
    return pessoa;
}

/**
 * Função que recebe um ponteiro para uma pessoa e desaloca toda a memória
 * associada a ela.
 * Essa função sempre verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaPessoa(tPessoa *p){
    if (p != NULL) {
        free(p);
    }
}


