#include <stdio.h>
#include <stdlib.h>
#include "tDocumento.h"

/**
 * Funções de callback que serão utilizadas para imprimir o documento na tela,
 * em arquivo e desalocar o dado genérico, respectivamente.
 */
typedef void (*func_ptr_imprimeNaTela)(void *dado);
typedef void (*func_ptr_imprimeEmArquivo)(void *dado, char *path);
typedef void (*func_ptr_desaloca)(void *dado);

typedef struct tDocumento {
    func_ptr_imprimeNaTela imprime_tela;
    func_ptr_imprimeEmArquivo imprime_arquivo;
    func_ptr_desaloca desaloca_dado;
    void * dado;
} tDocumento;

/**
 * Função que recebe um dado genérico (representando um tipo de documento) e suas funções de callback.
 * A função cria um Documento e retorna um ponteiro para ele.
 */
tDocumento *criaDocumento(void *dado, func_ptr_imprimeNaTela imprimeNaTela,
                          func_ptr_imprimeEmArquivo ImprimeEmArquivo,
                          func_ptr_desaloca desaloca) {
    tDocumento* doc = malloc(sizeof(tDocumento));
    doc->dado = dado;
    doc->desaloca_dado = desaloca;
    doc->imprime_arquivo = ImprimeEmArquivo;
    doc->imprime_tela = imprimeNaTela;
}

/**
 * Função que recebe um Documento e o desaloca. O dado genérico também deve ser desalocado
 * dentro dessa função.
 */
void desalocaDocumento(tDocumento *doc){
    if (doc != NULL) {
        if (doc->desaloca_dado != NULL){
            doc->desaloca_dado(doc->dado);
        }

        free(doc);
    }
    return;
}

/**
 * Função que recebe um Documento genérico e o imprime na tela.
 */
void imprimeNaTelaDocumento(tDocumento *doc){
    if (doc != NULL) {
        doc->imprime_tela(doc->dado);
    }
    return;
}

/**
 * Função que recebe um Documento genérico e o imprime em um arquivo.
 * O path representa o caminho até o diretório onde o arquivo será criado ou editado.
 */
void imprimeEmArquivoDocumento(tDocumento *doc, char *path){
    if (doc != NULL) {
        doc->imprime_arquivo(doc->dado, path);
    }
    return;
}

