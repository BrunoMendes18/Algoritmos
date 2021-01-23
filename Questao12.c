#include <stdio.h>
#include <string.h>
#include "structs.h"

#define TAMCLINICAS 50
#define TAMMEDICOS 200
#define TAMENFERMEIROS 200
#define TAMAUXILIARES 200
#define TAMCLIENTES 200

int main(int argc,char const*argv[])
{
    Clinica clinicas[TAMCLINICAS],clinica;
    Medico medicos[TAMMEDICOS],medico;
    Enfermeiro enfermeiros[TAMENFERMEIROS],enfermeiro;
    Auxiliar auxiliares[TAMAUXILIARES];
    Cliente clientes[TAMCLIENTES];

    //Ver se tenho permissao

    int nClinicas=0,nMedicos=0,nEnfermeiros=0,resultadoClin,resultadoMed,resultadoEnf;

    criarClinica(&clinica,nClinicas);

    resultadoClin=inserirClinica(clinicas,&nClinicas,clinica);

    if(resultadoClin)
    {
        printf("Clinica criada com sucesso!");
    }
    else
    {
        printf("Ocorreu um erro!!");
    }

    listarClinicas(clinicas,nClinicas);

    criarMedico(&medico,nMedicos);

    resultadoMed=inserirMedico(medicos,&nMedicos,medico);

    if(resultadoMed)
    {
        printf("Medico criado com sucesso!");
    }
    else
    {
        printf("Ocorreu um erro!!");
    }

    listarMedico(medicos,nMedicos);

    criarEnfermeiro(&enfermeiro,nEnfermeiros);

    resultadoEnf=inserirEnfermeiro(enfermeiros,&nEnfermeiros,enfermeiro);

    if(resultadoEnf)
    {
        printf("Enfermeiro criado com sucesso!");
    }
    else
    {
        printf("Ocorreu um erro!!");
    }

    listarEnfermeiros(enfermeiros,nEnfermeiros);

    getchar();

    return 0;

}

void criarClinica(Clinica *clinica,int n)
{
    printf("Criar Clinica:");
    printf("\nNOME: ");
    fgets(clinica->nome,50,stdin);
    clinica->nome[strlen(clinica->nome) - 1]='\0';
    /*fflush(stdin);*/

    printf("LOCALIZACAO: ");
    fgets(clinica->localizacao,50,stdin);
    clinica->localizacao[strlen(clinica->localizacao) - 1]='\0';
    /*fflush(stdin);*/

    printf("CONTACTO: ");
    fgets(clinica->contacto,11,stdin);
    clinica->contacto[strlen(clinica->contacto) - 1]='\0';
    fflush(stdin);

    clinica->id=n+1;
}

int inserirClinica(Clinica *clinicas, int *n,Clinica clinica)
{
    if(*n>TAMCLINICAS)
    {
        return 0;
    }

    clinicas[*n]=clinica;
    (*n)++;

    return 1;
}

void criarMedico(Medico *medico,int n)
{
    printf("\nCriar Medico:");
    printf("\nNOME: ");
    fgets(medico->nome,50,stdin);
    medico->nome[strlen(medico->nome) - 1]='\0';

    printf("IDADE: ");
    scanf("%d",&medico->idade);
    fflush(stdin);

    printf("GENERO (M/F): ");
    scanf("%c",&medico->genero);
    fflush(stdin);

    printf("EMAIL: ");
    fgets(medico->email,100,stdin);
    medico->email[strlen(medico->email) - 1]='\0';
    fflush(stdin);

    printf("VENCIMENTO: ");
    scanf("%f",&medico->vencimento);
    fflush(stdin);

    medico->id=n+1;
}

int inserirMedico(Medico *medicos, int *n,Medico medico)
{
    if(*n>TAMMEDICOS)
    {
        return 0;
    }

    medicos[*n]=medico;
    (*n)++;

    return 1;
}

void criarEnfermeiro(Enfermeiro *enfermeiro,int n)
{
    printf("\nCriar enfermeiro:");
    printf("\nNOME: ");
    fgets(enfermeiro->nome,50,stdin);
    enfermeiro->nome[strlen(enfermeiro->nome) - 1]='\0';

    printf("IDADE: ");
    scanf("%d",&enfermeiro->idade);
    fflush(stdin);

    printf("GENERO (M/F): ");
    scanf("%c",&enfermeiro->genero);
    fflush(stdin);

    printf("EMAIL: ");
    fgets(enfermeiro->email,100,stdin);
    enfermeiro->email[strlen(enfermeiro->email) - 1]='\0';
    fflush(stdin);

    printf("VENCIMENTO: ");
    scanf("%f",&enfermeiro->vencimento);
    fflush(stdin);

    enfermeiro->id=n+1;
}

int inserirEnfermeiro(Enfermeiro *enfermeiros, int *n,Enfermeiro enfermeiro)
{
    if(*n>TAMENFERMEIROS)
    {
        return 0;
    }

    enfermeiros[*n]=enfermeiro;
    (*n)++;

    return 1;
}

void listarClinicas(Clinica *clinicas,int *n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n%d",clinicas[i].id);
        printf("\n%s",clinicas[i].nome);
        printf("\n%s",clinicas[i].localizacao);
        printf("\n%s",clinicas[i].contacto);
    }
    
}

void listarMedico(Medico *medicos,int *n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n%d",medicos[i].id);
        printf("\n%s",medicos[i].nome);
        printf("\n%d",medicos[i].idade);
        printf("\n%c",medicos[i].genero);
        printf("\n%s",medicos[i].email);
        printf("\n%.2f",medicos[i].vencimento);
    }
    
}

void listarEnfermeiros(Enfermeiro *enfermeiros,int *n)
{
   for (int i = 0; i < n; i++)
    {
        printf("\n%d",enfermeiros[i].id);
        printf("\n%s",enfermeiros[i].nome);
        printf("\n%d",enfermeiros[i].idade);
        printf("\n%c",enfermeiros[i].genero);
        printf("\n%s",enfermeiros[i].email);
        printf("\n%.2f",enfermeiros[i].vencimento);
    }
    
}