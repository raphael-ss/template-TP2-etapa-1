#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tPaciente.h"
#include "tMedico.h"
#include "tSecretario.h"
#include "tLesao.h"
#include "tConsulta.h"

typedef struct tClinica {
    int numeroPacientes;
    int numeroMedicos;
    int numeroSecretarios;
    //int numeroLesoes;
    int numeroConsultas;
    tPaciente** pacientes;
    tMedico**  medicos;
    tSecretario** secretarios;
    //tLesao** lesoes;
    tConsulta** consultas;
} tClinica;

tClinica* criaClinica(){
    tClinica* clinica = calloc(1, sizeof(tClinica));
    clinica->pacientes = NULL;
    clinica->medicos = NULL;
    clinica->secretarios = NULL;
    //clinica->lesoes = NULL;
    clinica->consultas = NULL;

    clinica->numeroConsultas = 0;
    //clinica->numeroLesoes = 0;
    clinica->numeroMedicos = 0;
    clinica->numeroPacientes = 0;
    clinica->numeroSecretarios = 0;
    
    return clinica;
}

int verificaCPF(char* CPF, tPaciente** pacientes, int numeroPacientes){
    for (int i = 0; i < numeroPacientes; i++) {
        if (!(strcmp(obtemCPFPaciente(pacientes[i]), CPF))) {
            return 1;
        }
    }
    
    return 0;
}

void adicionaSecretario(tClinica*c, char* nome, char* cpf, char* dataNascimento, 
    char* telefone, eGenero genero, char* username, char* senha, eAcesso acesso){
        c->numeroSecretarios += 1;
        c->secretarios = realloc(c->secretarios, sizeof(tSecretario*)*c->numeroSecretarios);
        c->secretarios[c->numeroSecretarios-1] = criaSecretario(nome, cpf, dataNascimento,
        telefone, genero, username, senha, acesso);
        return;
}

void adicionaPaciente(tClinica*c, char* nome, char* cpf, char* dataNascimento, 
char* telefone, eGenero genero){
        c->numeroPacientes += 1;
        c->pacientes = realloc(c->pacientes, sizeof(tPaciente*)*c->numeroPacientes);
        c->pacientes[c->numeroPacientes-1] = criaPaciente(nome, cpf, dataNascimento,
        telefone, genero);
        return;
}

void adicionaMedico(tClinica*c, char* nome, char* cpf, char* dataNascimento, 
char* telefone, eGenero genero, char* CRM, char* username, char* senha){
        c->numeroMedicos += 1;
        c->medicos = realloc(c->medicos, sizeof(tMedico*)*c->numeroMedicos);
        c->medicos[c->numeroMedicos-1] = criaMedico(nome, cpf, dataNascimento,
        telefone, genero, CRM, username, senha);
        return;
}

void adicionaConsulta(tClinica*c, char* cpfPaciente, char* dataStr){
        c->numeroConsultas += 1;
        c->consultas = realloc(c->consultas, sizeof(tConsulta*)*c->numeroConsultas);
        c->consultas[c->numeroConsultas-1] = criaConsulta(cpfPaciente, dataStr);
        return;
}

tConsulta* obtemConsulta(tClinica* c, char* dataStr){
    for (int i = 0; i < c->numeroConsultas; i++) {
        if (!(strcmp(obtemDataConsulta(c->consultas[i]), dataStr))) {
            return c->consultas[i];
        }
    }
}


void desalocaClinica(tClinica* c){
    if (c != NULL) {
        if (c->pacientes != NULL) {
            for (int i = 0; i < c->numeroPacientes; i++) {
                desalocaPaciente(c->pacientes[i]);
            }
            free(c->pacientes);
        }
        if (c->medicos != NULL) {
            for (int i = 0; i < c->numeroMedicos; i++) {
                desalocaMedico(c->medicos[i]);
            }
            free(c->medicos);
        }
        if (c->secretarios != NULL) {
            for (int i = 0; i < c->numeroSecretarios; i++) {
                desalocaSecretario(c->secretarios[i]);
            }
            free(c->secretarios);
        }
        /*if (c->lesoes != NULL) {
            for (int i = 0; i < c->numeroLesoes; i++) {
                desalocaLesao(c->lesoes[i]);
            }
            free(c->lesoes);
        }*/
        if (c->consultas != NULL) {
            for (int i = 0; i < c->numeroConsultas; i++) {
                desalocaConsulta(c->consultas[i]);
            }
            free(c->consultas);
        }

        free(c);
    }
}

tLesao** obtemVetorLesoes(tConsulta** consultas, int numeroConsultas){
    tLesao** lesoes = NULL;
    int totalLesoes = 0;
    for (int i = 0; i < numeroConsultas; i++) {
        totalLesoes += obtemNumeroLesoes(consultas[i]);
    }
    lesoes = (tLesao**)realloc(lesoes, sizeof(tLesao*)*totalLesoes);
    int contador = 0;
    for (int i = 0; i < numeroConsultas; i++) {
        tLesao** lesoes_consulta = obtemLesoes(consultas[i]);
        for (int j = 0; j < obtemNumeroLesoes(consultas[i]); j++) {
            lesoes[contador] = lesoes_consulta[j];
        }
    }
    return lesoes;
}

int obtemTamanhoVetorLesoes(tConsulta** consultas, int numeroConsultas){
    int totalLesoes = 0;
    for (int i = 0; i < numeroConsultas; i++) {
        totalLesoes += obtemNumeroLesoes(consultas[i]);
    }
    return totalLesoes;
}

void salvaMedicosBin(tClinica *c, char *path) {
    char caminho[1000];
    sprintf(caminho, "%s/medicos.bin", path);

    FILE *medicosBin = fopen(caminho, "wb");

    if (medicosBin == NULL) {
        printf("Erro abrindo o arquivo 'medicos.bin' para armazenamento\n");
        exit(1);
    }

    if (c != NULL && c->medicos != NULL) {
        for (int i = 0; i < c->numeroMedicos; i++) {
            salvaMedico(c->medicos[i], medicosBin);
        }
    }

    fclose(medicosBin);
}

void salvaPacientesBin(tClinica *c, char *path){
    char caminho[1000];
    sprintf(caminho, "%s/pacientes.bin", path);

    FILE *pacientesBin = fopen(caminho, "wb");

    if (pacientesBin == NULL) {
        printf("Erro abrindo o arquivo 'pacientes.bin' para armazenamento\n");
        exit(1);
    }

    if (c != NULL && c->pacientes != NULL) {
        for (int i = 0; i < c->numeroPacientes; i++) {
            salvaPaciente(c->pacientes[i], pacientesBin);
        }
    }

    fclose(pacientesBin);
}

void salvaSecretariosBin(tClinica *c, char *path){
    char caminho[1000];
    sprintf(caminho, "%s/secretarios.bin", path);

    FILE *secretariosBin = fopen(caminho, "wb");

    if (secretariosBin == NULL) {
        printf("Erro abrindo o arquivo 'secretarios.bin' para armazenamento\n");
        exit(1);
    }

    if (c != NULL && c->secretarios != NULL) {
        for (int i = 0; i < c->numeroSecretarios; i++) {
            salvaSecretario(c->secretarios[i], secretariosBin);
        }
    }

    fclose(secretariosBin);

}

void salvaLesoesBin(tClinica *c, char *path){
    char caminho[1000];
    sprintf(caminho, "%s/lesoes.bin", path);

    FILE *lesoesBin = fopen(caminho, "wb");

    if (lesoesBin == NULL) {
        printf("Erro abrindo o arquivo 'lesoes.bin' para armazenamento\n");
        exit(1);
    }

    if (c != NULL && c->consultas != NULL) {
        tLesao** lesoes = obtemVetorLesoes(c->consultas, c->numeroConsultas);
        for (int i = 0; i < obtemTamanhoVetorLesoes(c->consultas, c->numeroConsultas); i++) {
            salvaLesao(lesoes[i], lesoesBin);
        }
    }

    fclose(lesoesBin);

}

void salvaConsultasBin(tClinica *c, char *path){
    char caminho[1000];
    sprintf(caminho, "%s/consultas.bin", path);

    FILE *consultasBin = fopen(caminho, "wb");

    if (consultasBin == NULL) {
        printf("Erro abrindo o arquivo 'consultas.bin' para armazenamento\n");
        exit(1);
    }

    if (c != NULL && c->consultas != NULL) {
        for (int i = 0; i < c->numeroConsultas; i++) {
            salvaConsultaComLesoes(c->consultas[i], consultasBin);
        }
    }

    fclose(consultasBin);

}

int recuperaMedicosBin(tClinica *c, char *path) {
    char caminho[1000];
    sprintf(caminho, "%s/medicos.bin", path);

    FILE *medicosBin = fopen(caminho, "rb");

    if (medicosBin == NULL) {
        //printf("Erro abrindo o arquivo 'medicos.bin' para leitura\n");
        return 0;
    }

    if (c != NULL && c->medicos != NULL) {
        for (int i = 0; i < c->numeroMedicos; i++) {
            c->medicos[i] = recuperaMedico(medicosBin);
        }
    }

    fclose(medicosBin);

    return 1;
}

void recuperaPacientesBin(tClinica *c, char *path){
    char caminho[1000];
    sprintf(caminho, "%s/pacientes.bin", path);

    FILE *pacientesBin = fopen(caminho, "rb");

    if (pacientesBin == NULL) {
        printf("Erro abrindo o arquivo 'pacientes.bin' para leitura\n");
        exit(1);
    }

    if (c != NULL && c->pacientes != NULL) {
        for (int i = 0; i < c->numeroPacientes; i++) {
            c->pacientes[i] = recuperaPaciente(pacientesBin);
        }
    }

    fclose(pacientesBin);
}

int recuperaSecretariosBin(tClinica *c, char *path){
    char caminho[1000];
    sprintf(caminho, "%s/secretarios.bin", path);

    FILE *secretariosBin = fopen(caminho, "rb");

    if (secretariosBin == NULL) {
        //printf("Erro abrindo o arquivo 'secretarios.bin' para leitura\n");
        return 0;
    }

    if (c != NULL && c->secretarios != NULL) {
        for (int i = 0; i < c->numeroSecretarios; i++) {
            c->secretarios[i] = recuperaSecretario(secretariosBin);
        }
    }

    fclose(secretariosBin);

    return 1;
}

/*void recuperaLesoesBin(tClinica *c, char *path){
    char caminho[1000];
    sprintf(caminho, "%s/lesoes.bin", path);

    FILE *secretariosBin = fopen(caminho, "rb");

    if (secretariosBin == NULL) {
        printf("Erro abrindo o arquivo 'secretarios.bin' para leitura\n");
        exit(1);
    }

    if (c != NULL && c->secretarios != NULL) {
        for (int i = 0; i < c->numeroSecretarios; i++) {
            c->secretarios[i] = recuperaSecretario(secretariosBin);
        }
    }

    fclose(secretariosBin);
}*/

void recuperaConsultasBin(tClinica *c, char *path){
    char caminho[1000];
    sprintf(caminho, "%s/consultas.bin", path);

    FILE *consultasBin = fopen(caminho, "rb");

    if (consultasBin == NULL) {
        printf("Erro abrindo o arquivo 'consultas.bin' para leitura\n");
        exit(1);
    }

    if (c != NULL && c->consultas != NULL) {
        for (int i = 0; i < c->numeroConsultas; i++) {
            c->consultas[i] = recuperaConsultaComLesoes(consultasBin);
        }
    }

    fclose(consultasBin);
}

tPaciente** obtemPacientes(tClinica* c) {
    return c->pacientes;
}

int obtemNumeroPacientes(tClinica* c){
    return c->numeroPacientes;
}

tPaciente* obtemPacientePeloCPF(char* CPF, tPaciente** pacientes, int numeroPacientes){
    for (int i = 0; i < numeroPacientes; i++) {
        if (!(strcmp(obtemCPFPaciente(pacientes[i]), CPF))) {
            return pacientes[i];
        }
    }
}