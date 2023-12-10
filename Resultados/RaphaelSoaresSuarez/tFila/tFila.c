#include <stdio.h>
#include <stdlib.h>
#include "tDocumento.h"
#include "tFila.h"


#include "tDocumento.h"

typedef struct tFila {
    tDocumento** docs;
    int tam_fila;
} tFila;

/**
 * Função que cria uma fila de impressao vazia e retorna um ponteiro para ela.
 */
tFila * criaFila(){
    tFila* fila = malloc(sizeof(tFila));
    fila->docs = NULL;
    fila->tam_fila = 0;
    return fila;
}

/**
 * Função que recebe um ponteiro para uma fila de impressao e desaloca toda a memória
 * associada a ela. Essa função também desaloca todos os documentos associados a fila.
 * Essa função sempre verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaFila(tFila *f){
    if (f != NULL) {
        for (int i = 0; i < f->tam_fila; i++) {
            if (f->docs[i] != NULL) {
                desalocaDocumento(f->docs[i]);
            }
        }
        free(f->docs);
        free(f);
    }
}

/**
 * Função que recebe uma fila, um dado genérico e suas funções de callback para criar um Documento com esses elementos
 * e inseri-lo na fila de impressão. Perceba que a fila é agnóstica ao tipo de dado e pode conter
 * múltiplos Documentos (limitados pela memória) aguardando para serem impressos.
 *
 */
void insereDocumentoFila(tFila *f, void *dado, func_ptr_imprimeNaTela imprimeNaTela,
                         func_ptr_imprimeEmArquivo ImprimeEmArquivo,
                         func_ptr_desaloca desaloca){
    if (f != NULL) {
        f->tam_fila += 1;
        f->docs = realloc(f->docs, f->tam_fila * sizeof(tDocumento*));
        f->docs[f->tam_fila-1] = criaDocumento(dado, imprimeNaTela, ImprimeEmArquivo, desaloca);
    }
    return;
}

/**
 * Função que recebe uma fila e retorna quantos documentos existem dentro dela.
 */
int quantidadeDocumentosNaFila(tFila *f){
    return f->tam_fila;
}

/**
 * Função que invoca as funções de impressão de Documento executando a impressão de todos os documentos da fila.
 * A impressão é feita em duas etapas, primeiro o Documento é impresso na tela e depois em arquivo.
 * A função também recebe o path para o diretório onde o arquivo deve ser criado ou editado
 */
void imprimeFila(tFila *f, char *path){
    if (f != NULL) {
        for (int i = 0; i < f->tam_fila; i++) {
            imprimeNaTelaDocumento(f->docs[i]);
            imprimeEmArquivoDocumento(f->docs[i], path);
        }
    }
}

