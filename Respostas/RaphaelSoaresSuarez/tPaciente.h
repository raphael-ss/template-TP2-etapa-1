

#ifndef _TPACIENTE_H_
#define _TPACIENTE_H_

/*
Nome completo (string com no máximo 100 caracteres)
CPF (no formato: 000.000.000-00)
Data de nascimento (seguindo padrão dd/mm/aaaa)
Telefone (formato: (00)00000-0000)
Gênero (masculino, feminino, outros)
*/

typedef enum
{
    UM,
    DOIS,
    TRES,
    QUATRO,
    CINCO,
    SEIS
} etipoPele;

typedef struct tPaciente tPaciente;


/**
 * Função que cria uma pessoa e retorna um ponteiro para ela.
 */
tPaciente *criaPaciente(char* nome, char* cpf, char* dataNascimento, char* telefone, eGenero genero);

/**
 * Função que adiciona outra lesão no vetor de lesões do paciente
 * Utiliza realloc para aumentar o tamanho do vetor
 * 
*/
void cadastraLesao(tPaciente* paciente, tLesao* lesao);

/**
 * Função que recebe um ponteiro para uma pessoa e desaloca toda a memória
 * associada a ela.
 * Essa função sempre verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaPaciente(tPaciente *p);


#endif