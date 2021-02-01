#include <stdio.h>
#include <string.h>
#include "structs.h"

#define TAMCLINICAS 50
#define TAMMEDICOS 200
#define TAMENFERMEIROS 200
#define TAMAUXILIARES 200
#define TAMUTENTES 200

void criarClinica(Clinica *clinica, int n);
int inserirClinica(Clinica *clinicas, int *n, Clinica clinica);
void criarMedico(Medico *medico, int n);
int inserirMedico(Medico *medicos, int *n, Medico medico, Clinica *clinicas, int *nclinicas);
void criarEnfermeiro(Enfermeiro *enfermeiro, int n);
int inserirEnfermeiro(Enfermeiro *enfermeiros, int *n, Enfermeiro enfermeiro, Clinica *clinicas, int *nclinicas);
void criarAuxiliar(Auxiliar *auxiliar, int n);
int inserirAuxiliar(Auxiliar *auxiliares, int *n, Auxiliar auxiliar, Clinica *clinicas, int *nclinicas);
void criarUtente(Utente *utente, int n);
int verificarUtente(Utente *utentes, int *n, int *SNS);
int verificarMedico(Medico *medicos, int *n, int *ID);
int verificarEnfermeiro(Enfermeiro *enfermeiros, int *n, int *ID);
void inserirConsultaMedico(Clinica *clinicas, int *n, int *ID, Utente *utentes, int *nUtentes, int *SNS);
void inserirConsultaEnfermeiro(Clinica *clinicas, int *n, int *ID, Utente *utentes, int *nUtentes, int *SNS);
int inserirUtente(Utente *utentes, int *n, Utente utente);
void listarClinicas(Clinica *clinicas, int *n);
void listarMedico(Medico *medicos, int *n);
void listarEnfermeiros(Enfermeiro *enfermeiros, int *n);
void listarAuxiliares(Auxiliar *auxilares, int *n);
void listarUtentes(Utente *utentes, int *n);
void MediaIdadesMedicos(Clinica *clinicas, int n);
void MediaIdadesAuxiliares(Clinica *clinicas, int n);
void MediaIdadesEnfermeiros(Clinica *clinicas, int n);
void SomaVencimentosMedicosPorClinica(Clinica *clinicas, int n);
void SomaVencimentosAuxiliaresPorClinica(Clinica *clinicas, int n);
void SomaVencimentosEnfermeirosPorClinica(Clinica *clinicas, int n);
void SomaVencimentosGeneroMedico(Medico *medicos, int n);
void SomaVencimentosGeneroAuxiliar(Auxiliar *auxiliares, int n);
void SomaVencimentosGeneroEnfermeiro(Enfermeiro *enfermeiros, int n);

int main(int argc, char const *argv[])
{
    Clinica clinicas[TAMCLINICAS], clinica;
    Medico medicos[TAMMEDICOS], medico;
    Enfermeiro enfermeiros[TAMENFERMEIROS], enfermeiro;
    Auxiliar auxiliares[TAMAUXILIARES], auxiliar;
    Utente utentes[TAMUTENTES], utente;

     int nClinicas = 0, nMedicos = 0, nEnfermeiros = 0, nAuxiliares = 0, nUtentes = 0, resultadoClin, resultadoMed, resultadoEnf, resultadoAux, resultadoUtente;
    int MenuResult = 0;
    int MenuConsulta = 0;
    int sns, idmedico, idenfermeiro, idclinica, medenf;

    while (MenuResult != 8)
    {
        printf("\nMenu Clinica:\n1-Criar Clinica\n2-Inserir medico\n3-Inserir enfermeiro\n4-Inserir auxiliar\n5-Inserir Utente\n6-Marcar Consula Medica\n7-Marcar consulta enfermagem\n8-Consultar medicos\n9-Consultar enfermeiros\n10-Consultar Auxiliares\n11-Listagem\n12-Numero de compromissos\n13-Agenda do Medico ou Enfermeiro\n");
        scanf("%d", &MenuResult);
        switch (MenuResult)
        {
        case 1:
            criarClinica(&clinica, nClinicas);
            resultadoClin = inserirClinica(clinicas, &nClinicas, clinica);

            if (resultadoClin)
            {
                printf("Clinica criada com sucesso!");
            }
            else
            {
                printf("Ocorreu um erro!!");
            }
            break;
        case 2:
            criarMedico(&medico, nMedicos);

            resultadoMed = inserirMedico(medicos, &nMedicos, medico, clinicas, nClinicas);

            if (resultadoMed)
            {
                printf("Medico criado com sucesso!");
            }
            else
            {
                printf("Ocorreu um erro!!");
            }
            break;

        case 3:
            criarEnfermeiro(&enfermeiro, nEnfermeiros);

            resultadoEnf = inserirEnfermeiro(enfermeiros, &nEnfermeiros, enfermeiro, clinicas, nClinicas);

            if (resultadoEnf)
            {
                printf("Enfermeiro criado com sucesso!");
            }
            else
            {
                printf("Ocorreu um erro!!");
            }
            break;

        case 4:
            criarAuxiliar(&auxiliar, nAuxiliares);

            resultadoAux = inserirAuxiliar(auxiliares, &nAuxiliares, auxiliar, clinicas, nClinicas);

            if (resultadoAux)
            {
                printf("Auxiliar criada com sucesso!");
            }
            else
            {
                printf("Ocorreu um erro!!");
            }
            break;

        case 5:
            criarUtente(&utente, nUtentes);

            resultadoUtente = inserirUtente(utentes, &nUtentes, utente);

            if (resultadoUtente)
            {
                printf("Utente criado com sucesso!");
            }
            else
            {
                printf("Ocorreu um erro!!");
            }
            break;

        case 6:
            printf("\nNumero sns:");
            scanf("%d", &sns);
            int resultado = verificarUtente(utentes, nUtentes, sns);
            if (resultado == 0)
            {
                printf("\nId do medico:");
                scanf("%d", &idmedico);
                int resultado2 = verificarMedico(medicos, nMedicos, idmedico);
                if (resultado2 == -2)
                    printf("erro");

                else
                    //Clinica *clinicas,int *n,int *ID,Utente *utentes,int *nUtentes,int *SNS
                    inserirConsultaMedico(clinicas, nClinicas, idmedico, utentes, nUtentes, sns);
            }
            else if (resultado == 1)
            {

                printf("\nUtente nao existe, crie um primeiro");
            }
            else
            {
                printf("Ocurreu um erro");
            }
            break;
        case 7:
            printf("\nNumero sns:");
            scanf("%d", &sns);
            int resultado3 = verificarUtente(utentes, nUtentes, sns);
            if (resultado3 == 0)
            {
                printf("\nId do enfermeiro:");
                scanf("%d", &idenfermeiro);
                int resultado4 = verificarEnfermeiro(enfermeiros, nEnfermeiros, idenfermeiro);
                if (resultado4 == -2)
                    printf("erro");

                else
                    //Clinica *clinicas,int *n,int *ID,Utente *utentes,int *nUtentes,int *SNS
                    inserirConsultaEnfermeiro(clinicas, nClinicas, idenfermeiro, utentes, nUtentes, sns);
            }
            else if (resultado3 == 1)
            {

                printf("\nUtente nao existe, crie um primeiro");
            }
            else
            {
                printf("Ocurreu um erro");
            }

            break;
        case 8:

            MediaIdadesMedicos(clinicas, nClinicas);
            SomaVencimentosGeneroMedico(medicos, nMedicos);

            break;

        case 9:
            MediaIdadesEnfermeiros(clinicas, nClinicas);
            SomaVencimentosGeneroEnfermeiro(enfermeiros, nEnfermeiros);
            break;

        case 10:

            MediaIdadesAuxiliares(clinicas, nClinicas);
            SomaVencimentosGeneroAuxiliar(auxiliares, nAuxiliares);
            break;

        case 11:

            SomaVencimentosMedicosPorClinica(clinicas, nClinicas);
            SomaVencimentosEnfermeirosPorClinica(enfermeiros, nEnfermeiros);
            SomaVencimentosAuxiliaresPorClinica(auxiliares, nAuxiliares);
            break;
        case 12:
            printf("\nClinica:");
            scanf("%d", &idclinica);
            int resul = verificarClinica(clinicas, nClinicas, idclinica);
            if (resul == 0)
            {
                CompromissosAgenda(clinicas, nClinicas, idclinica);
            }
            else if (resul == 1)
            {

                printf("\nClinica nao existe, crie um primeiro");
            }
            else
            {
                printf("Ocurreu um erro");
            }

            break;

        case 13:
            printf("\nMedico-1 ou Enfermeiro2: ");
            scanf("%d", &medenf);

            if (medenf == 1)
            {
                printf("\nId do medico:");
                scanf("%d", &idmedico);
                int resultado5 = verificarMedico(medicos, nMedicos, idmedico);
                if (resultado5 == -2)
                    printf("erro");

                else

                    listarAgendaMedico(medicos, nMedicos, idmedico, utentes, nUtentes);
            }
            else
            {
                int resultado6 = verificarEnfermeiro(enfermeiros,nEnfermeiros,idmedico);
                if (resultado6 == -2)
                    printf("erro");

                else

                    listarAgendaEnfermeiro(enfermeiros,nEnfermeiros,idmedico,utentes,nUtentes);

            }

            break;
        default:
            printf("Operacao invalida");
            break;
        }
    }

    //listarClinicas(clinicas,nClinicas);

    //listarMedico(medicos,nMedicos);

    //listarEnfermeiros(enfermeiros,nEnfermeiros);

    //listarAuxiliares(auxiliares,nAuxiliares);

    //listarUtentes(utentes,nUtentes);

    getchar();

    return 0;
}

void criarClinica(Clinica *clinica, int n)
{
    printf("Criar Clinica:");
    fflush(stdin);
    printf("\nNOME: ");
    fgets(clinica->nome, 50, stdin);
    clinica->nome[strlen(clinica->nome) - 1] = '\0';
    /*fflush(stdin);*/

    printf("LOCALIZACAO: ");
    fgets(clinica->localizacao, 50, stdin);
    clinica->localizacao[strlen(clinica->localizacao) - 1] = '\0';
    /*fflush(stdin);*/

    printf("CONTACTO: ");
    fgets(clinica->contacto, 11, stdin);
    clinica->contacto[strlen(clinica->contacto) - 1] = '\0';
    fflush(stdin);

    clinica->id = n + 1;
    clinica->numeroMedicos = -1;
    clinica->numeroEnfermeiros = -1;
    clinica->numeroAuxiliares = -1;
}

int inserirClinica(Clinica *clinicas, int *n, Clinica clinica)
{
    if (*n > TAMCLINICAS)
    {
        return 0;
    }

    clinicas[*n] = clinica;
    (*n)++;

    return 1;
}

void criarMedico(Medico *medico, int n)
{
    printf("\nCriar Medico:");
    fflush(stdin);
    printf("\nNOME: ");
    fgets(medico->nome, 50, stdin);
    medico->nome[strlen(medico->nome) - 1] = '\0';

    printf("IDADE: ");
    scanf("%d", &medico->idade);
    fflush(stdin);

    printf("GENERO (M/F): ");
    scanf("%c", &medico->genero);
    fflush(stdin);

    printf("EMAIL: ");
    fgets(medico->email, 100, stdin);
    medico->email[strlen(medico->email) - 1] = '\0';
    fflush(stdin);

    printf("VENCIMENTO: ");
    scanf("%f", &medico->vencimento);
    fflush(stdin);

    //Nao tem validacoes esperemos que o utilizador ponha um id valido
    printf("Associar Clinica(id): ");
    scanf("%d", &medico->idClinica);
    fflush(stdin);

    medico->id = n + 1;
    medico->nConsultas = -1;
}

int inserirMedico(Medico *medicos, int *n, Medico medico, Clinica *clinicas, int *nclinicas)
{
    if (*n > TAMMEDICOS)
    {
        return 0;
    }

    for (int i = 0; i < nclinicas; i++)
    {
        if (clinicas[i].id == medico.idClinica)
        {
            clinicas[i].numeroMedicos = clinicas[i].numeroMedicos + 1;
            clinicas[i].medicos[clinicas[i].numeroMedicos] = medico;
        }
    }

    medicos[*n] = medico;
    (*n)++;

    return 1;
}

int verificarClinica(Clinica *clinicas, int *n, int *idclinica)
{
    for (int i = 0; i <= n; i++)
    {
        if (clinicas[i].id == idclinica)
        {
            return 0;
        }
    }

    return 1;
}


void criarEnfermeiro(Enfermeiro *enfermeiro, int n)
{
    printf("\nCriar enfermeiro:");
    fflush(stdin);
    printf("\nNOME: ");
    fgets(enfermeiro->nome, 50, stdin);
    enfermeiro->nome[strlen(enfermeiro->nome) - 1] = '\0';

    printf("IDADE: ");
    scanf("%d", &enfermeiro->idade);
    fflush(stdin);

    printf("GENERO (M/F): ");
    scanf("%c", &enfermeiro->genero);
    fflush(stdin);

    printf("EMAIL: ");
    fgets(enfermeiro->email, 100, stdin);
    enfermeiro->email[strlen(enfermeiro->email) - 1] = '\0';
    fflush(stdin);

    printf("VENCIMENTO: ");
    scanf("%f", &enfermeiro->vencimento);
    fflush(stdin);

    printf("Associar Clinica(id): ");
    scanf("%d", &enfermeiro->idClinica);
    fflush(stdin);

    enfermeiro->id = n + 1;
    enfermeiro->nConsultas = -1;
}

int inserirEnfermeiro(Enfermeiro *enfermeiros, int *n, Enfermeiro enfermeiro, Clinica *clinicas, int *nclinicas)
{
    if (*n > TAMENFERMEIROS)
    {
        return 0;
    }

    for (int i = 0; i < nclinicas; i++)
    {
        if (clinicas[i].id == enfermeiro.idClinica)
        {
            clinicas[i].numeroEnfermeiros = clinicas[i].numeroEnfermeiros + 1;
            clinicas[i].enfermeiros[clinicas[i].numeroEnfermeiros] = enfermeiro;
        }
    }

    enfermeiros[*n] = enfermeiro;
    (*n)++;

    return 1;
}

void criarAuxiliar(Auxiliar *auxiliar, int n)
{
    printf("\nCriar auxiliar:");
    fflush(stdin);
    printf("\nNOME: ");
    fgets(auxiliar->nome, 50, stdin);
    auxiliar->nome[strlen(auxiliar->nome) - 1] = '\0';

    printf("IDADE: ");
    scanf("%d", &auxiliar->idade);
    fflush(stdin);

    printf("GENERO (M/F): ");
    scanf("%c", &auxiliar->genero);
    fflush(stdin);

    printf("EMAIL: ");
    fgets(auxiliar->email, 100, stdin);
    auxiliar->email[strlen(auxiliar->email) - 1] = '\0';
    fflush(stdin);

    printf("VENCIMENTO: ");
    scanf("%f", &auxiliar->vencimento);
    fflush(stdin);

    printf("Associar Clinica(id): ");
    scanf("%d", &auxiliar->idClinica);
    fflush(stdin);

    auxiliar->id = n + 1;
}

int inserirAuxiliar(Auxiliar *auxiliares, int *n, Auxiliar auxiliar, Clinica *clinicas, int *nclinicas)
{
    if (*n > TAMAUXILIARES)
    {
        return 0;
    }

    for (int i = 0; i < nclinicas; i++)
    {
        if (clinicas[i].id == auxiliar.idClinica)
        {
            clinicas[i].numeroAuxiliares = clinicas[i].numeroAuxiliares + 1;
            clinicas[i].axuliares[clinicas[i].numeroAuxiliares] = auxiliar;
        }
    }

    auxiliares[*n] = auxiliar;
    (*n)++;

    return 1;
}

void criarUtente(Utente *utente, int n)
{
    printf("\nCriar utente:");
    fflush(stdin);

    printf("\nNumero do SNS: ");
    scanf("%d", &utente->sns);
    fflush(stdin);

    printf("\nNOME: ");
    fgets(utente->nome, 50, stdin);
    utente->nome[strlen(utente->nome) - 1] = '\0';

    //La nao pede entao comentei

    /* printf("IDADE: ");
    scanf("%d",&cliente->idade);
    fflush(stdin);

    printf("GENERO (M/F): ");
    scanf("%c",&cliente->genero);
    fflush(stdin);

    printf("EMAIL: ");
    fgets(cliente->email,100,stdin);
    cliente->email[strlen(cliente->email) - 1]='\0';
    fflush(stdin);*/
}

int verificarUtente(Utente *utentes, int *n, int *SNS)
{
    for (int i = 0; i <= n; i++)
    {
        if (utentes[i].sns == SNS)
        {
            return 0;
        }
    }

    return 1;
}
int verificarMedico(Medico *medicos, int *n, int *ID)
{
    for (int i = 0; i <= n; i++)
    {
        if (medicos[i].id == ID)
        {
            return i;
        }
    }

    return -2;
}
int verificarEnfermeiro(Enfermeiro *enfermeiros, int *n, int *ID)
{
    for (int i = 0; i <= n; i++)
    {
        if (enfermeiros[i].id == ID)
        {
            return i;
        }
    }

    return -2;
}

void inserirConsultaMedico(Clinica *clinicas, int *n, int *ID, Utente *utentes, int *nUtentes, int *SNS)
{
    int posicao;

    for (int i = 0; i <= nUtentes; i++)
    {
        if (utentes[i].sns == SNS)
        {
            posicao = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= clinicas[i].numeroMedicos; j++)
        {
            if (clinicas[i].medicos[j].id == ID)
            {
                clinicas[i].medicos[j].nConsultas += 1;
                int position = clinicas[i].medicos[j].nConsultas;
                clinicas[i].medicos[j].agenda[position] = utentes[posicao];
            }
        }
    }
}

void inserirConsultaEnfermeiro(Clinica *clinicas, int *n, int *ID, Utente *utentes, int *nUtentes, int *SNS)
{
    int posicao;

    for (int i = 0; i <= nUtentes; i++)
    {
        if (utentes[i].sns == SNS)
        {
            posicao = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= clinicas[i].numeroEnfermeiros; j++)
        {
            if (clinicas[i].enfermeiros[j].id == ID)
            {
                clinicas[i].enfermeiros[j].nConsultas += 1;
                int position = clinicas[i].enfermeiros[j].nConsultas;
                clinicas[i].enfermeiros[j].agenda[position] = utentes[posicao];
            }
        }
    }
}

int inserirUtente(Utente *utentes, int *n, Utente utente)
{
    if (*n > TAMUTENTES)
    {
        return 0;
    }

    utentes[*n] = utente;
    (*n)++;

    return 1;
}

void listarClinicas(Clinica *clinicas, int *n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n%d", clinicas[i].id);
        printf("\n%s", clinicas[i].nome);
        printf("\n%s", clinicas[i].localizacao);
        printf("\n%s", clinicas[i].contacto);
        //printf("\n%s",clinicas[i].medicos[0].nome);
        //printf("\n%s",clinicas[i].medicos[1].nome);

        for (int j = 0; j <= clinicas[i].numeroMedicos; j++)
        {
            //so mostra o nome para nao ficar enorme na consola depois pomos o resto
            printf("\n%s", clinicas[i].medicos[j].nome);
            for (int h = 0; h <= clinicas[i].medicos[j].nConsultas; h++)
            {
                printf("\n%s", clinicas[i].medicos[j].agenda[h].nome);
                printf("\n%d", clinicas[i].medicos[j].agenda[h].sns);
            }
        }
        for (int j = 0; j <= clinicas[i].numeroEnfermeiros; j++)
        {
            //so mostra o nome para nao ficar enorme na consola depois pomos o resto
            printf("\n%s", clinicas[i].enfermeiros[j].nome);
            for (int h = 0; h <= clinicas[i].enfermeiros[j].nConsultas; h++)
            {
                printf("\n%s", clinicas[i].enfermeiros[j].agenda[h].nome);
                printf("\n%d", clinicas[i].enfermeiros[j].agenda[h].sns);
            }
        }

        for (int j = 0; j <= clinicas[i].numeroAuxiliares; j++)
        {
            //so mostra o nome para nao ficar enorme na consola depois pomos o resto
            printf("\n%s", clinicas[i].axuliares[j].nome);
        }
    }
}

void listarMedico(Medico *medicos, int *n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n%d", medicos[i].id);
        printf("\n%s", medicos[i].nome);
        printf("\n%d", medicos[i].idade);
        printf("\n%c", medicos[i].genero);
        printf("\n%s", medicos[i].email);
        printf("\n%.2f", medicos[i].vencimento);
        printf("\n%d", medicos[i].idClinica);
    }
}

void listarEnfermeiros(Enfermeiro *enfermeiros, int *n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n%d", enfermeiros[i].id);
        printf("\n%s", enfermeiros[i].nome);
        printf("\n%d", enfermeiros[i].idade);
        printf("\n%c", enfermeiros[i].genero);
        printf("\n%s", enfermeiros[i].email);
        printf("\n%.2f", enfermeiros[i].vencimento);
    }
}

void listarAuxiliares(Auxiliar *auxilares, int *n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n%d", auxilares[i].id);
        printf("\n%s", auxilares[i].nome);
        printf("\n%d", auxilares[i].idade);
        printf("\n%c", auxilares[i].genero);
        printf("\n%s", auxilares[i].email);
        printf("\n%.2f", auxilares[i].vencimento);
    }
}

void listarUtentes(Utente *utentes, int *n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n%d", utentes[i].sns);
        printf("\n%s", utentes[i].nome);
        /*printf("\n%d",utentes[i].idade);
        printf("\n%c",utentes[i].genero);
        printf("\n%s",utentes[i].email);*/
    }
}

void MediaIdadesMedicos(Clinica *clinicas, int n)
{
    int resultado = 0;
    float media = 0;

    for (int i = 0; i < n; i++)
    {
        printf("\nNomeClinica: %s", clinicas[i].nome);

        for (int j = 0; j <= clinicas[i].numeroMedicos; j++)
        {
            resultado = resultado + clinicas[i].medicos[j].idade;
            media = (float)resultado / n;
        }
    }

    printf("\nMedia dos Medicos: %.2f", media);
    printf("\nTem %d medicos", n);
}

void MediaIdadesEnfermeiros(Clinica *clinicas, int n)
{
    int resultado = 0;
    float media = 0;
    int contador = 0;

    for (int i = 0; i < n; i++)
    {
        printf("\nNomeClinica: %s", clinicas[i].nome);

        for (int j = 0; j <= clinicas[i].numeroEnfermeiros; j++)
        {
            resultado = resultado + clinicas[i].enfermeiros[j].idade;

            media = (float)resultado / n;
        }
    }

    printf("\nMedia dos Enfermeiros: %.2f", media);
    printf("\nTem %d enfermeiros", n);
}

void MediaIdadesAuxiliares(Clinica *clinicas, int n)
{
    int resultado = 0;
    float media = 0;
    int contador = 0;

    for (int i = 0; i < n; i++)
    {
        printf("\nNomeClinica: %s", clinicas[i].nome);

        for (int j = 0; j <= clinicas[i].numeroAuxiliares; j++)
        {
            resultado = resultado + clinicas[i].axuliares[j].idade;
            media = (float)resultado / n;
        }
    }

    printf("\nMedia dos Auxiliares: %.2f", media);
    printf("\nTem %d auxiliares", contador);
}

void SomaVencimentosMedicosPorClinica(Clinica *clinicas, int n)
{
    int resultado = 0;

    for (int i = 0; i < n; i++)
    {
        printf("\nMedicos:");

        printf("\n     ID      |      NOME        |      IDADE       |      GENERO      |          EMAIL           |       VENCIMENTO     \n");

        for (int j = 0; j <= clinicas[i].numeroMedicos; j++)
        {

            printf("       %d", clinicas[i].medicos[j].id);
            printf("           %s", clinicas[i].medicos[j].nome);
            printf("               %d", clinicas[i].medicos[j].idade);
            printf("                  %c", clinicas[i].medicos[j].genero);
            printf("                  %s", clinicas[i].medicos[j].email);
            printf("              %f", clinicas[i].medicos[j].vencimento);

            printf("\n");

            resultado = resultado + clinicas[i].medicos[j].vencimento;
        }
    }

    printf("\n\nTotal de Vencimentos: %d", resultado);
}

void SomaVencimentosEnfermeirosPorClinica(Clinica *clinicas, int n)
{
    int resultado = 0;

    for (int i = 0; i < n; i++)
    {
        printf("\nEnfermeiros:");

        printf("\n     ID      |      NOME        |      IDADE       |      GENERO      |          EMAIL           |       VENCIMENTO     \n");

        for (int j = 0; j <= clinicas[i].numeroEnfermeiros; j++)
        {

            printf("       %d", clinicas[i].enfermeiros[j].id);
            printf("           %s", clinicas[i].enfermeiros[j].nome);
            printf("               %d", clinicas[i].enfermeiros[j].idade);
            printf("                  %c", clinicas[i].enfermeiros[j].genero);
            printf("                  %s", clinicas[i].enfermeiros[j].email);
            printf("              %f", clinicas[i].enfermeiros[j].vencimento);

            printf("\n");

            resultado = resultado + clinicas[i].enfermeiros[j].vencimento;
        }
    }

    printf("\n\nTotal de Vencimentos: %d", resultado);
}

void SomaVencimentosAuxiliaresPorClinica(Clinica *clinicas, int n)
{
    int resultado = 0;

    for (int i = 0; i < n; i++)
    {
        printf("\nAuxiliares:");

        printf("\n     ID      |      NOME        |      IDADE       |      GENERO      |          EMAIL           |       VENCIMENTO     \n");

        for (int j = 0; j <= clinicas[i].numeroAuxiliares; j++)
        {

            printf("       %d", clinicas[i].axuliares[j].id);
            printf("           %s", clinicas[i].axuliares[j].nome);
            printf("               %d", clinicas[i].axuliares[j].idade);
            printf("                  %c", clinicas[i].axuliares[j].genero);
            printf("                  %s", clinicas[i].axuliares[j].email);
            printf("              %f", clinicas[i].axuliares[j].vencimento);

            printf("\n");

            resultado = resultado + clinicas[i].axuliares[j].vencimento;
        }
    }

    printf("\n\nTotal de Vencimentos: %d", resultado);
}

void SomaVencimentosGeneroMedico(Medico *medicos, int n)
{
    int somaFem = 0;
    int somaMasc = 0;

    for (int i = 0; i < n; i++)
    {
        if (medicos[i].genero == 'f')
        {
            somaFem += medicos[i].vencimento;
        }
        else
        {
            somaMasc += medicos[i].vencimento;
        }
    }

    printf("\nMedicos:");
    printf("\nTotal dos Vencimentos do sexo Masculino: %d", somaMasc);
    printf("\nTotal dos Vencimentos do sexo Feminino: %d", somaFem);
}

void SomaVencimentosGeneroEnfermeiro(Enfermeiro *enfermeiros, int n)
{
    int somaFem = 0;
    int somaMasc = 0;

    for (int i = 0; i < n; i++)
    {
        if (enfermeiros[i].genero == 'f')
        {
            somaFem += enfermeiros[i].vencimento;
        }
        else
        {
            somaMasc += enfermeiros[i].vencimento;
        }
    }

    printf("\nEnfermeiros:");
    printf("\nTotal dos Vencimentos do sexo Masculino: %d", somaMasc);
    printf("\nTotal dos Vencimentos do sexo Feminino: %d", somaFem);
}

void SomaVencimentosGeneroAuxiliar(Auxiliar *auxiliares, int n)
{
    int somaFem = 0;
    int somaMasc = 0;

    for (int i = 0; i < n; i++)
    {
        if (auxiliares[i].genero == 'f')
        {
            somaFem += auxiliares[i].vencimento;
        }
        else
        {
            somaMasc += auxiliares[i].vencimento;
        }
    }

    printf("\nAuxiliares:");
    printf("\nTotal dos Vencimentos do sexo Masculino: %d", somaMasc);
    printf("\nTotal dos Vencimentos do sexo Feminino: %d", somaFem);
}

void CompromissosAgenda(Clinica *clinicas, int *n, int *ID)
{
    int posicao;
    int compromissos = 0;

    for (int i = 0; i <= n; i++)
    {
        if (clinicas[i].id == ID)
        {
            posicao = i;
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j <= clinicas[i].numeroEnfermeiros; j++)
        {
            compromissos = clinicas[i].enfermeiros[j].nConsultas;
            compromissos++;
        }
    }
    printf("Compromissos: %d", compromissos);
}

void listarAgendaMedico(Medico *medicos, int *n, int *ID, Utente *utentes, int *nUtentes)
{
    for (int i = 0; i < n; i++)
    {

            printf("%d",medicos[i].agenda->sns);
            printf("%d",medicos[i].agenda->nome);


    }
}

void listarAgendaEnfermeiro(Enfermeiro *enfermeiros, int *n, int *ID, Utente *utentes, int *nUtentes)
{
    for (int i = 0; i < n; i++)
    {

            printf("%d",enfermeiros[i].agenda->sns);
            printf("%d",enfermeiros[i].agenda->nome);


    }
}

