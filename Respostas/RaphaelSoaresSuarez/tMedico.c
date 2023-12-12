#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPessoa.h"
#include "tMedico.h"

/*
CRM
NOME DE USUARIO
SENHA
*/

typedef struct tMedico {
    tPessoa* pessoa;
    char CRM[12];
    char username[20];
    char senha[20];
} tMedico;


/**
 * Função que cria uma pessoa e retorna um ponteiro para ela.
 */
tMedico *criaMedico(char* nome, char* cpf, char* dataNascimento, char* telefone, eGenero genero, char* CRM, char* username, char* senha){

    tMedico * medico = malloc(sizeof(tMedico));
    medico->pessoa = criaPessoa(nome, cpf, dataNascimento, telefone, genero);
    strcpy(medico->CRM,CRM);
    strcpy(medico->username,username);
    strcpy(medico->senha,senha);

    return medico;
}

/**
 * Função que recebe um ponteiro para uma pessoa e desaloca toda a memória
 * associada a ela.
 * Essa função sempre verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaMedico(tMedico *m){
    if (m != NULL) {
        desalocaPessoa(m->pessoa);
        free(m);
    }
}


