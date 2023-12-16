


#ifndef _TCLINICA_H_
#define _TCLINICA_H_

#include "tPaciente.h"
#include "tMedico.h"
#include "tSecretario.h"
#include "tLesao.h"
#include "tConsulta.h"

typedef struct tClinica tClinica;

tClinica* criaClinica();

int verificaCPF(char* CPF, tPaciente** pacientes, int numeroPacientes);

void adicionaSecretario(tClinica*c, char* nome, char* cpf, char* dataNascimento, 
    char* telefone, eGenero genero, char* username, char* senha, eAcesso acesso);

void adicionaPaciente(tClinica*c, char* nome, char* cpf, char* dataNascimento, 
char* telefone, eGenero genero);

void adicionaMedico(tClinica*c, char* nome, char* cpf, char* dataNascimento, 
char* telefone, eGenero genero, char* CRM, char* username, char* senha);

void adicionaConsulta(tClinica*c, char* cpfPaciente, char* dataStr);

tConsulta* obtemConsulta(tClinica* c, char* dataStr);

void desalocaClinica(tClinica* c);

tLesao** obtemVetorLesoes(tConsulta** consultas, int numeroConsultas);

int obtemTamanhoVetorLesoes(tConsulta** consultas, int numeroConsultas);

void salvaMedicosBin(tClinica *c, char *path);

void salvaPacientesBin(tClinica *c, char *path);

void salvaSecretariosBin(tClinica *c, char *path);

void salvaLesoesBin(tClinica *c, char *path);

void salvaConsultasBin(tClinica *c, char *path);

int recuperaMedicosBin(tClinica *c, char *path);

void recuperaPacientesBin(tClinica *c, char *path);

int recuperaSecretariosBin(tClinica *c, char *path);

void recuperaConsultasBin(tClinica *c, char *path);

tPaciente** obtemPacientes(tClinica* c);

int obtemNumeroPacientes(tClinica* c);

tPaciente* obtemPacientePeloCPF(char* CPF, tPaciente** pacientes, int numeroPacientes);

#endif