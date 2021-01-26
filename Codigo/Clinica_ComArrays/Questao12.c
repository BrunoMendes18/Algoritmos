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
    Auxiliar auxiliares[TAMAUXILIARES],auxiliar;
    Cliente clientes[TAMCLIENTES],cliente;

    int nClinicas=0,nMedicos=0,nEnfermeiros=0,nAuxiliares=0,nClientes,resultadoClin,resultadoMed,resultadoEnf,resultadoAux,resultadoClien;
    int MenuResult=0;

while(MenuResult!=8)
{
    printf("Menu Clinica:\n1-Criar Clinica\n2-Inserir medico\n3-Inserir enfermeiro\n4-Inserir auxiliar\n5-Inserir Cliente\n6-Marcar Consula Medica\n7-Marcar consulta enfermagem\n8-Sair\n");
    scanf("%d",&MenuResult);
    switch (MenuResult)
    {
    case 1:
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
        break;
    case 2:
    criarMedico(&medico,nMedicos);

    resultadoMed=inserirMedico(medicos,&nMedicos,medico,clinicas,nClinicas);

    if(resultadoMed)
    {
        printf("Medico criado com sucesso!");
    }
    else
    {
        printf("Ocorreu um erro!!");
    }
    break;

    case 3:
    criarEnfermeiro(&enfermeiro,nEnfermeiros);

    resultadoEnf=inserirEnfermeiro(enfermeiros,&nEnfermeiros,enfermeiro,clinicas,nClinicas);

    if(resultadoEnf)
    {
        printf("Enfermeiro criado com sucesso!");
    }
    else
    {
        printf("Ocorreu um erro!!");
    }
    break;

    case 4:
    criarAuxiliar(&auxiliar,nAuxiliares);

    resultadoAux=inserirAuxiliar(auxiliares,&nAuxiliares,auxiliar,clinicas,nClinicas);

    if(resultadoAux)
    {
        printf("Auxiliar criada com sucesso!");
    }
    else
    {
        printf("Ocorreu um erro!!");
    }
    break;

    case 5:
criarCliente(&cliente,nClientes);

    resultadoClien=inserirCliente(clientes,&nClientes,cliente);

    if(resultadoClien)
    {
        printf("Cliente criado com sucesso!");
    }
    else
    {
        printf("Ocorreu um erro!!");
    }
    break;

    case 6:
    break;
    case 7: 
    break;

    case 8:
    printf("Saiu");
    break;
    default:
    printf("Operacao invalida");
        break;
    }
}
    
    
    

    

    listarClinicas(clinicas,nClinicas);

    

    //listarMedico(medicos,nMedicos);

    

    //listarEnfermeiros(enfermeiros,nEnfermeiros);

    

    //listarAuxiliares(auxiliares,nAuxiliares);

    

    listarClientes(clientes,nClientes);

    getchar();

    return 0;

}

void criarClinica(Clinica *clinica,int n)
{
    printf("Criar Clinica:");
    fflush(stdin);
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
    clinica->numeroMedicos=-1;
    clinica->numeroEnfermeiros=-1;
    clinica->numeroAuxiliares=-1;
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
    fflush(stdin);
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

    //Nao tem validacoes esperemos que o utilizador ponha um id valido
    printf("Associar Clinica(id): ");
    scanf("%d",&medico->idClinica);
    fflush(stdin);

    medico->id=n+1;
}

int inserirMedico(Medico *medicos, int *n,Medico medico,Clinica *clinicas,int *nclinicas)
{
    if(*n>TAMMEDICOS)
    {
        return 0;
    }

    for(int i=0;i<nclinicas;i++)
    {
        if(clinicas[i].id == medico.idClinica)
        {
            clinicas[i].numeroMedicos = clinicas[i].numeroMedicos +1;
            clinicas[i].medicos[clinicas[i].numeroMedicos]=medico;
            
        }
    }

    medicos[*n]=medico;
    (*n)++;

    return 1;
}

void criarEnfermeiro(Enfermeiro *enfermeiro,int n)
{
    printf("\nCriar enfermeiro:");
    fflush(stdin);
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

    printf("Associar Clinica(id): ");
    scanf("%d",&enfermeiro->idClinica);
    fflush(stdin);

    enfermeiro->id=n+1;
}

int inserirEnfermeiro(Enfermeiro *enfermeiros, int *n,Enfermeiro enfermeiro,Clinica *clinicas,int *nclinicas)
{
    if(*n>TAMENFERMEIROS)
    {
        return 0;
    }

    for(int i=0;i<nclinicas;i++)
    {
        if(clinicas[i].id == enfermeiro.idClinica)
        {
            clinicas[i].numeroEnfermeiros = clinicas[i].numeroEnfermeiros +1;
            clinicas[i].enfermeiros[clinicas[i].numeroEnfermeiros]=enfermeiro;
            
        }
    }

    enfermeiros[*n]=enfermeiro;
    (*n)++;

    return 1;
}


void criarAuxiliar(Auxiliar *auxiliar,int n)
{
    printf("\nCriar auxiliar:");
    fflush(stdin);
    printf("\nNOME: ");
    fgets(auxiliar->nome,50,stdin);
    auxiliar->nome[strlen(auxiliar->nome) - 1]='\0';

    printf("IDADE: ");
    scanf("%d",&auxiliar->idade);
    fflush(stdin);

    printf("GENERO (M/F): ");
    scanf("%c",&auxiliar->genero);
    fflush(stdin);

    printf("EMAIL: ");
    fgets(auxiliar->email,100,stdin);
    auxiliar->email[strlen(auxiliar->email) - 1]='\0';
    fflush(stdin);

    printf("VENCIMENTO: ");
    scanf("%f",&auxiliar->vencimento);
    fflush(stdin);

    printf("Associar Clinica(id): ");
    scanf("%d",&auxiliar->idClinica);
    fflush(stdin);

    auxiliar->id=n+1;
}

int inserirAuxiliar(Auxiliar *auxiliares, int *n,Auxiliar auxiliar,Clinica *clinicas,int *nclinicas)
{
    if(*n>TAMAUXILIARES)
    {
        return 0;
    }

    for(int i=0;i<nclinicas;i++)
    {
        if(clinicas[i].id == auxiliar.idClinica)
        {
            clinicas[i].numeroAuxiliares = clinicas[i].numeroAuxiliares +1;
            clinicas[i].axuliares[clinicas[i].numeroAuxiliares]=auxiliar;
            
        }
    }

    auxiliares[*n]=auxiliar;
    (*n)++;

    return 1;
}

void criarCliente(Cliente *cliente,int n)
{
    printf("\nCriar cliente:");
    fflush(stdin);
    
    printf("SNS: ");
    scanf("%f",&cliente->sns);
    fflush(stdin);

    printf("\nNOME: ");
    fgets(cliente->nome,50,stdin);
    cliente->nome[strlen(cliente->nome) - 1]='\0';

    printf("IDADE: ");
    scanf("%d",&cliente->idade);
    fflush(stdin);

    printf("GENERO (M/F): ");
    scanf("%c",&cliente->genero);
    fflush(stdin);

    printf("EMAIL: ");
    fgets(cliente->email,100,stdin);
    cliente->email[strlen(cliente->email) - 1]='\0';
    fflush(stdin);

}

int inserirCliente(Cliente *clientes, int *n,Cliente cliente)
{
    if(*n>TAMCLIENTES)
    {
        return 0;
    }

    clientes[*n]=cliente;
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
        //printf("\n%s",clinicas[i].medicos[0].nome);
        //printf("\n%s",clinicas[i].medicos[1].nome); 
        for(int j=0;j<=clinicas[i].numeroMedicos;j++)
        {
            //so mostra o nome para nao ficar enorme na consola depois pomos o resto
            printf("\n%s",clinicas[i].medicos[j].nome);
        }  
        for(int j=0;j<=clinicas[i].numeroEnfermeiros;j++)
        {
            //so mostra o nome para nao ficar enorme na consola depois pomos o resto
            printf("\n%s",clinicas[i].enfermeiros[j].nome);
        } 
        for(int j=0;j<=clinicas[i].numeroAuxiliares;j++)
        {
            //so mostra o nome para nao ficar enorme na consola depois pomos o resto
            printf("\n%s",clinicas[i].axuliares[j].nome);
        }          
           
        
        
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
        printf("\n%d",medicos[i].idClinica);
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

void listarAuxiliares(Auxiliar *auxilares,int *n)
{
   for (int i = 0; i < n; i++)
    {
        printf("\n%d",auxilares[i].id);
        printf("\n%s",auxilares[i].nome);
        printf("\n%d",auxilares[i].idade);
        printf("\n%c",auxilares[i].genero);
        printf("\n%s",auxilares[i].email);
        printf("\n%.2f",auxilares[i].vencimento);
    }
    
}

void listarClientes(Cliente *clientes,int *n)
{
   for (int i = 0; i < n; i++)
    {
         printf("\n%d",clientes[i].sns);
        printf("\n%s",clientes[i].nome);
        printf("\n%d",clientes[i].idade);
        printf("\n%c",clientes[i].genero);
        printf("\n%s",clientes[i].email);
       
    }
    
}