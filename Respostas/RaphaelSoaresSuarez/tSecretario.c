#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPessoa.h"
#include "tSecretario.h"

/*
username
senha
nivel de acesso
*/

typedef enum
{
    USER,
    ADMIN
} eAcesso;

typedef struct tSecretario {
    tPessoa *pessoa;
    eAcesso acesso;
    char username[20];
    char senha[20];
} tSecretario;


/**
 * Função que cria uma pessoa e retorna um ponteiro para ela.
 */
tSecretario *criaSecretario(char* nome, char* cpf, char* dataNascimento, char* telefone, eGenero genero, char* username, char* senha, eAcesso acesso){

    tSecretario * secretario = malloc(sizeof(tSecretario));
    secretario->pessoa = criaPessoa(nome, cpf, dataNascimento, telefone, genero);
    strcpy(secretario->username,username);
    strcpy(secretario->senha,senha);

    secretario->acesso = acesso;

    return secretario;
}

/**
 * Função que recebe um ponteiro para uma pessoa e desaloca toda a memória
 * associada a ela.
 * Essa função sempre verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaSecretario(tSecretario *s){
    if (s != NULL) {
        desalocaPessoa(s->pessoa);
        free(s);
    }
}
