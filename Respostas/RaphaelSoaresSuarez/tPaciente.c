#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPessoa.h"
#include "tLesao.h"
#include "tPaciente.h"

/*
Nome completo (string com no máximo 100 caracteres)
CPF (no formato: 000.000.000-00)
Data de nascimento (seguindo padrão dd/mm/aaaa)
Telefone (formato: (00)00000-0000)
Gênero (masculino, feminino, outros)
*/

typedef struct tPaciente {
    tPessoa* pessoa;
    int diabetico;
    int fumante;
    int alergico;
    int canceroso;
    int numeroLesoes;
    etipoPele tipoPele;
    tLesao ** lesoes;
} tPaciente;


/**
 * Função que cria uma pessoa e retorna um ponteiro para ela.
 */
tPaciente *criaPaciente(char* nome, char* cpf, char* dataNascimento, char* telefone, eGenero genero) {
    tPaciente * paciente = malloc(sizeof(tPaciente));
    paciente->pessoa = criaPessoa(nome, cpf, dataNascimento, telefone, genero);
    paciente->diabetico = 0;
    paciente->fumante = 0;
    paciente->alergico = 0;
    paciente->canceroso = 0;
    paciente->tipoPele = UM;
    paciente->lesoes = NULL;
    return paciente;
}

void cadastraLesao(tPaciente* paciente, tLesao* lesao) {
                    if (paciente != NULL && lesao != NULL) {
                        paciente->numeroLesoes++;
                        int n = paciente->numeroLesoes;
                        paciente->lesoes = realloc(paciente->lesoes, (paciente->numeroLesoes * sizeof(tLesao*)));
                        paciente->lesoes[n] = lesao;
                    }
                    return;
                }

/**
 * Função que recebe um ponteiro para uma pessoa e desaloca toda a memória
 * associada a ela.
 * Essa função sempre verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaPaciente(tPaciente *p){
    if (p != NULL) {
        if (p->pessoa != NULL) {
            desalocaPessoa(p->pessoa);
        }
        if (p->lesoes != NULL) {
            for (int i = 0; i < p->numeroLesoes; i++) {
                desalocaLesao(p->lesoes[i]);
            }
            free(p->lesoes);
        }
        free(p);
    }
}
