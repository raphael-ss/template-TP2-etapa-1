

#ifndef _TSECRETARIO_H_
#define _TSECRETARIO_H_

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

typedef struct tSecretario tSecretario;


/**
 * Função que cria uma pessoa e retorna um ponteiro para ela.
 */
tSecretario *criaSecretario(char* nome, char* cpf, char* dataNascimento, char* telefone, eGenero genero, char* username, char* senha, eAcesso acesso);

/**
 * Função que recebe um ponteiro para uma pessoa e desaloca toda a memória
 * associada a ela.
 * Essa função sempre verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaSecretario(tSecretario *s);

void salvaSecretario(tSecretario* s, FILE* file);

tSecretario* recuperaSecretario(FILE* file);


#endif