#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#
#include "tPaciente.h"
#include "tBiopsia.h"
#include "tConsulta.h"
#include "tMedico.h"
#include "tDocumento.h"
#include "tSecretario.h"
#include "tEncaminhamento.h"
#include "tFila.h"
#include "tLesao.h"
#include "tListaBusca.h"
#include "tReceita.h"
#include "tRelatorio.h"
#include "tClinica.h"


typedef struct tSistema {
    tClinica* clinica;
    char* path_db;
    char* path_arq;
} tSistema;


/**
 * Função que cria uma pessoa e retorna um ponteiro para ela.
 */
tSistema* criaSistema(char* path_db, char* path){
    tSistema* sistema = (tSistema*)calloc(1, sizeof(tSistema));
    sistema->clinica = criaClinica();

    char path_arq[1000];
    char path_base[1000];

    sprintf(path_arq, "%s/saida", path);
    sprintf(path_base, "%s/%s", path, path_db);


    sistema->path_db = path_base;
    sistema->path_arq = path_arq;
    return sistema;
    //if (!recuperaMedicosBin(sistema->clinica, path_db) && !recuperaSecretariosBin(sistema->clinica, path_db)){
}

void cadastraSecretario(tSistema* s){
    char nome[101];
    char cpf[15];
    char dataNascimento[11];
    char telefone[15];
    char genero[10];
    eGenero gen;
    char username[21];
    char senha[21];
    char nivel[6];
    eAcesso nivelAcesso;    
    if (s!=NULL){

        printf("#################### CADASTRO SECRETARIO #######################\n");
        printf("NOME COMPLETO: ");
        scanf("%100s", &(nome));
        printf("\nCPF: ");
        scanf("%14s", &(cpf));
        printf("\nDATA DE NASCIMENTO: ");
        scanf("%10s", &(dataNascimento));
        printf("\nTELEFONE: ");
        scanf("%14s", &(telefone));
        printf("\nGENERO: ");
        scanf("%10s", &(genero));
        if (!strcmp(genero, "MASCULINO")){
            gen = MASCULINO;
        }
        else if (!strcmp(genero, "FEMININO")){
            gen = FEMININO;
        }
        if (!strcmp(genero, "OUTROS")){
            gen = OUTROS;
        }
        printf("\nNOME DE USUARIO: ");
        scanf("%20s", &(username));
        printf("\nSENHA: ");
        scanf("%20s", &(senha));
        printf("\nNIVEL DE ACESSO: ");
        scanf("%5s", &(nivel));
        if (!strcmp(genero, "ADMIN")){
            nivelAcesso = ADMIN;
        }
        else if (!strcmp(genero, "USER")){
            nivelAcesso = USER;
        }
        adicionaSecretario(s->clinica, nome, cpf, dataNascimento, telefone, gen, 
        username, senha, nivelAcesso);

        printf("\n\nCADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\n VOLTAR AO MENU INICIAL\n");
        printf("###############################################################");

    }
}

void cadastraMedico(tSistema* s) {
    char nome[101];
    char cpf[15];
    char dataNascimento[11];
    char telefone[15];
    char genero[10];
    eGenero gen;
    char CRM[13];
    char username[21];
    char senha[21]; 
    if (s!=NULL){

        printf("#################### CADASTRO MEDICO #######################\n");
        printf("NOME COMPLETO: ");
        scanf("%100s", &(nome));
        printf("\nCPF: ");
        scanf("%14s", &(cpf));
        printf("\nDATA DE NASCIMENTO: ");
        scanf("%10s", &(dataNascimento));
        printf("\nTELEFONE: ");
        scanf("%14s", &(telefone));
        printf("\nGENERO: ");
        scanf("%10s", &(genero));
        if (!strcmp(genero, "MASCULINO")){
            gen = MASCULINO;
        }
        else if (!strcmp(genero, "FEMININO")){
            gen = FEMININO;
        }
        if (!strcmp(genero, "OUTROS")){
            gen = OUTROS;
        }
        printf("\nCRM: ");
        scanf("%12s", &(CRM));
        printf("\nNOME DE USUARIO: ");
        scanf("%20s", &(username));
        printf("\nSENHA: ");
        scanf("%20s", &(senha));

        adicionaMedico(s->clinica, nome, cpf, dataNascimento, telefone, gen,
        CRM, username, senha);
        

        printf("\n\nCADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\n VOLTAR AO MENU INICIAL\n");
        printf("###############################################################");

    }
}

void cadastraPaciente(tSistema* s) {
    char nome[101];
    char cpf[15];
    char dataNascimento[11];
    char telefone[15];
    char genero[10];
    eGenero gen;
    if (s!=NULL){

        printf("#################### CADASTRO MEDICO #######################\n");
        printf("NOME COMPLETO: ");
        scanf("%100s", &(nome));
        printf("\nCPF: ");
        scanf("%14s", &(cpf));
        printf("\nDATA DE NASCIMENTO: ");
        scanf("%10s", &(dataNascimento));
        printf("\nTELEFONE: ");
        scanf("%14s", &(telefone));
        printf("\nGENERO: ");
        scanf("%10s", &(genero));
        if (!strcmp(genero, "MASCULINO")){
            gen = MASCULINO;
        }
        else if (!strcmp(genero, "FEMININO")){
            gen = FEMININO;
        }
        else if (!strcmp(genero, "OUTROS")){
            gen = OUTROS;
        }

        adicionaPaciente(s->clinica, nome, cpf, dataNascimento, telefone, gen);
        

        printf("\n\nCADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\n VOLTAR AO MENU INICIAL\n");
        printf("###############################################################");

    }
}

void cadastraLesaoConsulta(tConsulta* c){
    if (c != NULL){
        printf("#################### CONSULTA MEDICA #######################\nCADASTRO DE LESAO:\n");
        char diag[26];
        char reg[16];
        int tamanho;
        int cirurgia;
        int crioterapia;
        eRegiao regiao;
        eDiagnostico diagnostico;

        printf("DIAGNOSTICO CLINICO: ");
        scanf("%25s", &(diag));

        if (!strcmp(diag, "CARCINOMA BASOCELULAR")){
            diagnostico = CARCINOMA_BASOCELULAR;
        }
        else if (!strcmp(diag, "CARCINOMA ESPINOCELULAR")){
            diagnostico = CARCINOMA_ESPINOCELULAR;
        }
        else if (!strcmp(diag, "MELANOMA")){
            diagnostico = MELANOMA;
        }
        else if (!strcmp(diag, "CERATOSE ACTINICA")){
            diagnostico = CERATOSE_ACTINICA;
        }
        else if (!strcmp(diag, "NEVO")){
            diagnostico = NEVO;
        }
        else if (!strcmp(diag, "CERATOSE SEBORREICA")){
            diagnostico = CERATOSE_SEBORREICA;
        }
        else if (!strcmp(diag, "OUTROS")){
            diagnostico = OUTRO_DIAGNOSTICO;
        }


        printf("\nREGIAO DO CORPO: ");
        scanf("%15s", &(reg));

        if (!strcmp(reg, "FACE")){
            regiao = FACE;
        }
        else if (!strcmp(reg, "ORELHA")){
            regiao = ORELHA;
        }
        else if (!strcmp(reg, "COURO CABELUDO")){
            regiao = COURO_CAB;
        }
        else if (!strcmp(reg, "PEITORAL")){
            regiao = PEITORAL;
        }
        else if (!strcmp(reg, "DORSO")){
            regiao = DORSO;
        }
        else if (!strcmp(reg, "ABDOME")){
            regiao = ABDOME;
        }
        else if (!strcmp(reg, "BRAÇO")){
            regiao = BRACO;
        }
        else if (!strcmp(reg, "ANTEBRAÇO")){
            regiao = ANTEBRACO;
        }
        else if (!strcmp(reg, "MAO")){
            regiao = MAO;
        }
        else if (!strcmp(reg, "COXA")){
            regiao = COXA;
        }
        else if (!strcmp(reg, "CANELA")){
            regiao = CANELA;
        }
        else if (!strcmp(reg, "PE")){
            regiao = PE;
        }
        else if (!strcmp(reg, "OUTROS")){
            regiao = OUTRA_REGIAO;
        }



        printf("\nTAMANHO: ");
        scanf("%d", &(tamanho));
        printf("\nENVIAR PARA CIRURGIA: ");
        scanf("%d", &(cirurgia));
        printf("\nENVIAR PARA CRIOTERAPIA: ");
        scanf("%d", &(crioterapia));

        char rotulo[6];
        sprintf(rotulo, "L%d", obtemNumeroLesoes(c)+1);

        cadastraLesao(c, rotulo, diagnostico, regiao, tamanho, cirurgia, crioterapia);

        printf("\n\nLESAO REGISTRADA COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\n VOLTAR AO MENU INICIAL\n");
        printf("###############################################################");

        scanf("%*c");
        return;
    }
}

void geraReceitaMedica(tConsulta* c);

void geraBiopsia(tConsulta* c);

void geraEncaminhamento(tConsulta* c);

int exibeMenuConsulta(){
    int opcao = 0;
    printf("#################### CONSULTA MEDICA #######################\n");
    printf("ESCOLHA UMA OPCAO:\n");
    printf("(1) CADASTRAR LESAO\n(2) GERAR RECEITA MEDICA\n(3) SOLICITACAO DE BIOPSIA\n (4) ENCAMINHAMENTO\n (5) ENCERRAR CONSULTA\n");
    printf("############################################################\n");
    scanf("%d", &(opcao));
    return opcao;
}

void executaMenuConsulta(tConsulta* c, int opcao){
    if (opcao == 1){
        cadastraLesaoConsulta(c);
    }
    else if (opcao == 2) {
        geraReceitaMedica(c);
    }
    else if (opcao == 3){
        geraBiopsia(c);
    }
    else if (opcao == 4){
        geraEncaminhamento(c);
    }
    else if (opcao == 5){
        return;
    }
}

void realizaConsulta(tSistema* s){
    if (s!=NULL) {
        char cpf[15];
        printf("#################### CONSULTA MEDICA #######################\n");
        printf("CPF DO PACIENTE: ");
        scanf("%14s", &(cpf));
        int pacienteExiste = verificaCPF(cpf,obtemPacientes(s->clinica), obtemNumeroPacientes(s->clinica));

        if (pacienteExiste){
            tPaciente* paciente = obtemPacientePeloCPF(cpf, obtemPacientes(s->clinica), obtemNumeroPacientes(s->clinica));
            printf("\n---");
            printf("\n- NOME: %s\n", obtemNomePaciente(paciente));
            printf("- DATA DE NASCIMENTO: %s\n", obtemDataNascimentoPaciente(paciente));
            printf("---\n");

            char dataConsulta[11];
            int diabetico;
            int fumante;
            int alergico;
            int canceroso;
            etipoPele tipoPele;
            char pele[3];

            printf("DATA DA CONSULTA: ");
            scanf("%10s", &(dataConsulta));
            printf("\nPOSSUI DIABETES: ");
            scanf("%d", &(diabetico));
            printf("\nFUMANTE: ");
            scanf("%d", &(fumante));
            printf("\nALERGIA A MEDICAMENTO: ");
            scanf("%d", &(alergico));
            printf("\nHISTORICO DE CANCER: ");
            scanf("%d", &(canceroso));
            printf("\nTIPO DE PELE: ");
            scanf("%2s", &(pele));

            if (!strcmp(pele, "I")){
                tipoPele = UM;
            }
            else if (!strcmp(pele, "II")){
                tipoPele = DOIS;
            }
            else if (!strcmp(pele, "III")){
                tipoPele = TRES;
            }   
            else if (!strcmp(pele, "IV")){
                tipoPele = QUATRO;
            }
            else if (!strcmp(pele, "V")){
                tipoPele = CINCO;
            }   
            else if (!strcmp(pele, "VI")){
                tipoPele = SEIS;
            }   

            printf("############################################################\n");

            adicionaConsulta(s->clinica, cpf, dataConsulta);
            
            int opcao = exibeMenuConsulta();

            tConsulta* consulta = obtemConsulta(s->clinica, dataConsulta);
        }

        else if (!pacienteExiste){
            printf("\nPACIENTE SEM CADASTRO\n\n");
            printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU INICIAL\n");
            printf("############################################################");
            return;
        }
    }
}

/**
 * Função que recebe um ponteiro para uma pessoa e desaloca toda a memória
 * associada a ela.
 * Essa função sempre verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaSistema();

void realizaLogin(tSistema* sist);

tRelatorio* calculaRelatorio(tClinica* c);

/**
 * 
*/
void executaRelatorio();

void SalvaBancoDeDados(tSistema* sist);
