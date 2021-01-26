#ifndef STRUCTS_H_
#define STRUCTS_H_



typedef struct 
{
    int id;
    char nome[50];
    int idade;
    char genero;
    char email[100];
    float vencimento;
     int idClinica;
}Medico;

typedef struct 
{
    int id;
    char nome[50];
    char localizacao[50];
    char contacto[9];
    //Assim deu mesmo nao pondo tamanho xd
    Medico medicos[];
}Clinica;

typedef struct 
{
    int id;
    char nome[50];
    int idade;
    char genero;
    char email[100];
    float vencimento;
}Enfermeiro;

typedef struct 
{
    int id;
    char nome[50];
    int idade;
    char genero;
    char email[100];
    float vencimento;
}Auxiliar;

typedef struct 
{
    int sns;
    char nome[50];
    int idade;
    char genero;
    char email[100];
}Cliente;

#endif