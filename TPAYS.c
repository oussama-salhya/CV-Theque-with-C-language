#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#define BIG_MAX 100
#define MAX 25
#include "TPAYS.h"
#include "TPERMIS.h"
#include "TETATCIVILE.h"
#include "TVILLES.h"
#include "TLANGUE.h"
#include "TCANDIDATS.h"
#include "TFORMATIONS.h"
#include "TTYPECONTRAT.h"
#include "TCV.h"
#include "TCOMPETENCES.h"
#include "TEXPERIENCES.h"

struct TPAYS
{
    int IdPays;
	char NomPays[50];
};struct TPAYS P ;

void test_file_opening(FILE * F)
{
    if(!F)
    {
        printf("Could'nt open file !\n");
        exit(-1);
    }
}
void AjouterPays()
{

	FILE *Fp;
	Fp=fopen("TPAYS.txt","a");
	test_file_opening(Fp);
	printf("\tSaisir le Nom du Pays ");
	scanf("%s",&P.NomPays);
	getchar();
	if(RecherchePaysParNom(P.NomPays)==1)
    {
        printf("Ce Pays deja existe\n");
        return;
    }

	P.IdPays=getIDPays("TPAYS.txt")+1;
	fflush(stdin);

	fprintf(Fp,"%d ; %s  \n",P.IdPays,P.NomPays);
	printf("\n\nle Pays %u %s est ajoute au fichier TPAYS.txt avec success \n",P.IdPays,P.NomPays);
	fclose(Fp);
}

void RecherchePays()
{
	int NumR,j=0;
	printf("\n\tEntrez le numero du Pays a rechercher :");
	scanf("%d",&NumR);
	FILE *Fp;
	Fp=fopen("TPAYS.txt","r");
	do
	{
	fscanf(Fp,"%d ;%s \n",&P.IdPays,&P.NomPays);
	if(NumR==P.IdPays)
	{
	        printf("\n\t===============INFORMATION SUR LE PAYS  %d  ================\n\t ",P.IdPays);
	        printf("\n\tLe Pays \t\t\t:%s",P.NomPays);
	        printf("\n\t-----------------------------------------------------------------");
	        j++;
	}

	}while(!feof(Fp));
	fclose(Fp);
	if(j==0){
	    printf("\n\tDesole! Ce Pays n'existe pas\n");
	}
}

void AfficherPaysC(int NumR)
{
	FILE *Fp;
	Fp=fopen("TPAYS.txt","r");
	do
	{
	fscanf(Fp,"%d ;%s \n",&P.IdPays,&P.NomPays);
	if(NumR==P.IdPays)
	{
	        printf("\n\tLa Nationalite \t\t\t:%s",P.NomPays);
	}
	}while(!feof(Fp));
	fclose(Fp);
}

void SupprimerPays()
{
	char rep;
	int NumRech;
	printf("\n\tEntrez Le numero du Pays a supprimer :");
	scanf("%d",&NumRech);
	getchar();
	fflush(stdin);

	if(rechPays(NumRech)==1)
	{
	    printf("\n\tVoulez-vous vraiment Supprimer o/n?");
	    scanf("%c",&rep);
	    fflush(stdin);
	    if(rep=='o'||rep=='O')
	    {
	        FILE *Fpt,*Fp;
	        Fp=fopen("TPAYS.txt","r");
	        test_file_opening(Fp);
	        Fpt=fopen("PAYS.txt","a");
	        test_file_opening(Fpt);
	        do
	        {
	         fscanf(Fp,"%d ;%s \n",&P.IdPays,&P.NomPays);
	         if(NumRech!=P.IdPays)
	         {
	         fprintf(Fpt,"%d ;%s \n",P.IdPays,P.NomPays);
	         }
	        }while(!feof(Fp));
	        fclose(Fpt);
	        fclose(Fp);
	        remove("TPAYS.txt");
	        rename("PAYS.txt","TPAYS.txt");
	        printf("\n\tLa suppression Effectuee avec succees");

	    }
	}
	else
	{
	    printf("\n\tCe numero du Pays n'existe pas");
	}
}

void ModifierPays(){

	FILE *Fp,*Fpt;
	int num,i;
	char rep='n';
	printf("\n\tEntrez Le numero du Pays a Modifier: ");
	scanf("%d",&num);
	fflush(stdin);

	if(rechPays(num)==1)
	{
	printf("\n\tVoulez vous vraiment Modifier o/n?");
	scanf("%c",&rep);
	fflush(stdin);
	if(rep=='o'||rep=='O')
	{
	    Fp=fopen("TPAYS.txt","r");
	    test_file_opening(Fp);
	    Fpt=fopen("PAYS.txt","a");
	    test_file_opening(Fpt);

	 do
	 {
	fscanf(Fp,"%d ;%s \n",&P.IdPays,&P.NomPays);
	if(num==P.IdPays)
	{
	P.IdPays=num;

	printf("\n\tEntrez Le Nouveau Pays :");
	gets(P.NomPays);
	if(RecherchePaysParNom(P.NomPays)==1)
    {
        printf("Ce Pays deja existe\n");
        return;
    }
	}
	fprintf(Fpt,"%d ;%s \n",P.IdPays,P.NomPays);
	}while(!feof(Fp));
    fclose(Fpt);
    fclose(Fp);
    remove("TPAYS.txt");
    rename("PAYS.txt","TPAYS.txt");
	printf("\n\tLa Modification a Reussi");
	}
	else
	{
	printf("\n\tLa Modification a ete annule\n");
	}
	}
	else
	{
	printf("\n\tCe Numero du Pays N'existe pas\n");
	}
}

int RecherchePaysParNom(char * NomPays)
{
	unsigned int 	id;
    char  NomPays_courant[MAX];
    char  line[BIG_MAX];
    FILE * F=fopen("TPAYS.txt","r");

    test_file_opening(F);

    while(!feof(F))
    {
        fscanf(F,"%d ;%s \n",&id,NomPays_courant);
        if(!strcmp(NomPays,NomPays_courant))
        {
            return 1;
        }
    }

    fclose(F);
    return 0;
}

int rechPays(int Numrech)
{
	FILE *Fp;
	Fp=fopen("TPAYS.txt","r");
	test_file_opening(Fp);
	do
		{
		fscanf(Fp,"%d ;%s \n",&P.IdPays,&P.NomPays);
		fflush(stdin);
		if(P.IdPays==Numrech)
			{
			fclose(Fp);
			return 1;
			}
		}while(!feof(Fp));
	fclose(Fp);
	return -1;
}

void AfficherPays()
{
FILE *Fp;
Fp=fopen("TPAYS.txt","r");
printf("\n\tLa liste des Pays :\n");
printf("\n\tNumero\tLe Pays\n");
printf("\n\t--------------------------------------\n");
do
{
fscanf(Fp,"%d ;%s \n",&P.IdPays,&P.NomPays);
fflush(stdin);
printf("\n\t%d ;%s \n",P.IdPays,P.NomPays);
}while(!feof(Fp));
fclose(Fp);
}

int count_separator(char car,int i)
{
    if (car == ';')
        i++;
    return i;
}

int is_space(char car)
{
    if (car == ' ')
        return 1;
    return 0;
}

int remplir_nom(char * nom, char car, int index)
{
    if(((index != 0) && is_space(car)) || isalnum(car))
        nom[index++] = car;
    return index;
}

void lire_nom(const char * line,char * nom)
{
    char car;
    int separator_counter = 0;
    int index=0;
    int i=0;

    while((car = line[i++]) != '\0')
    {
        separator_counter = count_separator(car,separator_counter);
        if (separator_counter == 1)
        {
            index = remplir_nom(nom,car,index);
        }
    }

    nom[--index] = '\0';
}

unsigned int getIDPays(char *File)
{
	unsigned int id;
	int j=(-1);
	char NomPays_courant[MAX];
	char N[100];
    FILE *F;
    F=fopen("TPAYS.txt","r");
    test_file_opening(F);
    while(!feof(F))
	{
    fgets(N,100,F);
    j++;
	}
    if(j==0)
    {
    	fclose(F);
		return 0;
	}
	else
	{
		fclose(F);
		F=fopen(File,"r");
		test_file_opening(F);
		while(!feof(F))
		{
			fscanf(F,"%u ;%s \n",&id,NomPays_courant);
		}
	fclose(F);
	return id;
	}
}

void MenuPays()
{
int Choix;char rep;
do
	{
	    system("cls");
	    printf("\n\t              ***********************                  ");
	    printf("\n\t***************    MENU DES PAYS    ***************");
	    printf("\n\t              ***********************                 ");
	    printf("\n\t                                               \n");
	    printf("\t*  (1) Ajouter un Pays                          *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (2) Rechercher Une Pays                      *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (3) Supprimer Un Pays                        *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (4) Modifier Une Pays                        *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (5) Afficher tous Les Pays                   *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (6) Quiter                                   *\n");
	    printf("\t*-----------------------------------------------*\n");

	    do
		    {
		     printf("\n\t>>> Etrez votre choix...");
		     scanf("%d",&Choix);
		     fflush(stdin);
		    }while(Choix<1||Choix>6);
	    switch(Choix)
			{
		    case 1:AjouterPays();
		        break;
		    case 2:RecherchePays();
		        break;
		    case 3:SupprimerPays();
		        break;
		    case 4:ModifierPays();
		        break;
		    case 5:AfficherPays();
		        break;
		    case 6:break;
		    }
	    printf("\n\t>>> Voulez-vous continuez O/N?...");
	    scanf("%s",&rep);
	    fflush(stdin);
	}while(rep=='o'||rep=='O');
}
