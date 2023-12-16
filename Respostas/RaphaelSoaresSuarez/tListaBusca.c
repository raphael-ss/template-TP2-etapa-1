#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPaciente.h"

typedef struct tListaBusca {
    tPaciente **pacientes;
    int numPacientes;
    tPaciente **pacientesEncontrados;
    int numPacientesEncontrados;
} tListaBusca;

tListaBusca* criaLista(){
    tListaBusca *lista = malloc(sizeof(tListaBusca));
    lista->pacientes = NULL;
    lista->numPacientes = 0;
    lista->pacientesEncontrados = NULL;
    lista->numPacientesEncontrados = 0;
    return lista;
}

void desalocaPacientesEncontrados(tListaBusca *lb) {
    if (lb->pacientesEncontrados != NULL) {
        for (int i = 0; i < lb->numPacientesEncontrados; i++) {
            desalocaPaciente(lb->pacientesEncontrados[i]);
        }
        free(lb->pacientesEncontrados);
        lb->pacientesEncontrados = NULL;
        lb->numPacientesEncontrados = 0;
    }
}

void desalocaLista(tListaBusca* lb) {
    for (int i = 0; i < lb->numPacientes; i++) {
        desalocaPaciente(lb->pacientes[i]);
    }
    free(lb->pacientes);

    desalocaPacientesEncontrados(lb);

    free(lb);
}


void ExecutaBusca(tListaBusca *lb, char *nome) {
    if (lb == NULL || nome == NULL) {
        return;
    }

    int encontrados = 0;

    // Libera a lista existente se houver
    desalocaPacientesEncontrados(lb);

    // Aloca espaço para a lista de pacientes encontrados
    //lb->pacientesEncontrados = malloc(lb->numPacientes * sizeof(tPaciente*));

    for (int i = 0; i < lb->numPacientes; i++) {
        if (lb->pacientes[i] != NULL && strstr(obtemNomePaciente(lb->pacientes[i]), nome) != NULL) {
            // Encontrou uma correspondência
            encontrados++;

            lb->pacientesEncontrados = realloc(lb->pacientesEncontrados, (encontrados * sizeof(tPaciente*)));

            lb->pacientesEncontrados[encontrados - 1] = criaPaciente(obtemNomePaciente(lb->pacientes[i]), 
            obtemCPFPaciente(lb->pacientes[i]), obtemDataNascimentoPaciente(lb->pacientes[i]), obtemTelefonePaciente(lb->pacientes[i]),
            obtemGeneroPaciente(lb->pacientes[i]));
        }
    }

    lb->numPacientesEncontrados = encontrados;
}

tPaciente** obtemLista(tListaBusca *lb){
    return (lb->pacientesEncontrados);
}

void imprimeListaTela(tListaBusca *lb){
    if (lb != NULL) {
        for (int i = 0; i < lb->numPacientesEncontrados; i++) {
            printf("%d - %s (%s)\n", (i+1), obtemNomePaciente(lb->pacientesEncontrados[i]), obtemCPFPaciente(lb->pacientesEncontrados[i]));
        }
    }
}

void imprimeListaArquivo(tListaBusca *lb, char *path){

    char caminho[1000];
    sprintf(caminho, "%s/lista_busca.txt", path);

    FILE *lista = fopen(caminho, "a");
    if (lb != NULL) {
        for (int i = 0; i < lb->numPacientesEncontrados; i++) {
            fprintf(lista, "%d - %s (%s)\n", (i+1), obtemNomePaciente(lb->pacientesEncontrados[i]), obtemCPFPaciente(lb->pacientesEncontrados[i]));
        }

        fclose(lista);
    }

}