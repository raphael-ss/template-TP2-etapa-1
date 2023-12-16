#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPessoa.h"
#include "tSecretario.h"


typedef struct tSecretario {
    tPessoa *pessoa;
    eAcesso acesso;
    char username[21];
    char senha[21];
} tSecretario;


/**
 * Função que cria uma pessoa e retorna um ponteiro para ela.
 */
tSecretario *criaSecretario(char* nome, char* cpf, char* dataNascimento, 
char* telefone, eGenero genero, char* username, char* senha, eAcesso acesso){

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

void salvaSecretario(tSecretario* s, FILE* file){
    fwrite(&(s), sizeof(tSecretario), 1, file);
    salvaPessoa(s->pessoa, file);
    return;
}

tSecretario* recuperaSecretario(FILE* file){
    tSecretario* s = (tSecretario*)calloc(1, sizeof(tSecretario));
    fread(s, sizeof(tSecretario), 1, file);
    s->pessoa = recuperaPessoa(file);
    return s;
}
