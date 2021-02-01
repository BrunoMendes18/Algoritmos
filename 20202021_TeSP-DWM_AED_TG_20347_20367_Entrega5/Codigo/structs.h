#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef struct 
{
    int sns;
    char nome[50];
    int idade;
    char genero;
    char email[100];
}Utente;

typedef struct 
{
    int id;
    char nome[50];
    int idade;
    char genero;
    char email[100];
    float vencimento;
     int idClinica;
     int nConsultas;
     Utente agenda[];
}Medico;


typedef struct 
{
    int id;
    char nome[50];
    int idade;
    char genero;
    char email[100];
    float vencimento;
    int idClinica;
    int nConsultas;
    Utente agenda[];   
    
}Enfermeiro;

typedef struct 
{
    int id;
    char nome[50];
    int idade;
    char genero;
    char email[100];
    float vencimento;
    int idClinica;
}Auxiliar;



typedef struct 
{
    int id;
    char nome[50];
    char localizacao[50];
    char contacto[9];
    int numeroMedicos;
    Medico medicos[10];
    int numeroEnfermeiros;
    Enfermeiro enfermeiros[10];
    int numeroAuxiliares;
    Auxiliar axuliares[10];

}Clinica;



#endif