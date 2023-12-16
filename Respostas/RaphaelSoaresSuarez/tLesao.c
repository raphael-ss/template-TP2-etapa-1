#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tLesao.h"

/*
Coletada essas informações, o médico deve ser capaz de cadastrar uma ou mais lesões relacionadas ao paciente. 
Uma lesão possui os seguintes atributos:
Rótulo (string com no máximo 5 caracteres seguindo o padrão L1, L2, L3, …, Ln)
Deve ser incrementado automaticamente à medida que as lesões são adicionadas ao paciente
Diagnóstico clínico
Valores possíveis: CARCINOMA BASOCELULAR, CARCINOMA ESPINOCELULAR, MELANOMA, CERATOSE ACTINICA, NEVO, 
CERATOSE SEBORREICA e OUTROS
Região do corpo
Valores possíveis: FACE, ORELHA, COURO CABELUDO, PEITORAL, DORSO, ABDOME,  BRAÇO, ANTEBRAÇO, MAO, 
COXA, CANELA, PE e OUTROS
Tamanho (inteiro representando o tamanho em milímetros)
Se a lesão deve ser enviada para cirurgia (inteiro assumindo 1 ou 0)
Se a lesão deve ser enviada para crioterapia (inteiro assumindo 1 ou 0)

*/

typedef struct tLesao {
    char rotulo[5];
    eDiagnostico diagnostico;
    eRegiao regiao;
    int tamanho; // EM MILIMETROS
    int requerCirurgia;
    int requerCrioterapia;
} tLesao;


/**
 * Função que cria uma pessoa e retorna um ponteiro para ela.
 */
tLesao *criaLesao(char* rotulo,eDiagnostico diagnostico,eRegiao regiao,
                int tamanho,int requerCirurgia,int requerCrioterapia){

                    tLesao *lesao = malloc(sizeof(tLesao));

                    strcpy(lesao->rotulo, rotulo);
                    lesao->diagnostico = diagnostico;
                    lesao->regiao = regiao;
                    lesao->tamanho = tamanho;
                    lesao->requerCirurgia = requerCirurgia;
                    lesao->requerCrioterapia = requerCrioterapia;

                    return lesao;
}

/**
 * Função que recebe um ponteiro para uma pessoa e desaloca toda a memória
 * associada a ela.
 * Essa função sempre verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaLesao(tLesao *l){
    if (l != NULL) {
        free(l);
    }
}

char* obtemRotuloLesao(tLesao *l){
    if (l != NULL) {
        return l->rotulo;
    }
    return NULL;
}

//25
char* obtemDiagnosticoLesao(tLesao *l){
    if (l != NULL) {
        if (l->diagnostico == CARCINOMA_BASOCELULAR) {
            return "CARCINOMA BASOCELULAR";
        }
        else if (l->diagnostico == CARCINOMA_ESPINOCELULAR) {
            return "CARCINOMA ESPINOCELULAR";
        }
        else if (l->diagnostico == CERATOSE_SEBORREICA) {
            return "CERATOSE SEBORREICA";
        }
        else if (l->diagnostico == MELANOMA) {
            return "MELANOMA";
        }
        else if (l->diagnostico == CERATOSE_ACTINICA) {
            return "CERATOSE ACTINICA";
        }
        else if (l->diagnostico == NEVO) {
            return "NEVO";
        }
        else if (l->diagnostico == OUTRO_DIAGNOSTICO) {
            return "OUTROS";
        }
    }
    return NULL;
}

//15
char* obtemRegiaoLesao(tLesao *l){
    if (l != NULL) {
        if (l->regiao == FACE) {
            return "FACE";
        }
        else if (l->regiao == ORELHA) {
            return "ORELHA";
        }
        else if (l->regiao == COURO_CAB) {
            return "COURO CABELUDO";
        }
        else if (l->regiao == PEITORAL) {
            return "PEITORAL";
        }
        else if (l->regiao == DORSO) {
            return "DORSO";
        }
        else if (l->regiao == ABDOME) {
            return "ABDOME";
        }
        else if (l->regiao == BRACO) {
            return "BRACO";
        }
        else if (l->regiao == ANTEBRACO) {
            return "ANTEBRACO";
        }
        else if (l->regiao == MAO) {
            return "MAO";
        }
        else if (l->regiao == COXA) {
            return "COXA";
        }
        else if (l->regiao == CANELA) {
            return "CANELA";
        }
        else if (l->regiao == PE) {
            return "PE";
        }
        else if (l->regiao == OUTRA_REGIAO) {
            return "OUTROS";
        }
    }
    return NULL;
}

char* obtemExibicaoLesao(tLesao *l){
    char* exibicao = (char*)calloc(1, sizeof(char) * 60);

    sprintf(exibicao, "%s - %s - %s - %dMM\n", obtemRotuloLesao(l), obtemDiagnosticoLesao(l),
    obtemRegiaoLesao(l), l->tamanho);

    return exibicao;
}

void salvaLesao(tLesao* l, FILE* file){
    fwrite(l, sizeof(tLesao), 1, file);
    return;
}

tLesao* recuperaLesao(FILE* file){
    tLesao* l = (tLesao*)calloc(1, sizeof(tLesao));
    fread(l, sizeof(tLesao), 1, file);
    return l;
}