

#ifndef _TRELATORIO_H_
#define _TRELATORIO_H_

typedef struct tRelatorio tRelatorio;

/**
 * Função que recebe todas as informações pertinentes a uma receita e retorna
 * um ponteiro com a receita criada.
 *
 */
tRelatorio *criaRelatorio();

/**
 * Função que recebe o ponteiro genérico (que deve conter uma receita) e o desaloca da memória.
 * Essa função primeiro verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaRelatorio(tRelatorio *r);


void atualizaRelatorio(tRelatorio* r, int idadeMedia, int numeroPacientes,int homens,int mulheres,
                       int outros,int tamanhoMedioLesoes,int numeroCirurgias,int numeroLesoes,
                       int numeroCrioterapia);

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void imprimeNaTelaRelatorio(tRelatorio *r);

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 * Ex: /home/usuario/Documentos
 * O nome do arquivo e a maneira de escrita é definido dentro da função
 */
void imprimeEmArquivoRelatorio(tRelatorio *r, char *path);

#endif