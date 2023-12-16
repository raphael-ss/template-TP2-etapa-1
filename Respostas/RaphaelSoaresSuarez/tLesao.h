

#ifndef _TLESAO_H_
#define _TLESAO_H_

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

typedef enum
{
    CARCINOMA_BASOCELULAR,
    CARCINOMA_ESPINOCELULAR,
    MELANOMA,
    CERATOSE_ACTINICA,
    NEVO,
    CERATOSE_SEBORREICA,
    OUTRO_DIAGNOSTICO
} eDiagnostico;

typedef enum
{
    FACE,
    ORELHA,
    COURO_CAB,
    PEITORAL,
    DORSO,
    ABDOME,
    BRACO,
    ANTEBRACO,
    MAO,
    COXA,
    CANELA,
    PE,
    OUTRA_REGIAO
} eRegiao;

typedef struct tLesao tLesao;


/**
 * Função que cria uma pessoa e retorna um ponteiro para ela.
 */
tLesao *criaLesao(char* rotulo,eDiagnostico diagnostico,eRegiao regiao,
                int tamanho,int requerCirurgia,int requerCrioterapia);

/**
 * Função que recebe um ponteiro para uma pessoa e desaloca toda a memória
 * associada a ela.
 * Essa função sempre verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaLesao(tLesao *l);

char* obtemExibicaoLesao(tLesao *l);

void salvaLesao(tLesao* l, FILE* file);

tLesao* recuperaLesao(FILE* file);


#endif